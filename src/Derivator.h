/**
 * @file Derivator.h
 * This file implements a function which de
 */

#ifndef DERIVATOR_H
#define DERIVATOR_H

#include <armadillo>


/**
 * Differentiates twice a matrix
 * @class Derivator
 */
class Derivator {
private :

    /**
     * @brief Does the second discrete derivative of the matrix by columns, excluding the first one and the last 
     * @param m matrix to differentiate
     */
    static void differentiateTwice(arma::Mat<double> &m);

    /**
     * @brief If the matrix has 3 or more columns, removes the first one and the last
     * @param m matrix to correct
     */
    static void correctBounds(arma::Mat<double> &m);

public :
    /**
     * @brief If the matrix has 3 or more colums, differentiates it twice then removes the first column and the last since they don't make sense
     * @param m matrix to differentiate
     * @return a matrix corresponding to the second discrete derivative of the matrix m
     */
    static arma::Mat<double> differentiate(arma::Mat<double> m);

};

#endif
