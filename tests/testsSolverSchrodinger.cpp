/**
 * @file tests_solverschrodinger.cpp
 *
 * This file contains unit test for the class SolverSchrodinger
 */

#include <gtest/gtest.h>
#include <armadillo>
#include <vector>

#include "../src/SolverSchrodinger.h"
#include "../src/constants.h"

/**
 * @struct define the parameter of SolutionTest
 */
struct solution_check {
    double zmin;
    double zmax;
    uint n;
    // expected number of rows in the resulting matrix
    uint length;

    /**
     * @brief format when printing a solution_check object
     */
    friend std::ostream &operator<<(std::ostream &os, const solution_check &state) {
        os << "; zmin=" << state.zmin << "; zmax=" << state.zmax;
        os << "; n=" << state.n << "; length=" << state.length << "}\n";
        return os;
    }
};

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
    arma::mat result = SolverSchrodinger::solve1D(state.zmin, state.zmax, state.n);

    EXPECT_EQ(state.n + 1, result.n_rows);
    EXPECT_EQ(state.length, result.n_cols);
}

/**
 * Run all SolutionTest tests with given values
 */
INSTANTIATE_TEST_SUITE_P(BasicCases, SolutionTest, testing::Values(
        solution_check{-1, 1, 1, uint((2 / STEP) + 1)},
        solution_check{-10, 10, 1, uint((20 / STEP) + 1)},
        solution_check{-1, 1, 4, uint((2 / STEP) + 1)}
));