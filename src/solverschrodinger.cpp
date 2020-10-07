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

  // Compute the factor of the solution with n constant
  arma::rowvec z = arma::regspace(zmin,step,zmax).t();
  
  return SolverSchrodinger::solve1D(w, m, z, n);
}
  
/**
 * @param w angular frequency
 * @param m mass
 * @param z a vector of z values
 * @param n maximum energy level
 * @return a matrix where enery vary with the row and z with the column
 */
arma::mat SolverSchrodinger::solve1D(double w, double m, arma::rowvec z,
    int n) {

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
  arma::rowvec zwiseconst = arma::square(z);
  zwiseconst = zwiseconst * -1 * m * w / (2 * h_bar);
  zwiseconst = arma::exp(zwiseconst);

  // Compute the final solution
  arma::mat result = nwiseconst * zwiseconst;

  arma::mat hermitePolynomes = Hermite::ComputeMatrix(n, z);

  result = result % hermitePolynomes;

  return result;
}

bool SolverSchrodinger::test1DSolution(double w, double m, arma::rowvec z, arma::mat phi) {
  
  // This should be defined in a macro
  double h_bar = 1;

  // Compute second derivative of each function
  arma::mat dzsecond = Derivator::derivator(phi);

  // Compute left member
  arma::mat left = h_bar * h_bar * dzsecond / (2*m);
  left = left + (m/2 * w * w * arma::square(z) % phi.cols(1,phi.n_cols-2));

  // Compute right member
  arma::vec E = (arma::regspace(0,phi.n_rows-1) + 1/2 ) * h_bar * w;
  arma::mat right = E % phi.cols(1,phi.n_cols-2);

  // TODO Check left == right
  return false;
}
