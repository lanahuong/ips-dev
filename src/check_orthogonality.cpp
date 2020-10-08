#include "check_orthogonality.h"


/**
 * The maximum value for n and m is bound by the max degree of the polynomial we have
 * @param maxIndex
 * @param nquadra
 */
orthogonalityChecker::orthogonalityChecker(int maxIndex, int nquadra) {
    this->indexMax = maxIndex < HERM_QUADRA_N_MAX ? maxIndex : HERM_QUADRA_N_MAX;
    this->nQuadra = nquadra < HERM_QUADRA_N_MAX ? nquadra : HERM_QUADRA_N_MAX;
    this->hermiteMatrix = hermite::computeMatrix(this->indexMax, getZvector());

    /** We initialize the cached values  */
    for (int i = 0; i <= this->indexMax; i++) {
        this->constArray[i] = -1;
        this->pseudoFactorials[i] = 0;
    }
    this->pseudoFactorials[0] = 1;
}


/**
 * The Hermite polynomial has a degree of n, thus here its n+m
 * If we force n and m to be smalled than the degree of the quadrature
 *  we can ensure that the result is not an approximation
 * @param n
 * @param m
 * @return nan if the values are out of bound
 */
double orthogonalityChecker::checkFor(int n, int m) {
    if (unlikely(n > indexMax || m > indexMax)) {
        return std::numeric_limits<double>::quiet_NaN();
    } else {
        double constFactor = getConstFactor(n) * getConstFactor(m);
        double sum = 0;
        for (int i = 0; i < this->nQuadra; i++) {
            sum += getWeight(i) * this->hermiteMatrix.at(m, i) * this->hermiteMatrix.at(n, i);
        }
        return sum * constFactor;
    }
}


/**
 * Computes the vector that is the Hermite::ComputeMatrix vector
 * The numerator corresponds to the factor that apprears when we change the
 * integration variable.
 * @return
 */
arma::rowvec orthogonalityChecker::getZvector() {
    return (this->hermiteQuadra[this->nQuadra].row(0).as_row()) / (sqrt(MASS * OMEGA / H_BAR));
}

/**
 * Turns out that we have to compute a complex factor for each n or m.
 * This factor is strictly positive, so when on is missing we'll encode
 * that with a negative value.
 * @return
 */
double orthogonalityChecker::getConstFactor(int i) {
    if (this->constArray[i] >= 0) {
        /** the factor was previously computed */
        return this->constArray[i];
    } else {
        /** we compute it */
        return this->constArray[i] = pow((MASS * OMEGA / (PI * H_BAR)), 0.25) * getPseudoFactorial(i);
    }
}


double inline orthogonalityChecker::getWeight(int i) {
    return this->hermiteQuadra[this->nQuadra].at(1, (arma::uword) i);
}

/**
 * Corresponds to the factor 1/sqrt(n!2**n), each time we multiply the previous
 * number by 1/(sqrt 2n) so there's no overflow
 * @param n
 * @return
 */
double orthogonalityChecker::getPseudoFactorial(int n) {
    if (this->pseudoFactorials[n] == 0) {
        for (int i = 1; i <= n; i++) {
            if (this->pseudoFactorials[i] == 0) {
                this->pseudoFactorials[i] = this->pseudoFactorials[i - 1] * pow(2 * i, -0.5);
            }
        }
    }
    return this->pseudoFactorials[n];
}