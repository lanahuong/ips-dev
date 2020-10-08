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
    explicit orthogonalityChecker(int indexMax = HERM_QUADRA_N_MAX, int nQuadra = HERM_QUADRA_N_MAX);

    double checkFor(int n, int m);

private:
    int indexMax;
    int nQuadra;

    double getConstFactor(int i);

    double constArray[HERM_QUADRA_N_MAX + 1]{};

    double getWeight(int i);

    u_long factorialArray[HERM_QUADRA_N_MAX + 1]{};

    u_long factorial(int n);

    arma::mat hermite_matrix;
    arma::mat hermite_quadra[HERM_QUADRA_N_MAX + 1] = HERMITE_QUADRA_COEFS;

    arma::rowvec getZvector();
};


#endif //PROJET_IPS1_CHECK_ORTHOGONALITY_H
