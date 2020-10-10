#!/usr/bin/env python3
import csv
import sys
import matplotlib.pyplot as pp

if len(sys.argv) == 1:
    print("Missing argument : you must specify the CSV file to load")

else:
    functions = []
    z = []

    with open(sys.argv[1], newline='') as csvfile:
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
