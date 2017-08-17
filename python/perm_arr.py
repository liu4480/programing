def perm(arr, offset):
    if offset == len(arr) - 1:
        printarray(arr)
        return
    else:
        i = offset;
        while i < len(arr):
            swap(arr, i, offset)
            perm(arr, offset+1)
            swap(arr, i, offset)
            i = i + 1

def printarray(arr):
    print '--------------'
    print arr
    print '--------------'

def swap(arr, i, offset):
    tmp = arr[i]
    arr[i] = arr[offset]
    arr[offset] = tmp

arr=[1,2,3,4]
perm(arr, 0)
