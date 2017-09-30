#! /usr/bin/python
# -*- encoding:utf-8 -*-
import PyPDF2

pdfFileObj = open("/home/liub/桌面/glusterfs/doc/legacy/coding-standard.pdf", 'rb')

pdfReader = PyPDF2.PdfFileReader(pdfFileObj)

print(pdfReader.numPages)

pageObj = pdfReader.getPage(2)

print(pageObj.extractText())

pdfFileObj.close()
