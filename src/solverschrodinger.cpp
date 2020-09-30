#include "solverschrodinger.h"

/**
 * @param w angular frequency
 * @param m mass
 * @param zmin minimum z where to compute the function
 * @param zmax maximum z where to compute the function
 * @param n maximum energy level
 * @param step the step to subdivise the interval 
 * @return a matrix where enery vary with the row and z with the column
 */
arma::mat SolverSchrodinger::solve1D(double w, double m, double zmin, double zmax,
    int n, double step) {

  // This should be defined in a macro
  double h_bar = 1;

  // Compute the factor of the solution with n constant
  arma::vec nwiseconst = arma::regspace(0,n);
  nwiseconst[0] = 1;

  for (int i=1; i<=n; i++) {
    nwiseconst[i] = nwiseconst[i]*nwiseconst[i-1]*2;
  }

  nwiseconst = arma::pow(arma::sqrt(nwiseconst), -1);
  nwiseconst = nwiseconst * sqrt(sqrt(m * w / (arma::datum::pi * h_bar)));

  // Compute the factor of the solution with n constant
  arma::rowvec zwiseconst = arma::regspace(zmin,step,zmax).as_row();
  
  zwiseconst = arma::square(zwiseconst);
  zwiseconst = zwiseconst * -1 * m * w / (2 * h_bar);
  zwiseconst = arma::exp(zwiseconst);

  // Compute the final solution
  arma::mat result = nwiseconst * zwiseconst;

  arma::mat hermitePolynomes = Hermite::ComputeMatrix(n, zmin, zmax, step);

  result = result % hermitePolynomes;

  return result;
}
  
