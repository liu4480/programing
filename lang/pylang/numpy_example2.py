import numpy as np
 
# creating array from list with type float
a = np.array([[1, 2, 4], [5, 8, 7]], dtype = 'float')
print "Array created using passed list:\n", a
 
# creating array from tuple
b = np.array((1 , 3, 2))
print "\nArray created using passed tuple:\n", b
 
# creating a 3X4 array with all zeros
c = np.zeros((3, 4))
print "\nAn array initialized with all zeros:\n", c
 
# create a constant value array of complex type
d = np.full((3, 3), 6, dtype = 'complex')
print "\nAn array initialized with all 6s. Array type is complex:\n", d
 
# create an array with random values
e = np.random.random((2,2))
print "\nA random array:\n", e
 
# create a sequence of integers from 0 to 30 with steps of 5
f = np.arange(0, 30, 5)
print "\nA sequential array with steps of 5:\n", f
 
# create a sequence of 10 values in range 0 to 5
g = np.linspace(0, 5, 10)
print "\nA sequential array with 10 values between 0 and 5:\n", g
 
# reshaping 3X4 array to 2X2X3 array
arr = np.array([[1, 2, 3, 4],
                [5, 2, 4, 2],
                [1, 2, 0, 1]])
newarr = arr.reshape(2, 2, 3)
print "\nOriginal array:\n", arr
print "Reshaped array:\n", newarr
 
# flatten array
arr = np.array([[1, 2, 3], [4, 5, 6]])
flarr = arr.flatten()
print "\nOriginal array:\n", arr
print "Fattened array:\n", flarr

arr = np.array([[-1, 2, 0, 4],
                [4, -0.5, 6, 0],
                [2.6, 0, 7, 8],
                [3, -7, 4, 2.0]])
temp = arr[:2, ::2]
print "Array with first 2 rows and alternate columns(0 and 2):\n", temp
 
# integer array indexing example
temp = arr[[0, 1, 2, 3], [3, 2, 1, 0]]
print "\nElements at indices (0, 3), (1, 2), (2, 1), (3, 0):\n", temp
 
# boolean array indexing example
cond = arr > 0    # cond is a boolean array
temp = arr[cond]
print "\nElements greater than 0:\n", temp

a = np.array([1,2,5,3])
print "Adding 1 to every element:", a+1
print "substrcting 3 from every element", a-3
# multiply each element by 10
print "Multiplying each element by 10:", a*10
 
# square each element
print "Squaring each element:", a**2
  
# modify existing array
a *= 2
print "Doubled each element of original array:", a

a = np.array([[1,2,3], [3,4,5], [9,6,0]])
print "\nOriginal array:\n", a
print "Transpose of array:\n", a.T

arr = np.array([[1,5,6],
                [4,7,2],
                [3,1,9]])

print "Largest element : ", arr.max()
print "Row-wise maximum element : ", arr.max(axis = 1)
print "column-wise minimum element : ", arr.min(axis = 0)
print "sum of all array elements : ", arr.sum()
print "Cumulative sum along each row:\n", arr.cumsum(axis=1)

a = np.array([[1,2],
              [3,4]])
b = np.array([[4,3],
              [2,1]])

print "Array sum:\n", a+b
print "Array multiplication:\n", a*b
print "Maxtrix multiplication:\n", a.dot(b)

del a
del b
a = np.array([0, np.pi/2, np.pi])
print "Sine values of array elements: ", np.sin(a)
del a
a = np.array([0,1,2,3])
print "Exponent of array elements: ", np.exp(a)

print "Square root of array elements: ", np.sqrt(a)
del a

a = np.array([[1,4,2],
              [3,4,6],
              [0,-1,5]])
print "Array elements in sorted order:\n", np.sort(a, axis = None)
print "Row-sise sorted array:\n", np.sort(a, axis = 1)
print "Column wise sort by applying merge-sort:\n", np.sort(a, axis = 0, kind='mergesort')

# example to show sorting of structured array
## set alias names for dtypes
dtypes = [('name', 'S10'), ('grad_year', int), ('cgpa', float)]
## values to be put in array
values = [('Hrithik', 2009, 8.5), ('Ajay', 2008, 8.7), ('Pankaj', 2008, 7.9), 
('Aakash', 2009, 9.0)]
## creating array
arr = np.array(values, dtype = dtypes)
print "\nArray sorted by names:\n", np.sort(arr, order = 'name')
print "Array sorted by grauation year and then cgpa:\n", np.sort(arr, order 
= ['grad_year', 'cgpa'])
