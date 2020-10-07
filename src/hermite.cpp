#include "hermite.h"

/**
 * Computes a matrix containing...
 * @param n_max an integer, n can be equal to 0, must be positive
 * @param z_rowvec double strictly smaller than z_end
 * @return
 */
arma::mat Hermite::ComputeMatrix(int n_max, const arma::rowvec &z_rowvec) {
    /**
     * If the parameters are nonsense the matrix (0) is returned
     */
    arma::uword row_len = z_rowvec.size();
    auto nMax = static_cast<arma::uword>(n_max);
    arma::mat herm_out = arma::mat(nMax + 1, row_len, arma::fill::zeros);
    herm_out.row(0) = arma::vec(row_len, arma::fill::ones).t();
    if (n_max > 0) {
        herm_out.row(1) = 2 * z_rowvec;
        for (arma::uword i = 2; i <= nMax; i++) {
            herm_out.row(i) = herm_out.row(1) % herm_out.row(i - 1) - 2. * ((double) i - 1.) * herm_out.row(i - 2);
        }
    }
    return herm_out;
}
