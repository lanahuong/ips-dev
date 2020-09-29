#include "solverschrodinger.h"

/**
 * @param e energy
 * @param m mass
 * @param zmin minimum z where to compute the function
 * @param zmax maximum z where to compute the function
 * @param n maximum energy level
 * @param step the step to subdivise the interval 
 * @return a matrix where enery vary with the row and z with the column
 */
arma::mat SolverSchrodinger::solve1D(double e, double m, double zmin, double zmax,
    int n, double step) {
  return arma::mat();
}
  
