class Test:
    def func(self, x):
        print x+x

obj = Test()
mytest = obj.func
n=2
for i in range(n):
    mytest(i)
