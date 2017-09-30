#! /usr/bin/python
# -*- coding: utf-8 -*-

import unicodedata

print(unicodedata.lookup('LEFT CURLY BRACKET'))
print(unicodedata.lookup("RIGHT CURLY BRACKET"))
print(unicodedata.lookup("ASTERISK"))

print unicodedata.name(u'/')
print unicodedata.name(u'|')
print unicodedata.name(u':')
#This function returns the digit value assigned to the given character as integer. 
#If no value is defined, default is returned by the function otherwise ValueError
#is raised if value is not given.
print unicodedata.decimal(u'9')
try:
    print unicodedata.decimal(u'a')
except ValueError:
    print 'ValueError is raised'

print unicodedata.decimal(u'a', 10)

#This function returns the digit value assigned to the given character as integer. 
#If no value is defined, default is returned by the function otherwise ValueError
#is raised if value is not given.
print unicodedata.digit(u'9')
try:
    print unicodedata.digit(u'143')
except TypeError:
    print "TypeError is raised"

print unicodedata.digit(u'a', 100)

#This function returns the digit value assigned to the given character as integer. 
#If no value is defined, default is returned by the function otherwise ValueError
#is raised if value is not given.
print unicodedata.numeric(u'9')
print unicodedata.numeric(u'a', 10)

print unicodedata.category(u'A')
print unicodedata.category(u'b')

#This function returns the bidirectional class assigned to the given character as string. 
#For example, it returns ‘A’ for arabic and ‘N’ for number. 
#An empty string is returned by this function if no such value is defined.
print unicodedata.bidirectional(u'\u0660')
print unicodedata.bidirectional(u'\u0666')

#This function returns the normal form form for the Unicode string unistr. 
#Valid values for form are ‘NFC’, ‘NFKC’, ‘NFD’, and ‘NFKD’.
from unicodedata import normalize
  
print '%r' % normalize('NFD', u'\u00C7')
print '%r' % normalize('NFC', u'C\u0327')
print '%r' % normalize('NFKD', u'\u2460')
print '%r' % normalize('NFKC', u'\u2460')
print '%r' % normalize('NFC', u'C\u2460')
