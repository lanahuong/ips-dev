#!/usr/bin/env python3
import csv
import numpy
import sys


def writer_factory(filename):
    factory_manufactured_file = open(filename, mode='w')
    csv_writer = csv.writer(factory_manufactured_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    return csv_writer


if __name__ == "__main__":
    if len(sys.argv) == 2:
        n = int(sys.argv[1])
        print("Computing polynomials for n = ", n)
        polynomials = numpy.polynomial.hermite.hermgauss(n)
        writer = writer_factory('n.csv')
        writer.writerows(polynomials)

