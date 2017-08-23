#! /usr/bin/python

import numpy as np

a = np.array([[1,2],
              [3,4]])
b = np.array([[5,6],
              [7,8]])
print "Vertical stacking:\n", np.vstack((a,b))

print "\nHorizontal stacking:\n", np.hstack((a,b))

c = [5,6]
print "\nColumn stacking:\n", np.column_stack((a,c))

print "\nConcatenating to 2nd axis:\n", np.concatenate((a,b), 1) 

del a,b,c

a = np.array([[1, 3, 5, 7, 9, 11],
              [2, 4, 6, 8, 10,12]])
# horizontal splitting
print "Splitting along horizontal axis into 2 parts:\n", np.hsplit(a, 2)
 
# vertical splitting
print "\nSplitting along vertical axis into 2 parts:\n", np.vsplit(a, 2)
del a

a = np.array([1.0, 2.0, 3.0])
 
# Example 1
b = 2.0
print(a * b)
  
# Example 2
c = [2.0, 2.0, 2.0]
print(a * c)

del a, b, c

a = np.array([0.0, 10.0, 20.0, 30.0])
b = np.array([0.0, 1.0, 2.0])

print(a[:, np.newaxis] + b)

today = np.datetime64('2017-02-12')
print "date is:", today
print "Year is:", np.datetime64(today, 'Y')

dates = np.arange('2017-02', '2017-03', dtype='datetime64[D]')
print 'Dates of February, 2017:\n', dates
print 'today is February:', today in dates

# arithmetic operation on dates
dur = np.datetime64('2017-05-22') - np.datetime64('2016-05-22')
print "\nNo. of days:", dur
print "No. of weeks:", np.timedelta64(dur, 'W')
 
# sorting dates
a = np.array(['2017-02-12', '2016-10-13', '2019-05-22'], dtype='datetime64')
print "\nDates in sorted order:", np.sort(a)

A = np.array([[6, 1, 1],
              [4, -2, 5],
              [2, 8, 7]])
 
print "Rank of A:", np.linalg.matrix_rank(A)
 
print "\nTrace of A:", np.trace(A)
 
print "\nDeterminant of A:", np.linalg.det(A)
 
print "\nInverse of A:\n", np.linalg.inv(A)
 
print "\nMatrix A raised to power 3:\n", np.linalg.matrix_power(A, 3)

# coefficients
a = np.array([[1, 2], [3, 4]])
# constants
b = np.array([8, 18])
 
print("Solution of linear equations:", np.linalg.solve(a, b))
