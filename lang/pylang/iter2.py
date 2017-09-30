#! /usr/bin/python3

import itertools

li = [2, 4, 5, 7, 8, 10, 20]
li1 = [(1, 10, 5), (8, 4, 1), (5, 4, 9), (11, 10, 1)]

print("The sliced list values are : ", end="")
print(list(itertools.islice(li, 1, 6, 2)))

print("The values acc. to function are : ", end="")
print(list(itertools.starmap(min, li1)))

li[2] = 6
iti = iter(li)
print("The list values till 1st false value are : ", end="")
print(list(itertools.takewhile(lambda x : x%2==0, li)))

it = itertools.tee(iti, 3)
for i in range(0, 3):
    print(list(it[i]))

print("The combined values of iterables is : ")
print(*(itertools.zip_longest('GesoGes', 'ekfrek', fillvalue='_')))

print("The cartesian product of containers is : ")
print(list(itertools.product('AB', '12')))

print("All the permutations of the given container is : ")
print(list(itertools.permutations('GfG', 2)))

print("All the combination of container in sorted order(witout replacement) is : ")
print(list(itertools.combinations('1234',2)))

print("All the combination of container in sorted order(witout replacement) is : ")
print (list(itertools.combinations_with_replacement('GfG',2)))

#infinite 
#iterator.count(5, 2), can not finc iterator

print("Printing numbers repeatedly : ")
print(list(itertools.repeat(25, 4)))
