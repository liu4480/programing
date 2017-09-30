# Python program to illustrate swapping
# of a variable in one line 
 
# slower
x = 2
y = 5
temp = x
x = y
y = temp
print x,y
 
x,y = 3,5
# faster
x, y = y, x
print x,y
