import tarfile
import os
import sys
import time
import StringIO

start=time.time()
tar = tarfile.open("pacemaker-mgmt.tar", 'w')
tar.add('pacemaker-mgmt')
tar.close()

print time.time() - start
f = open('pacemaker-mgmt.tar', 'r')
lines = f.readlines()
f.close()

string = StringIO.StringIO()
string.write(lines)
string.seek(0)
info = tarfile.TarInfo(name="pacemaker-mgmt")
info.size = len(string.buf)

t=tarfile.open('/tmp/pacemaker-mgmt.tar','w')
t.addfile(tarinfo=info, fileobj=string)
t.close()

start2 = time.time()
t = tarfile.open('pacemaker-mgmt.tar','r:')
t.extractall(path='/tmp/')
t.close()
print time.time()-start2
print time.time()-start
