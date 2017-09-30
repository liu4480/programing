#! /usr/bin/python3

import struct
import ctypes

# h is short in C type
# l is long in C type
# i is int in C type
# ?is bool in C type
# q is long long int in C type
# f is float in C type

var = struct.pack('hhl', 1, 2, 3)
print(var)

var = struct.pack('?iii', True, 1, 2, 3)
print(var)

tup = struct.unpack('?iii', var)
print(tup)

var = struct.pack('?hil', True, 2, 5, 445)
print(var)
print(struct.calcsize("?hil"))
print(struct.calcsize("qf"))

siz = struct.calcsize('hhl')
print(siz)

buff = ctypes.create_string_buffer(siz)
x=struct.pack('hhl', 1, 2, 3)
print(x)
print(struct.unpack('hhl', x))

struct.pack_into('hhl', buff, 0, 2, 2, 3)
print(*buff)
print(struct.unpack_from('hhl', buff, 0))
