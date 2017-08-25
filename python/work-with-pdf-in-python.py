#! /usr/bin/python3

import PyPDF2
# -*- encoding : utf-8 -*-

pdfFileObj = open("working-images-python.pdf", 'rb')

pdfReader = PyPDF2.PdfFileReader(pdfFileObj)

print(pdfReader.numPages)

pageObj = pdfReader.getPage(2)

print(pageObj.extractText())

pdfFileObj.close()
