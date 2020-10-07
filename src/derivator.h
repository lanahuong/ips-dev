#ifndef DERIVATOR_H
#define DERIVATOR_H
#include <armadillo>

class Derivator
{
    private :
        
        static arma::Mat<double> derivate_twice(arma::Mat<double> M);
        static void correct_bounds(arma::Mat<double> *M);


    public :
        static arma::Mat<double> derivator(arma::Mat<double> M);
        

};

#endif