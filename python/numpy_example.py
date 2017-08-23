#! /usr/bin/python2

# Python program to demonstrate basic array characteristics
import numpy as np
 
# creating array object
arr = np.array([[ 1, 2, 3],
                [ 4, 2, 5]])
 
# printing type of arr object
print "Array is of type: ", type(arr)
 
# printing array dimensions (axes)
print "No. of dimensions: ", arr.ndim
 
# printing shape of array
print "Shape of array: ", arr.shape
 
# printing size (total number of elements) of array
print "Size of array: ", arr.size
 
# printing type of elements in array
print "Array stores elements of type: ", arr.dtype
