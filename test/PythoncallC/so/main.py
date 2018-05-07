import  ctypes
dll=ctypes.cdll.LoadLibrary
lib = dll('./c_so.so')
print 'python call c so:'
lib.add_func(2,3)
