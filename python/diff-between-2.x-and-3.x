1. division operator
on 3.x
>>>7/5
1.4
>>> -7/5
-1.4

on 2.x
>>> 7/5
1
>>> 7./5
1.4
>>> -7/5
-2
>>> -7./5
-1.4

2. print function
This is the most well known change. In this the print function in Python 2.x is replaced by print() function in Python 3.x,i.e, to print in Python 3.x an extra pair of parenthesis is required.

on 3.x
print 'Hello, Geeks'      # Python 3.x doesn't support
print('Hope You like these facts')
>>> print 'Hello, Geeks'
  File "<stdin>", line 1
    print 'Hello, Geeks'
                       ^
SyntaxError: Missing parentheses in call to 'print'
>>> print('Hope You like these facts')
Hope You like these facts

on 2.x
>>> print 'Hello, Geeks'
Hello, Geeks
>>> print('Hope You like these facts')
Hope You like these facts

3. unicode
In Python 2, implicit str type is ASCII. But in Python 3.x implicit str type is Unicode.

on 3.x
>>> print(type('default string '))
<class 'str'>
>>> print(type(b'string with b '))
<class 'bytes'>
>>> print(type('default string '))
<class 'str'>
>>> print(type(u'string with b '))
<class 'str'>

on 2.x
>>> print(type('default string '))
<type 'str'>
>>> print(type(b'string with b '))
<type 'str'>
>>> print(type('default string '))
<type 'str'>
>>> print(type(u'string with b '))
<type 'unicode'>

4. xrange
xrange() of Python 2.x doesn’t exist in Python 3.x.

on 3.x
>>> for x in xrange(1, 5):
...     print(x)
... 
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'xrange' is not defined
>>> for x in range(1, 5):
...     print(x)
... 
1
2
3
4

on 2.x
>>> for x in xrange(1, 5):
...     print(x)
... 
1
2
3
4
>>> for x in range(1, 5):
...     print(x)
... 
1
2
3
4

5. error handling
There is a small change in error handling in both versions. In python 3.x, ‘as’ keyword is required

on 3.x
>>> try:
...     trying_to_check_error
... except NameError, err:
  File "<stdin>", line 3
    except NameError, err:

>>> try:
...      trying_to_check_error
... except NameError as err: # 'as' is needed in Python 3.x
...      print (err, 'Error Caused')
... 
name 'trying_to_check_error' is not defined Error Caused


on 2.x
>>> try:
...     trying_to_check_error
... except NameError, err:
...     print err, 'Error Caused'
... 
name 'trying_to_check_error' is not defined Error Caused

>>> try:
...     trying_to_check_error
... except NameError as err: # 'as' is needed in Python 3.x
...     print (err, 'Error Caused')
... 
(NameError("name 'trying_to_check_error' is not defined",), 'Error Caused')

6. _future_module
This is basically not a difference between two version, but useful thing to mention here. The idea of __future__ module is to help in migration. We can use Python 3.x
