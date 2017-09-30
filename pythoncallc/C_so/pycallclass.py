import ctypes
so = ctypes.cdll.LoadLibrary
lib = so("./libpycallclass.so")

lib.display()
lib.display_int(100)
print lib.add(100, 200)
