//
// Created by migda on 16/09/2020.
//

#ifndef PROJET_IPS1_HERMITE_H
#define PROJET_IPS1_HERMITE_H


#include <armadillo>
#include <vector>

class hermite {
public:
    static arma::mat computeMatrix(int, const arma::rowvec &);
};


#endif //PROJET_IPS1_HERMITE_H
