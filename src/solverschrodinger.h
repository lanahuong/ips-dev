/**
 * @file solverschrodinger.h
 *
 * This file contains the SolverSchrodinger class that computes the final
 * solution of the Schrodinger equation.
 */
#ifndef SOLVERSCHRODINGER_H
#define SOLVERSCHRODINGER_H

#include <armadillo>
#include <vector>
#include <cmath>
#include "hermite.h"

/**
 * @class SolverSchrodinger
 *
 * This class solves the Schrodinger equation
 */
class SolverSchrodinger {
  public:
    /**
     * @brief Solve the equation between \a zmin and \a zmax with the step \a
     * step for energie levels from 0 to \a n in 1 dimension
     */
    static arma::mat solve1D(double, double, double, double, int, double);

    /**
     * @brief Solve the equation between \a zmin and \a zmax with the step \a
     * step for energie levels from 0 to \a n in 1 dimension
     */
    static arma::mat solve1D(double, double, arma::rowvec, int, double);
};


#endif // !SOLVERSCHRODINGER_H
