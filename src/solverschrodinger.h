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
#include "derivator.h"

/**
 * @class SolverSchrodinger
 *
 * This class solves the Schrodinger equation
 */
class solverSchrodinger {
public:
    /**
     * @brief Solve the equation between \a zmin and \a zmax with the step \a
     * step for energie levels from 0 to \a n in 1 dimension
     */
    static arma::mat solve1D(double zmin, double zmax, int n);

    /**
     * @brief Solve the equation between \a zmin and \a zmax with the step \a
     * step for energie levels from 0 to \a n in 1 dimension
     */
    static arma::mat solve1D(const arma::rowvec &z, int n);

    /**
     * @brief Test the solution
     */
    static bool test1DSolution(const arma::rowvec &z, arma::mat phi);
};


#endif // !SOLVERSCHRODINGER_H
