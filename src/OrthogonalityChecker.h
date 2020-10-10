#ifndef PROJET_IPS1_ORTHOGONALITYCHECKER_H
#define PROJET_IPS1_ORTHOGONALITYCHECKER_H


#include <armadillo>
#include "constants.h"
#include "hermiteCoefs.h"
#include "Hermite.h"
#include "SolverSchrodinger.h"

/**
 * Works with a memory thus needs to be initialised
 * @remark could be implemented more efficiently by dynamically
 * computing the values as needed.
 */
class OrthogonalityChecker {
public:
    explicit OrthogonalityChecker(uint indexMax = HERM_QUADRA_N_MAX, uint nQuadra = HERM_QUADRA_N_MAX);

    double checkFor(uint n, uint m);

private:
    /**
     * To hold the parameters
     */
    uint indexMax;
    uint nQuadra;


    /**
     * Get the weight from the values previously computed in python and included in the header
     * hermite_coefs.h
     * @param i from the \omega_i
     * @return
     */
    arma::Row<double> getWeightVector();


    /**
     * Simple function to compute the factorial factor given a cache stored in pseudoFactorials
     * so the factorials are only computed once
     * @param n
     * @return
     */
    void initPseudoFactorial();

    /**
     * Holds the pre computed values
     */
    arma::rowvec pseudoFactorials;


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


#endif //PROJET_IPS1_ORTHOGONALITYCHECKER_H
