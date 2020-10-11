#ifndef DERIVATOR_H
#define DERIVATOR_H

#include <armadillo>

class Derivator {
private :
    static void differentiateTwice(arma::Mat<double> &m);

    static void correctBounds(arma::Mat<double> &m);

public :
    static arma::Mat<double> differentiate(arma::Mat<double> m);

};

#endif
