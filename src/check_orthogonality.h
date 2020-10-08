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
    /**
     * To hold the parameters
     */
    int indexMax;
    int nQuadra;

    /**
     * Returns the pre-evalued value (if exists)
     * @param i the index of the value
     * @return
     */
    double getConstFactor(int i);

    /**
     * To hold the pre-evalued values. At compile time we can safely assume the max size
     * given n and m are bound by HERM_QUADRA_N_MAX (n in the lesson )
     */
    double constArray[HERM_QUADRA_N_MAX + 1]{};


    /**
     * Get the weight from the values previously computed in python and included in the header
     * hermite_coefs.h
     * @param i from the \omega_i
     * @return
     */
    double getWeight(int i);


    /**
     * Simple function to compute the factorial factor given a cache stored in pseudoFactorials
     * so the factorials are only computed once
     * @param n
     * @return
     */
    double getPseudoFactorial(int n);

    /**
     * Holds the pre computed values
     */
    double pseudoFactorials[HERM_QUADRA_N_MAX + 1]{};


    /**
     * Holds H_n evaluated on a vector composed of the Gauss-Hermine polynomial's roots
     */
    arma::mat hermiteMatrix;

    /**
     * An array of arma::mat. In each matrix the first row corresponds o the
     */
    arma::mat hermiteQuadra[HERM_QUADRA_N_MAX + 1] = HERMITE_QUADRA_COEFS;

    arma::rowvec getZvector();
};


#endif //PROJET_IPS1_CHECK_ORTHOGONALITY_H
