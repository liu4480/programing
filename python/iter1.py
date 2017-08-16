#! /usr/bin/python3
import itertools
import operator

li1 = [1, 4, 5, 7]
li2 = [1, 6, 5, 9]
li3 = [8, 10, 5 ,4]
li4 = [li1, li2, li3]

# using accumulate()
# prints the successive summation of elements
print ("The sum after each iteration is : ",end="")
print (list(itertools.accumulate(li1)))
 
# using accumulate()
# prints the successive multiplication of elements
print ("The product after each iteration is : ",end="")
print (list(itertools.accumulate(li1,operator.mul)))
  
# using chain() to print all elements of lists
print ("All values in mentioned chain are : ",end="")
print (list(itertools.chain(li1,li2,li3)))

# using chain.from_iterable() to print all elements of lists
print ("All values in mentioned chain are : ",end="")
print (list(itertools.chain.from_iterable(li4)))

# using compress() selectively print data values
print ("The compressed values in string are : ",end="")
print (list(itertools.compress('GEEKSFORGEEKS',[1,0,0,0,0,1,0,0,1,0,0,0,0])))

li = [2, 4, 5, 7, 8]

#using dropwhile() to start displaying after contidion is false
print("The values after condition returns falsee : ", end="")
print(list(itertools.dropwhile(lambda x: x%2==0, li)))

#using filterfalse() to print false values
print("The values that return false to function are : ", end="")
print(list(itertools.filterfalse(lambda x : x%2 == 0, li)))
