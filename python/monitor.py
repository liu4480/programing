#http://download.suse.de/ibs/SUSE:/SLE-12-SP2:/GA/standard/x86_64/
import re, os, urllib2, sys
#pacemaker-1.1.15-17-x86_64.rpm
#corosync-2.3.5-4.2.x86_64.rpm
#patterns=['pacemaker-(\d)','corosync-(\d)+']
patterns=['^pacemaker-(\d)+\.(\d)+\.(\d)+-(\d)+\.(\d)+\.(\w)+\.rpm','^corosync-(\d)+\.(\d)+\.(\d)+-(\d)+\.(\d)+\.\w+\.rpm']

def isTheRPM(package):
    if not package.endswith('rpm'):
        return False
    for pattern in patterns:
        p = re.compile(pattern)
        if p.match(package):
            return True
    return False

def get_all_packages(html):
    content = html.split()
    packages = []
    for line in content:
        if "pacemaker" in line or "corosync" in line:
            package=line.split('"')[1].split('"')[0]
            if isTheRPM(package) and package not in packages:
                packages.append(package)
    return packages

def save_package_info(html):
    packages = get_all_packages(html)
    f = open('package_info','w')
    content=""
    for package in packages:
        content = content + package + "\n"
    f.write(content)
    f.close()

def get_package_info():
    f = open('package_info')
    return f.read().split()

response=urllib2.urlopen('http://download.suse.de/ibs/SUSE:/SLE-12-SP2:/GA/standard/x86_64/')
html = response.read()

old_packages = get_package_info()
new_packages = get_all_packages(html)
if old_packages == new_packages:
    print "do not need to update"
    sys.exit(1)
else:
    print "please update"
    save_package_info(html)
    sys.exit(0)
