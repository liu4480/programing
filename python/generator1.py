#! /usr/bin/python3

def simpleGeneratorFun():
    yield 1
    yield 2
    yield 3

print("generator-function", end="\n")
for value in simpleGeneratorFun():
    print(value)

print("generator-object", end="\n")
x = simpleGeneratorFun()
print(x.__next__())
print(x.__next__())
print(x.__next__())

def fib(limit):
    a, b = 0, 1

    while a < limit:
        yield a
        a, b = b, a + b

x = fib(5)
print("\nUsing __next__()\n")
print(x.__next__())
print(x.__next__())
print(x.__next__())
print(x.__next__())
print(x.__next__())

print("\nUsing for in loop\n")
for i in fib(5):
    print(i)
