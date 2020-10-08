#!/usr/bin/env python3
import csv
import matplotlib.pyplot as pp

functions = []
z = []

with open('schrodinger_solutions.csv', newline='') as csvfile:
    funcreader = csv.reader(csvfile, delimiter=',', quoting=csv.QUOTE_NONNUMERIC)
    i = 0
    for row in funcreader:
        if i == 0:
            z = row
        else:
            functions.append(row)
        i+=1

for i in range(len(functions)):
    pp.plot(z,functions[i])

pp.show()
