#include <gtest/gtest.h>
#include <armadillo>

struct orthoSolutionCheck {
    int n;
    int m;

    /**
     * @brief format when printing a solution_check object
     */
    friend std::ostream &operator<<(std::ostream &os, const orthoSolutionCheck &state) {
        os << "{n=" << state.n << "; m=" << state.m << "}\n";
        return os;
    }
};