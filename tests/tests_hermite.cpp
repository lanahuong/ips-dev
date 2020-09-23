// calc_test.cpp
#include <gtest/gtest.h>
#include "../src/hermite.h"


#define EPSILON 0.0001

using namespace arma;


TEST(Hermite, ComputeMatrix) {
    mat mat_zero = mat(1, 1, fill::zeros);
    mat M;
    /** Wrong order */
    M = Hermite::ComputeMatrix(-2, 1.0, 2.0, 0.01);
    ASSERT_TRUE(approx_equal(mat_zero, M, "absdiff", EPSILON)) << "Fail with non null matrix while n_max is neg";

    M = Hermite::ComputeMatrix(2, 1.0, -1.0, 0.01);
    ASSERT_TRUE(approx_equal(mat_zero, M, "absdiff", EPSILON)) << "Fail with non null matrix while z_max is smaller than z_min";

    M = Hermite::ComputeMatrix(10, 1.0, 2.0, 0);
    ASSERT_TRUE(approx_equal(mat_zero, M, "absdiff", EPSILON)) << "Fail with non null matrix while step is null";

    

}