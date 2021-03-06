#! /usr/bin/python

import os
import sys
import commands
import time
import socket
import smtplib
import utils
import getopt

import smtplib
from email.mime.text import MIMEText
mailto_list=["yyy@xxx.com", "ttt@xxx.com"]
mail_host="xxx.xxx.com"
mail_port='xxx'
mail_user="xxx"
mail_pass="*********"
mail_postfix="XXX.com"

class Disk:
    def __init__(self, label, path, stat):
        self.label = label
        self.path = path
        self.stat = stat
    
    def get_label(self):
        return self.label

    def get_path(self):
        return self.path

class VM:
    def __init__(self, name, disks=[]):
        self.name = name
        self.disks = []

    def adddisk(self, disk):
        self.disks.append(disk)

    def removedisk(self, disk):
        self.disks.pop(disk)

    def vm_mtime(self):
        self.lastmodified = 0
        for disk in self.disks:
            if self.lastmodified < disk.stat.st_mtime:
                self.lastmodified = disk.stat.st_mtime
        return self.lastmodified

    def get_vmname(self):
        return self.name

    def get_disks(self):
        return self.disks

def canCleanVMs(pathname="/mnt/vm/"):
    avail = utils.get_fs_freespace(pathname)
    return avail < 1 - 0.6

def formatVMs(vmlist, listname):
    content = '\n\tVMs are %s:' % listname
    for vm in vmlist:
        content = content + '\n\t\t%s:' % vm.name
        for disk in vm.disks:
            #content = content + '\n\t\t\t%s\t%s\t\t\t%s' % (disk.label, disk.path, time.asctime(time.localtime(disk.stat.st_mtime)))
            content = content + '\n\t\t\t%s\t%s\t\t\t%s' % (disk.label, disk.path, time.strftime("%Y-%m-%d", time.localtime(disk.stat.st_mtime)))
    return content

def printVMs(vmlist, listname):
    print '\tVMs are %s:' % listname
    for vm in vmlist:
        print '\t\t%s:' % vm.name
        for disk in vm.disks:
            print '\t\t\t%s\t%s\t\t\t%s' % (disk.label, disk.path, time.asctime(time.localtime(disk.stat.st_mtime)))

def getVMByName(vmname):
    cmd = 'virsh domblklist %s|grep \/' % (vmname)
    status, output = commands.getstatusoutput(cmd)
    if status:
        sys.exit(-1)
    disk_list = output.split('\n')
    expired = False
    delete = False
    vm = VM(vmname)
    for disk in disk_list:
        label, path = disk.strip().split()
        if os.path.exists(path) == False:
            continue
        stat_struct = os.stat(path)
        disk1 = Disk(label, path, stat_struct)
        vm.adddisk(disk1)
    return vm

def remove_vm(vm):
    vmname = vm.get_vmname()
    disk_list = vm.get_disks()
    cmd = 'virsh destroy %s' % vmname
    status, output = commands.getstatusoutput(cmd)
    print "destroying vm %s" % vmname
    for disk in disk_list:
        path = disk.get_path()
        if os.path.exists(path) == False:
            continue
        stat_struct = os.stat(path)
        os.remove(path)
        print "os.remove(%s)" % path
    cmd = "virsh undefine %s" % vmname
    status, output = commands.getstatusoutput(cmd)
    print "status, output = commands.getstatusoutput(%s)" % cmd

def removeVMByName(vmname):
    vm = getVMByName(vmname)
    remove_vm(vm)

def getVMList():
    cmd='virsh list --all|grep "shut off"'
    status, output=commands.getstatusoutput(cmd)
    elelist=output.split('\n')
    expired_list=[]
    delete_list=[]
    now = time.time()
    diff = 0
    if canCleanVMs() == False:
        sys.exit(-1)
    for el in elelist:
        vmname = el[7:][:-8].strip()
        vm = getVMByName(vmname)
        diff = now - vm.vm_mtime()
        if diff >= 7776000:
            delete_list.append(vm)
            remove_vm(vm)
            
        elif diff >= 5184000 and diff < 7776000:
            expired_list.append(vm)

    content = formatVMs(delete_list, "deleted")
    content = content + '\n' + formatVMs(expired_list, "expired") + '\n\n' 
    return content

def getHostInfo():
    hostname = socket.gethostname()
    #ip = socket.gethostbyname(hostname)
    #print '\tThe host is (%s/%s) ' %(hostname, ip)
    return 'On Host %s' %(hostname)

def get_ip_first_ip():
    cmd = 'ip addr|grep -w inet|egrep -v "vir|127.0.0.1"'
    status,output = commands.getstatusoutput(cmd)
    ipList=output.split('\n')
    return ipList[0].strip().split()[1]

def get_content():
    content = getHostInfo()
    ip = get_ip_first_ip()
    title = 'SLEX Lab - VM garbage collector - %s(%s) ' % (socket.gethostname(), ip)
    content = content + "("+ ip + ")\n" + getVMList()
    if os.path.exists('notice.txt'):
        f = open('notice.txt')
        content = content + f.read()
        print content
    return title, content
 
def send_mail(to_list,sub,content):
    me="xxx"+"<"+mail_user+"@"+mail_postfix+">"
    msg = MIMEText(content,_subtype='plain',_charset='gb2312')
    msg['Subject'] = sub
    msg['From'] = me
    msg['To'] = ";".join(to_list)
    try:
        s = smtplib.SMTP(mail_host, mail_port)
        #s.ehlo()
        s.starttls()
        s.login(mail_user,mail_pass)
        s.sendmail(me, to_list, msg.as_string())
        s.close()
        return True
    except Exception, e:
        print str(e)
        return False

def usage():
    print '''Usage:
        To clean old vms and sendmail: ./cleanVM.py -m
        To remove specified vms: ./cleanVM.py -c "vm1 vm2"
    '''
    sys.exit(-2)
if __name__ == '__main__':
    opts, args = getopt.getopt(sys.argv[1:], "c:m")
    for opt, value in opts:
       if opt == '-m':
           title, content = get_content()
           print content
           if send_mail(mailto_list,title,content):
               print "success"
               sys.exit(0)
           else:
               print "failed"
               sys.exit(-3)
       elif opt == '-c':
           vm_list = value.split()
           for vmname in vm_list:
               removeVMByName(vmname)
           sys.exit(0)
    usage()
