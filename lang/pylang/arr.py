# Python code to demonstrate the working of 
# array(), append(), insert()
  
# importing "array" for array operations
import array
  
# initializing array with array values
# initializes array with signed integers
arr = array.array('i', [1, 2, 3]) 
 
# printing original array
print ("The new created array is : ",end="")
for i in range (0,3):
    print (arr[i], end=" ")
 
print ("\r")
 
# using append() to insert new value at end
arr.append(4);
 
# printing appended array
print ("The appended array is : ", end="")
for i in range (0, 4):
    print (arr[i], end=" ")
     
# using insert() to insert value at specific position
# inserts 5 at 2nd position
arr.insert(2, 5)
 
print("\r")
 
# printing array after insertion
print ("The array after insertion is : ", end="")
for i in range (0, 5):
    print (arr[i], end=" ")

print("\r")
print ("The popped element is : ",end="")
print (arr.pop(2));
 
# printing array after popping
print ("The array after popping is : ",end="")
for i in range (0,4):
    print (arr[i],end=" ")
 
print("\r")
 
# using remove() to remove 1st occurrence of 1
arr.remove(1)
 
# printing array after removing
print ("The array after removing is : ",end="")
for i in range (0,3):
    print (arr[i],end=" ")
print("\r")

del arr
arr= array.array('i',[1, 2, 3, 1, 2, 5]) 
 
# printing original array
print ("The new created array is : ",end="")
for i in range (0,6):
    print (arr[i],end=" ")
 
print ("\r")
 
# using index() to print index of 1st occurrenece of 2
print ("The index of 1st occurrence of 4 is : ",end="")
try:
    print (arr.index(4))
except ValueError as err:
    print(err)
 
#using reverse() to reverse the array
arr.reverse()
 
# printing array after reversing
print ("The array after reversing is : ",end="")
for i in range (0,6):
    print (arr[i],end=" ")
print('\r')

# using typecode to print datatype of array
print ("The datatype of array is : ",end="")
print (arr.typecode)
 
# using itemsize to print itemsize of array
print ("The itemsize of array is : ",end="")
print (arr.itemsize)
 
# using buffer_info() to print buffer info. of array
print ("The buffer info. of array is : ",end="")
print (arr.buffer_info())
print('\r')

del arr

arr1 = array.array('i', [1, 2, 3, 1, 2, 5])
arr2 = array.array('i', [1, 2, 3])

print("The occurences of 1 in arr1 is : ", end="")
print(arr1.count(1))

arr1.extend(arr2)
print("The modified arr1 is : ", end="")
print(arr1)

del arr1
del arr2

arr = array.array('i', [1, 2, 3, 1, 2, 5])
li = [1, 2, 3]

arr.fromlist(li)

print(arr)

li2 = arr.tolist()
print(li2)
