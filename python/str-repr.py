#! /usr/bin/python
# -*- encoding: utf-8 -*-
#str() is used for creating output for end user while repr() is mainly
#used for debugging and development. repr’s goal is to be unambiguous 
#and str’s is to be readable.

#The print statement and str() built-in function uses __str__ to display
#the string representation of the object while the repr() built-in function 
#uses __repr__ to display the object. 

#repr() compute the “official” string representation of an object
#(a representation that has all information about the abject) and str() 
#is used to compute the “informal” string representation of an object
#(a representation that is useful for printing the object).
s = 'Hello, Geeks'
print str(s)
print str(2.0/11.0)

print repr(s)
print repr(2.0/11.0)

import datetime
today = datetime.datetime.now()
 
# Prints readable format for date-time object
print str(today)
  
# prints the official format of date-time object
print repr(today) 

class Complex:
    def __init__(self, real, img):
        self.real = real
        self.img = img

    def __repr__(self):
        return "Rational(%s %s)" % (self.real, self.img)

    def __str__(self):
        return "%s + i%s" % (self.real, self.img)

t = Complex(10, 20)

print str(t)
print repr(t)
