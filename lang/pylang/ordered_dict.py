#! /usr/bin/python3

from collections import OrderedDict

print("This is a Dict:\n")
d = OrderedDict()
d['a'] = 1
d['b'] = 2
d['c'] = 3
d['d'] = 4

print("Before:\n")
for key, value in d.items():
    print(key, value)

print("\nAfter:\n")
d['c'] = 5
for key, value in d.items():
    print(key, value)

d['c'] = 3
print("Before deleting:\n")

for key, value in d.items():
    print(key, value)

print("\nafter deleting:\n")
d.pop("c")
for key, value in d.items():
    print(key, value)

print("\nafter re-inserting:\n")
d['c'] = 3
for key, value in d.items():
    print(key, value)
