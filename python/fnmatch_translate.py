#! /usr/bin/python3

import fnmatch, re

regex = fnmatch.translate('*.txt')
reobj = re.compile(regex)

print(regex)
print(reobj.match('foobar.txt'))
