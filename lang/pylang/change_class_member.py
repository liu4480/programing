#! /usr/bin/python2

# Class for Computer Science Student
class CSStudent:
    stream = 'cse'     # Class Variable 
    def __init__(self, name, roll):
        self.name = name 
        self.roll = roll
 
# Driver program to test the functionality
# Creating objects of CSStudent class
a = CSStudent("Geek", 1)
b = CSStudent("Nerd", 2)
 
print "Initially"
print "a.stream =", a.stream
print "b.stream =", b.stream 
 
# This thing doesn't change class(static) variable
# Instead creates instance variable for the object
# 'a' that shadows class member.
a.stream = "ece"
 
print "\nAfter changing a.stream"
print "a.stream =", a.stream
print "b.stream =", b.stream

CSStudent.stream = "mec"
print "\nAfter changing CSStudent.stream"
print "a.stream =", a.stream
print "b.stream =", b.stream
