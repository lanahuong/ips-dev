#ifndef PROJET_IPS1_HERMITE_H
#define PROJET_IPS1_HERMITE_H

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

#include <armadillo>
#include <vector>

class hermite {
public:
    static arma::mat computeMatrix(int, const arma::rowvec &);
};


#endif //PROJET_IPS1_HERMITE_H
