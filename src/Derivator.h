/**
 * @file Derivator.h
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
     *
     * @param m
     */
    static void differentiateTwice(arma::Mat<double> &m);

    /**
     *
     * @param m
     */
    static void correctBounds(arma::Mat<double> &m);

public :
    /**
     *
     * @param m
     * @return
     */
    static arma::Mat<double> differeniate(arma::Mat<double> m);
};

#endif