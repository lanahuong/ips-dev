#include "solverschrodinger.h"
#include "derivator.h"
#include "constants.h"

/**
 * @param OMEGA angular frequency
 * @param m mass
 * @param zmin minimum z where to compute the function
 * @param zmax maximum z where to compute the function
 * @param n maximum energy level
 * @param step the step to subdivise the interval 
 * @return a matrix where enery vary with the row and z with the column
 */
arma::mat SolverSchrodinger::solve1D(double zmin, double zmax, uint n) {
    // Compute the factor of the solution with n constant
    arma::rowvec z = arma::regspace(zmin, STEP, zmax).as_row();
    return SolverSchrodinger::solve1D(z, n);
}

/**
 * @param OMEGA angular frequency
 * @param m mass
 * @param z a vector of z values
 * @param n maximum energy level
 * @return a matrix where enery vary with the row and z with the column
 */
arma::mat SolverSchrodinger::solve1D(const arma::rowvec &z, uint n) {
    // Compute the factor of the solution with n constant
    arma::vec nwiseconst = arma::regspace(0, n);
    nwiseconst[0] = 1;

    for (uint i = 1; i <= n; i++) {
        nwiseconst[i] = nwiseconst[i] * nwiseconst[i - 1] * 2;
    }

    nwiseconst = arma::pow(arma::sqrt(nwiseconst), -1);
    nwiseconst = nwiseconst * sqrt(sqrt(MASS * OMEGA / (arma::datum::pi * H_BAR)));

    // Compute the factor of the solution with n constant
    arma::rowvec zwiseconst = arma::square(z);
    zwiseconst = zwiseconst * -1 * MASS * OMEGA / (2 * H_BAR);
    zwiseconst = arma::exp(zwiseconst);

    // Compute the final solution
    arma::mat result = nwiseconst * zwiseconst;
    arma::mat hermitePolynomes = hermite::computeMatrix(n, z);
    result = result % hermitePolynomes;
    return result;
}

bool SolverSchrodinger::test1DSolution(const arma::rowvec &z, arma::mat phi) {
    // Compute second derivative of each function
    arma::mat dzsecond = derivator::differeniate(phi);

    // Compute left member
    arma::mat left = H_BAR * H_BAR * dzsecond / (2 * MASS);
    left = left + (MASS / 2 * OMEGA * OMEGA * arma::square(z) % phi.cols(1, phi.n_cols - 2));

    // Compute right member
    arma::vec E = (arma::regspace(0, (double) phi.n_rows - 1) + 1. / 2.) * H_BAR * OMEGA;
    arma::mat right = E % phi.cols(1, phi.n_cols - 2);

    // TODO Check left == right
    return false;
}
