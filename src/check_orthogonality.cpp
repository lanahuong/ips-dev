//
// Created by michel on 08/10/2020.
//

#include "check_orthogonality.h"


orthogonalityChecker::orthogonalityChecker(int maxIndex, int nquadra) {
    this->indexMax = maxIndex;
    this->nQuadra = nquadra < HERM_QUADRA_N_MAX ? nquadra : HERM_QUADRA_N_MAX;
    this->alpha = MASS * OMEGA / H_BAR;
    this->hermite_matrix = hermite::computeMatrix(this->indexMax, getZvector());

    /** We initialize the cached values  */
    for (int i = 0; i <= this->indexMax; i++) {
        this->constArray[i] = -1;
        this->factorialArray[i] = 0;
    }
    this->factorialArray[0] = 1;
    this->factorialArray[1] = 1;
}

double orthogonalityChecker::checkFor(int n, int m) {
    double constFactor = getConstFactor(n) * getConstFactor(m);
    double sum = 0;
    for (int i = 0; i < this->nQuadra; i++) {
        sum += getWeight(i) * this->hermite_matrix.at(m, i) * this->hermite_matrix.at(n, i);
    }
    return sum * constFactor;
}


/**
 * Computes the vector that is the Hermite::ComputeMatrix vector
 * @return
 */
arma::rowvec orthogonalityChecker::getZvector() {
    return (this->hermite_quadra[this->nQuadra].row(0).as_row()) / (sqrt(this->alpha));
}

/**
 * Turns out that we have to compute a complex factor for each n or m.
 * This factor is strictly positive, so when on is missing we'll encode
 * that with a negative value.
 * @return
 */
double orthogonalityChecker::getConstFactor(int i) {
    if (this->constArray[i] >= 0) {
        return this->constArray[i]; /** the factor was previously computed */
    } else {
        return this->constArray[i] = pow((MASS * OMEGA / (PI * H_BAR)), 0.25) * pow((double) factorial((uint) i), -0.5) * pow(2, -i);
    }
}

/**
 *
 * @param i
 * @return
 */
double inline orthogonalityChecker::getWeight(int i) {
    return this->hermite_quadra[this->nQuadra].at(1, (arma::uword) i);
}

/**
 * Stupid factorial to improve
 * @param n
 * @return
 */
u_long orthogonalityChecker::factorial(int n) {
    if (this->factorialArray[n] == 0) {
        for (int i = 1; i <= n; i++) {
            if (this->factorialArray[i] == 0) {
                this->factorialArray[i] = this->factorialArray[i - 1] * (u_long) i;
            }
        }
    }
    return this->factorialArray[n];
}