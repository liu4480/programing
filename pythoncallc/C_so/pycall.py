import ctypes
ll = ctypes.cdll.LoadLibrary
lib = ll("./libpycall.so")
print lib.add(1, 3)
print "***finish***"
