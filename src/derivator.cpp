#include "derivator.h"
#include <armadillo>


void derivator::derivateTwice(arma::Mat<double> &m) {
    arma::uword n = m.n_cols;
    arma::Mat<double> M_n1 = m;
    arma::Mat<double> M_n_1 = m;
    if (n > 2) {
        M_n1.shed_col(0);
        M_n1.insert_cols(n - 2, 1);  //création de la matrice au rang z + h

        M_n_1.shed_col(n - 1);
        M_n_1.insert_cols(0, 1);   //création de la matrice z - h

        m = M_n1 + M_n_1 - 2 * m;      // dérivée seconde discrète
    } else {
        m = arma::zeros(size(m));
    }
}


void derivator::correctBounds(arma::Mat<double> &m) {
    arma::uword n = m.n_cols;
    if (n > 2) {
        m.shed_col(0);
        m.shed_col(n - 2);
    }
}


arma::mat derivator::differeniate(arma::Mat<double> m) {
    derivateTwice(m);
    correctBounds(m);
    return m;
}
