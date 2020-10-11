/**
 * @file tests_derivator.cpp
 *
 * This file contains unit test for the class Derivator
 */

#include <gtest/gtest.h>
#include <armadillo>
#include <vector>
#include <assert.h>

#include "../src/derivator.h"

/**
 * @struct define the parameter of SolutionTest
 */
struct solution_check{
    arma::Mat<double> M;
    arma::Mat<double> res;


    friend std::ostream& operator<<(std::ostream& os, const solution_check& state) {
        os << "{M = ";
        arma.print(state.M);
        return os;
    }
}

/**
 * @class SolutionTest
 * This class defines parameterized tests using instances of solution_check as parameter
 */
class SolutionTest : public testing::TestWithParam<solution_check> {
  public:
  SolutionTest() {};
};

/**
 * @brief Creates an instance of SolutionTest that will run the given test
 */
TEST_P(SolutionTest, solutionSize) {
  solution_check state = GetParam();
  arma::mat result = Derivator::derivator(state.M);

  ASSERT_EQ(arma::approx_equal(result,state.res),true)
}

arma::Mat<double> test1(){
    arma::Mat<double> M = arma::zeros(5,6);
    for (int i=1,5,i++){
        for (int j=1,6,j++){
            M(i,j) = i+j-1;
        }
    }
    return M;
}

/* arma::Mat<double> test2(){
    arma::Mat<double> M = arma::zeros(8,7);
    for (int i=1,5,i++){
        for (int j=1,6,j++){
            M(i,j) = ;
        }
    }
    return M;
}
*/
NSTANTIATE_TEST_SUITE_P(BasicCases, SolutionTest, testing::Values(
      solution_check{test1(),arma::zeros(5,4))},
     // solution_check{test2(),arma::},
    ));

