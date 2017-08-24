#! /usr/bin/python3
# -*- encoding: utf-8 -*-
import textwrap
 
value = """This function wraps the input paragraph such that each line
in the paragraph is at most width characters long. The wrap method
returns a list of output lines. The returned list
is empty if the wrapped
output has no content."""

#This function wraps the input paragraph such that each line in the paragraph is at most width characters long. 
#The wrap method returns a list of output lines. The returned list is empty if the wrapped output has no content. 
#Default width is taken as 70. Wrap this text.
wrapper = textwrap.TextWrapper(width=50)
 
word_list = wrapper.wrap(text=value)
 
# Print each line.
for element in word_list:
    print(element)

#The fill() convenience function works similar to textwrap.wrap except it returns the data joined into a single,
#newline-separated string. This function wraps the input single paragraph in text, and returns a single string
#containing the wrapped paragraph. 
value = """This function returns the answer as STRING and not LIST."""
string = wrapper.fill(text=value)
print (string)

#This function is used to remove any common leading whitespace from every line in the input text.
#This allows to use docstrings or embedded multi-line strings line up with the left edge of the
#display, while removing the formatting of the code itself. 
s = '''\
    hello
      world
    '''
print(repr(s)) # prints '    hello\n      world\n    '
 
text = textwrap.dedent(s)
print(repr(text)) # prints 'hello\n  world\n'

#This function truncates the input string so that the length of the string becomes equal to the given width. 
#At first, all the whitespaces are collapsed in the string by removing the whitespaces with a single space.
#If the modified string fits in the given string, then it is returned otherwise, the characters from the end 
#are dropped so that the remaining words plus the placeholder fit within width.
 
sample_text = """This function wraps the input paragraph such that each line
n the paragraph is at most width characters long. The wrap method
returns a list of output lines. The returned list
is empty if the wrapped
output has no content."""
 
wrapper = textwrap.TextWrapper(width=50)
 
dedented_text = textwrap.dedent(text=sample_text)
original = wrapper.fill(text=dedented_text)
 
print('Original:\n')
print(original)
 
shortened = textwrap.shorten(text=original, width=100)
shortened_wrapped = wrapper.fill(text=shortened)
 
print('\nShortened:\n')
print(shortened_wrapped)

#This function is used to add the given prefix to the beginning of the selected lines of the text. 
#The predicate argument can be used to control which lines are indented. 
s = 'hello\n\n \nworld'
s1 = textwrap.indent(text=s, prefix=' ')
 
print (s1)
print ("\n")

s2 = textwrap.indent(text=s, prefix='+ ', predicate=lambda line: True)
print(s2)
