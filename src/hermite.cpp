//
// Created by migda on 16/09/2020.
//

#include "hermite.h"

/**
 * Computes a matrix containing...
 * @param n_max an integer, n can be equal to 0
 * @param z_start
 * @param z_end
 * @param step
 * @return
 */
arma::mat Hermite::ComputeMatrix(int n_max, double z_start, double z_end, double step) {
    /**
     * If the parameters are nonsense the matrix (0) is returned
     */
    if (n_max < 0 || step <= 0 || z_start >= z_end) {
        return arma::mat(1, 1, arma::fill::zeros);
    }

    arma::vec z = arma::regspace(z_start, step, z_end);
    int n = z.size();
    arma::mat m = arma::mat(n_max + 1, n, arma::fill::zeros);
    m.row(0) = arma::vec(n, arma::fill::ones).t();
    if (n_max > 0) {
        m.row(1) = 2 * z.t();
        for (int i = 2; i <= n_max; i++) {
            m.row(i) = m.row(1) % m.row(i - 1) - 2 * (i-1) * m.row(i - 2);
        }
    }
    return m;
}
