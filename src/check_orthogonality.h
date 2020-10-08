//
// Created by michel on 08/10/2020.
//

#ifndef PROJET_IPS1_CHECK_ORTHOGONALITY_H
#define PROJET_IPS1_CHECK_ORTHOGONALITY_H

#include <armadillo>
#include "constants.h"
#include "hermite_coefs.h"
#include "hermite.h"
#include "solverschrodinger.h"

/**
 * Works with a memory thus needs to be initialised
 * @remark could be implemented more efficiently by dynamically
 * computing the values as needed.
 */
class orthogonalityChecker {
public:
    orthogonalityChecker(int indexMax, int nQuadra);

    double checkFor(int n, int m);

private:
    arma::rowvec getZvector();

    double getConstFactor(int i);

    double constArray[HERM_QUADRA_N_MAX + 1]{};
    int indexMax;
    int nQuadra;
    double alpha;

    double getWeight(int i);

    double getRoot(int i);

    double getConst(int n, int m);

    arma::mat hermite_matrix;
    arma::mat hermite_quadra[HERM_QUADRA_N_MAX + 1] = HERMITE_QUADRA_COEFS;

    static u_long factorial(uint n);
};


#endif //PROJET_IPS1_CHECK_ORTHOGONALITY_H
