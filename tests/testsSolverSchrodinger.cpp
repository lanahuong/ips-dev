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
 * @struct define the parameter of SolutionBoundedTest
 */
struct solution_bounded_state {
    double zmin;
    double zmax;
    uint n;
    // expected number of rows in the resulting matrix
    uint length;

    /**
     * @brief format when printing a solution_bounded_state object
     */
    friend std::ostream &operator<<(std::ostream &os, const solution_bounded_state &state) {
        os << "; zmin=" << state.zmin << "; zmax=" << state.zmax;
        os << "; n=" << state.n << "; length=" << state.length << "}\n";
        return os;
    }
};

/**
 * @class SolutionBoundedTest
 * This class defines parameterized tests using instances of solution_bounded_state as parameter
 */
class SolutionBoundedTest : public testing::TestWithParam<solution_bounded_state> {
public:
    SolutionBoundedTest() {};
};

/**
 * @brief Creates an instance of SolutionBoundedTest that will run the given test
 */
TEST_P(SolutionBoundedTest, solutionSize) {
    solution_bounded_state state = GetParam();
    arma::mat result = SolverSchrodinger::solve1D(state.zmin, state.zmax, state.n);

    EXPECT_EQ(state.n + 1, result.n_rows);
    EXPECT_EQ(state.length, result.n_cols);
}

/**
 * Run all SolutionBoundedTest tests with given values
 */
INSTANTIATE_TEST_SUITE_P(BasicCases, SolutionBoundedTest, testing::Values(
        solution_bounded_state{-1, 1, 1, uint((2 / STEP) + 1)},
        solution_bounded_state{-10, 10, 1, uint((20 / STEP) + 1)},
        solution_bounded_state{-1, 1, 4, uint((2 / STEP) + 1)}
));
