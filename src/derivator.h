#ifndef DERIVATOR_H
#define DERIVATOR_H

class Derivator
{
    private :
        arma::mat create_deriv_mat(int n, int m);
        void derivate_twice(mat *M);
        void add_column(mat *M);
        void add_line(mat *M);
        void fill(mat *M);


    public :
        arma::mat derivator(mat M, int nmax);
        

}

#endif