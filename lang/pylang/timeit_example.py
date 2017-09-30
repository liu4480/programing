#! /usr/bin/python

import timeit

mysetup="from math import sqrt"
code='''
def example():
    mylist = []
    for x in range(100):
        mylist.append(sqrt(x))
    print mylist
'''

print timeit.timeit(setup=mysetup, stmt=code, number=10000)
