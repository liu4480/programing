import os

def tt(arg='',top='.',fnames=''):
    print fnames, arg

def list_dir(path):
    print path
    print os.path.walk(path, tt, (path,1,2))

def binarysearch(arr, num):
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = (start + end) >> 1
        if arr[mid] == num:
            if arr[mid + 1] > num:
                return mid
            else:
                start = mid + 1
        elif arr[mid] > num:
            end = mid - 1
        else:
            start = mid + 1
    return mid

list1=[3,1,-2,4]
list1.sort()
print list1
index=binarysearch(list1, 2)
print index
for i in range(index):
    print list1[i]**2
