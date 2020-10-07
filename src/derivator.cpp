#include "derivator.h"
#include <iostream>
#include <armadillo>


 arma::mat Derivator::derivate_twice(arma::Mat<double> M){
    int n = M.n_cols;
    arma::Mat<double> M_n1 = M;
    arma::Mat<double> M_n_1 = M;
    if (n>2){
        M_n1.shed_col(0);
        M_n1.insert_cols(n-2,1);  //création de la matrice au rang z + h

        M_n_1.shed_col(n-1);
        M_n_1.insert_cols(0,1);   //création de la matrice z - h

        M = M_n1 + M_n_1 -2*M;      // dérivée seconde discrète
    }
    else{
        M = arma::zeros(size(M));
    }
    return M;
}


arma::Mat<double> Derivator::correct_bounds(arma::Mat<double> M){
    int n = (M).n_cols;
    if (n>2){
        (M).shed_col(0);
        (M).shed_col(n-2);
    }
    return M;
}


arma::mat Derivator::derivator(arma::Mat<double>  M){
    M = derivate_twice(M);
    correct_bounds(M);
    return M;
}
