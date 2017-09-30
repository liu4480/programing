#! /usr/bin/python
# -*- encoding:utf-8 -*-
import PyPDF2

def PDFrotate(origFileName, newFileName, rotation):
    pdfFileObj = open(origFileName, 'rb')

    pdfReader = PyPDF2.PdfFileReader(pdfFileObj)
    pdfWriter = PyPDF2.PdfFileWriter()

    for page in range(pdfReader.numPages):
        pageObj = pdfReader.getPage(page)
        pageObj.rotateClockwise(rotation)

        pdfWriter.addPage(pageObj)

    newFile = open(newFileName, 'wb')
    pdfWriter.write(newFile)

    pdfFileObj.close()
    newFile.close()

#PDFrotate("/home/liub/桌面/glusterfs/doc/legacy/coding-standard.pdf", "rotate.pdf", 270)

def PDFMerge(pdfs, output):
    pdfMerger = PyPDF2.PdfFileMerger()

    for pdf in pdfs:
        with open(pdf, 'rb') as f:
            pdfMerger.append(f)

    with open(output, 'wb') as f:
        pdfMerger.write(f)

#pdfs = ['coding-standard.pdf', 'rotate.pdf']
#PDFMerge(pdfs, 'combined.pdf')

def PDFsplit(pdf, splits):
    pdfFileObj = open(pdf, 'rb')

    pdfReader = PyPDF2.PdfFileReader(pdfFileObj)

    start = 0;
    end = splits[0]

    for i in range(len(splits) + 1):
        pdfWriter = PyPDF2.PdfFileWriter()

        outputpdf = pdf.split('.pdf')[0] + str(i) + '.pdf'

        for page in range(start, end):
            pdfWriter.addPage(pdfReader.getPage(page))

        with open(outputpdf, 'wb') as f:
            pdfWriter.write(f)

        start = end
        try:
            end = splits[i+1]
        except IndexError:
            end = pdfReader.numPages
    pdfFileObj.close()

#PDFsplit('coding-standard.pdf', [2,4])
def add_watermark(vmFile, pageObj):
    vmFileObj = open(vmFile, 'rb')

    pdfReader = PyPDF2.PdfFileReader(vmFileObj)

    pageObj.mergePage(pdfReader.getPage(0))

    vmFileObj.close()
    return pageObj


