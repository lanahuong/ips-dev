//
// Created by migda on 16/09/2020.
//

#ifndef PROJET_IPS1_HERMITE_H
#define PROJET_IPS1_HERMITE_H


#include <armadillo>
#include <vector>

class Hermite {
public:
    static arma::mat ComputeMatrix(int, const arma::vec);
};


#endif //PROJET_IPS1_HERMITE_H
