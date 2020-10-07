#include "hermite.h"

/**
 * Computes a matrix containing...
 * @param n_max an integer, n can be equal to 0, must be positive
 * @param z_start double strictly smaller than z_end
 * @return
 */
arma::mat Hermite::ComputeMatrix(int n_max, const arma::vec &z_start) {
    /**
     * If the parameters are nonsense the matrix (0) is returned
     */
    int n = z_start.size();
    arma::mat herm_out = arma::mat(n_max + 1, n, arma::fill::zeros);
    herm_out.row(0) = arma::vec(n, arma::fill::ones).t();
    if (n_max > 0) {
        herm_out.row(1) = 2 * z_start.t();
        for (int i = 2; i <= n_max; i++) {
            herm_out.row(i) = herm_out.row(1) % herm_out.row(i - 1) - 2 * (i - 1) * herm_out.row(i - 2);
        }
    }
    return herm_out;
}
