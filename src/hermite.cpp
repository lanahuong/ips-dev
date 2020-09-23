//
// Created by migda on 16/09/2020.
//

#include "hermite.h"

/**
 * Computes a matrix containing...
 * @param n_max an integer, n can be equal to 0, must be positivs
 * @param z_start double strictly smaller than z_end
 * @param z_end double strictly greater than z_start
 * @param step double strictly greater than zero
 * @return
 */
arma::mat Hermite::ComputeMatrix(int n_max, double z_start, double z_end, double step) {
    /**
     * If the parameters are nonsense the matrix (0) is returned
     */
    arma::mat herm_out ;
    if (n_max < 0 || step <= 0 || z_start >= z_end) {
        herm_out = arma::mat(1, 1, arma::fill::zeros);
    } else {
        arma::vec z = arma::regspace(z_start, step, z_end);
        int n = z.size();
        herm_out = arma::mat(n_max + 1, n, arma::fill::zeros);
        herm_out.row(0) = arma::vec(n, arma::fill::ones).t();
        if (n_max > 0) {
            herm_out.row(1) = 2 * z.t();
            for (int i = 2; i <= n_max; i++) {
                herm_out.row(i) = herm_out.row(1) % herm_out.row(i - 1) - 2 * (i - 1) * herm_out.row(i - 2);
            }
        }
    }
    return herm_out;
}
