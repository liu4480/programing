#! /usr/bin/python3

from string import Template
 
# List Student stores the name and marks of three students
Student = [('Ram',90), ('Ankit',78), ('Bob',92)]
 
# We are creating a basic structure to print the name and
# marks of the students.
t = Template('Hi $name, you have got $marks marks')
 
for i in Student:
     print (t.substitute(name = i[0], marks = i[1]))

str1 = ''
str2 = 'geeks'
 
# repr is used to print the string along with the quotes
print(repr(str1 and str2)) # Returns str1 
print(repr(str2 and str1)) # Returns str1
print(repr(str1 or str2)) # Returns str2 
print(repr(str2 or str1)) # Returns str2
 
str1 = 'for'
 
print(repr(str1 and str2)) # Returns str2 
print(repr(str2 and  str1)) # Returns str1
print(repr(str1 or str2)) # Returns str1 
print(repr(str2 or str1)) # Returns str2
