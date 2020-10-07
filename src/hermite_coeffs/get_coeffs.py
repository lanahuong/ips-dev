#!/usr/bin/env python3
import csv
import sys

import numpy


def writer_factory(f):
    csv_writer = csv.writer(f, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    return csv_writer


if __name__ == "__main__":
    if len(sys.argv) == 2:
        n = int(sys.argv[1])
        print("Computing polynomials for n = ", n)
        polynomials = numpy.polynomial.hermite.hermgauss(n)
        file = open('n.csv', mode='w')
        writer = writer_factory(file)
        writer.writerows(polynomials)
        file.close()
