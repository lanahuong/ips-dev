#include "hermite.h"

/**
 * Computes a matrix containing...
 * @param n_max an integer, n can be equal to 0, must be positive
 * @param zRowvec double strictly smaller than z_end
 * @return
 */
arma::mat hermite::computeMatrix(int n_max, const arma::rowvec &zRowvec) {
    /**
     * If the parameters are nonsense the matrix (0) is returned
     */
    arma::uword rowLen = zRowvec.size();
    arma::uword nMax = static_cast<arma::uword>(n_max);
    arma::mat hermOut = arma::mat(nMax + 1, rowLen, arma::fill::zeros);
    hermOut.row(0) = arma::vec(rowLen, arma::fill::ones).t();
    if (likely(n_max > 0)) {
        hermOut.row(1) = 2 * zRowvec;
        for (arma::uword i = 2; i <= nMax; i++) {
            hermOut.row(i) = hermOut.row(1) % hermOut.row(i - 1) - 2. * ((double) i - 1.) * hermOut.row(i - 2);
        }
    }
    return hermOut;
}
