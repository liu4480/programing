#! /usr/bin/python

import thread
from time import sleep, ctime

loops = [4, 2]

def loop(nloop, nsec, lock):
    print 'start loop', nloop, ' at:', ctime()
    sleep(nsec)
    print 'loop',nloop, 'done at:', ctime()
    ret=lock.release()
    print 'release lock', nloop, id(lock), ret

def main():
    print 'starting at:', ctime()
    locks = []
    nloop = range(len(loops))

    for i in nloop:
        lock = thread.allocate_lock()
        lock.acquire()
        locks.append(lock)

    for i in nloop:
        print id(locks[i])
        thread.start_new_thread(loop, (i, loops[i], locks[i]))

    for i in nloop:
        while locks[i].locked():
            pass

if __name__ == '__main__':
    main()
