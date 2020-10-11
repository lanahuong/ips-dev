#include "Derivator.h"
#include "Hermite.h"
#include <armadillo>


void Derivator::differentiateTwice(arma::Mat<double> &m) {
    arma::uword n = m.n_cols;
    arma::Mat<double> M_n1 = m;
    arma::Mat<double> M_n_1 = m;
    if (likely(n > 2)) {
        M_n1.shed_col(0);
        M_n1.insert_cols(n - 2, 1);  //création de la matrice au rang z + h
        M_n_1.shed_col(n - 1);
        M_n_1.insert_cols(0, 1);   //création de la matrice z - h

        m = M_n1 + M_n_1 - 2 * m;      // dérivée seconde discrète
    } else {
        m = arma::zeros(size(m));
    }
}


void Derivator::correctBounds(arma::Mat<double> &m) {
    arma::uword n = m.n_cols;
    if (likely(n > 2)) {
        m.shed_col(0);
        m.shed_col(n - 2);
    }
}


arma::mat Derivator::differentiate(arma::Mat<double> m) {
    differentiateTwice(m);
    correctBounds(m);
    return m;
}
