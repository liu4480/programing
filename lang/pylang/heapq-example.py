#! /usr/bin/python3

import heapq

# initializing list
li = [5, 7, 9, 1, 3]
 
# using heapify to convert list into heap
heapq.heapify(li)
 
# printing created heap
print ("\nThe created heap is : ",end="")
print (list(li))
 
# using heappush() to push elements into heap
# pushes 4
heapq.heappush(li,4)
 
# printing modified heap
print ("\nThe modified heap after push is : ",end="")
print (list(li))
 
# using heappop() to pop smallest element
print ("\nThe popped and smallest element is : ",end="")
print (heapq.heappop(li))

print ("\nThe modified heap after pop is : ",end="")
print (list(li))

del li
# initializing list 1
li1 = [5, 7, 9, 4, 3]
 
# initializing list 2
li2 = [5, 7, 9, 4, 3]
 
# using heapify() to convert list into heap
heapq.heapify(li1)
heapq.heapify(li2)
 
# using heappushpop() to push and pop items simultaneously
# pops 2
print ("\nBefore calling heappushpop(), li1 is : ",end="")
print (list(li1))
print ("\nThe popped item using heappushpop() is : ",end="")
print (heapq.heappushpop(li1, 2))
print ("\nAfter calling heappushpop(), li1 is : ",end="")
print (list(li1))
 
# using heapreplace() to push and pop items simultaneously
# pops 3
print ("\nBefore calling heapreplace(), li2 is : ",end="")
print (list(li2))
print ("\nThe popped item using heapreplace() is : ",end="")
print (heapq.heapreplace(li2, 2))
print ("\nAfter calling heapreplace(), li2 is : ",end="")
print (list(li2))

del li1, li2

# initializing list 
li1 = [6, 7, 9, 4, 3, 5, 8, 10, 1]
 
# using heapify() to convert list into heap
heapq.heapify(li1)
 
# using nlargest to print 3 largest numbers
# prints 10, 9 and 8
print("The 3 largest numbers in list are : ",end="")
print(heapq.nlargest(3, li1))
print (list(li1))
 
# using nsmallest to print 3 smallest numbers
# prints 1, 3 and 4
print("The 3 smallest numbers in list are : ",end="")
print(heapq.nsmallest(3, li1))
print (list(li1))
