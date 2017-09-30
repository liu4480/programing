import time

somelist = [1, -3, 6, 11, 5]
start = time.clock()
somelist.sort()
end = time.clock()
print somelist, end - start
 
somelist = [1, -3, 6, 11, 5]
start = time.clock()
somelist=sorted(somelist)
end = time.clock()
print somelist, end - start

print somelist, end - start
s = 'geeks'
# use sorted() if you don't want to sort in-place:
s = sorted(s)
print s
