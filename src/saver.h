/**
 * @file saver.h
 *
 * This file contains the Saver class that saves a function to CSV.
 */
#ifndef SAVER_H
#define SAVER_H

#include <armadillo>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "hermite.h"

/**
 * @class Saver
 *
 * This class saves a function to a CSV file
 */
class Saver {
  public:
    /**
     * @brief Save functions \a f to CSV
     */
    static void saveToCSV(arma::rowvec, arma::mat);
};


#endif // !SOLVERSCHRODINGER_H
