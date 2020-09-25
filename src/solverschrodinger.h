/**
 * @file solverschrodinger.h
 *
 * This file contains the SolverSchrodinger class that computes the final
 * solution of the 1D Schrodinger equation.
 */
#ifndef SOLVERSCHRODINGER_H
#define SOLVERSCHRODINGER_H

#include <armadillo>
#include <vector>
#include "hermite.h"

class SolverSchrodinger {
  public:
    /**
     * @brief Solves the equation between \a zmin and \a zmax with the step \a
     * step for energie levels from 0 to \a n
     */
    static arma::mat solve1D(double, double, double, double, int, double);
};


#endif // !SOLVERSCHRODINGER_H
