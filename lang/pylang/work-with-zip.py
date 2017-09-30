#! /usr/bin/python

# -*- encoding:utf-8 -*-
import datetime
import os
from zipfile import ZipFile

def extract_file(filename):
    try:
        f = ZipFile(filename)
        f.printdir()

        print('extracting all files now...')
        zip.extractall()
        print('Done!')
    except Exception, e:
        print e

def get_all_file_paths(directory):
    file_paths = []

    for root, directory, files in os.walk(directory):
        for filename in files:
            filepath = os.path.join(root, filename)
            file_paths.append(filepath)

    return file_paths

def  write_zip_file(directory):
    file_paths = get_all_file_paths(directory)

    print('Following files will be zipped:')
    for filename in file_paths:
        print(filename)

    try:
        f = ZipFile('my_python_files.zip', 'w')
        for file1 in file_paths:
            f.write(file1)
    except Exception, e:
        print e

    print('All files zipped successfully!')

#write_zip_file('test-zip')

def get_all_info(filename):
    try:
        f = ZipFile(filename)
        for info in f.infolist():
            print(info.filename)
            print('\tModified:\t' + str(datetime.datetime(*info.date_time)))
            print('\tSystem:\t\t' + str(info.create_system) + '(0 = Windows, 3 = Unix)')
            print('\tZIP version:\t' + str(info.create_version))
            print('\tCompressed:\t' + str(info.compress_size) + ' bytes')
            print('\tUncompressed:\t' + str(info.file_size) + ' bytes')
    except Exception, e:
        print e

get_all_info('/home/liub/Python-2.7.13/Lib/test/zipdir.zip')
