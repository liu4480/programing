#! /usr/bin/python
# -*- encoding:utf-8 -*-

import csv

def read_csv(filename):
    with open(filename) as csvfile:
        csvreader = csv.reader(csvfile)

        fields = csvreader.next()

        for row in csvreader:
            rows.append(row)

        print("Total no. of rows: %d" %(csvreader.line_num))

    print("Field name are:" + ', '.join(field for field in fields))

    print('\nFirst 5 rows are:\n')
    for row in rows[:5]:
        for col in row:
            print("%10s" % col)
        print('\n')

def write_csv(filename);
    # field names
    fields = ['Name', 'Branch', 'Year', 'CGPA']
 
    # data rows of csv file
    rows = [ ['Nikhil', 'COE', '2', '9.0'],
             ['Sanchit', 'COE', '2', '9.1'],
             ['Aditya', 'IT', '2', '9.3'],
             ['Sagar', 'SE', '1', '9.5'],
             ['Prateek', 'MCE', '3', '7.8'],
             ['Sahil', 'EP', '2', '9.1']]
 
    #filename = "university_records.csv"
 
    # writing to csv file
    with open(filename, 'w') as csvfile:
        # creating a csv writer object
        csvwriter = csv.writer(csvfile)
     
        # writing the fields
        csvwriter.writerow(fields)
     
        # writing the data rows
        csvwriter.writerows(rows)

def write_dir_to_csv(filename):
    # my data rows as dictionary objects
    mydict =[{'branch': 'COE', 'cgpa': '9.0', 'name': 'Nikhil', 'year': '2'},
             {'branch': 'COE', 'cgpa': '9.1', 'name': 'Sanchit', 'year': '2'},
             {'branch': 'IT', 'cgpa': '9.3', 'name': 'Aditya', 'year': '2'},
             {'branch': 'SE', 'cgpa': '9.5', 'name': 'Sagar', 'year': '1'},
             {'branch': 'MCE', 'cgpa': '7.8', 'name': 'Prateek', 'year': '3'},
             {'branch': 'EP', 'cgpa': '9.1', 'name': 'Sahil', 'year': '2'}]
     
    # field names
    fields = ['name', 'branch', 'year', 'cgpa']
     
    # name of csv file
    filename = "university_records.csv"
     
    # writing to csv file
    with open(filename, 'w') as csvfile:
        # creating a csv dict writer object
        writer = csv.DictWriter(csvfile, fieldnames = fields)
         
        # writing headers (field names)
        writer.writeheader()
         
        # writing data rows
        writer.writerows(mydict)
