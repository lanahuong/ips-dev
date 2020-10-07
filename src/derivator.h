#ifndef DERIVATOR_H
#define DERIVATOR_H
#include <armadillo>

class Derivator
{
    private :
        
        arma::Mat<double> derivate_twice(arma::Mat<double> M);
        void correct_bounds(arma::Mat<double> *M);


    public :
        arma::Mat<double> derivator(arma::Mat<double> M);
        

};

#endif