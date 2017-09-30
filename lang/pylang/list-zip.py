#! /usr/bin/python3

geek = ['Geeks', 'Programming', 'Algorithm', 'Article']
 
# Directly printing the list
print ("Simple List:", geek)
  
# Printing the list by join method
print ('List by using join method: %s' % ', ' .join(geek))
   
# Direct use of join method
print ('Direct apply the join method:',(", " .join(geek)))

# Declaring the list geek
geek = ['Sun', 'Flowers', 'Peoples', 'Animals', 'Day', 'Night']
 
# In python 2.7, just remove the list keyword
partition = list(zip (*[iter(geek)] * 2))
print (partition)

list1 = [1, 3, 5, 7]
list2 = [2, 4, 6, 8]

print (zip(list1, list2))
print (repr(zip(list1, list2)))

for a, b in zip(list1, list2):
    print(a, b)

formatted_list = list(map(int, input().split()))
print(formatted_list)

import itertools
 
# Declaring the list geek
geek = [[1, 2], [3, 4], [5, 6]]
  
# chain.from_iterable() function returns the elements of nested list
# and iterate from first list of iterable till the last
# end of the list
   
lst = list(itertools.chain.from_iterable(geek))
print(lst)

print ("G" + "e"*5 + "k"*4 + "s"*2)
