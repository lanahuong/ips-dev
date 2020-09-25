#include <gtest/gtest.h>
#include <armadillo>
#include <vector>

#include "../src/solverschrodinger.h"

/** @struct define the parameter of SolutionTest
 */
struct solution_check {
  double e;
  double m;
  double zmin;
  double zmax;
  double step;
  int n;
  int length;

  friend std::ostream& operator<<(std::ostream& os, const solution_check& state) {
    os << "{e=" << state.e << "; m=" << state.m;
    os << "; zmin=" << state.zmin << "; zmax=" << state.zmax << "; step=" << state.step;
    os << "; n=" << state.n << "; length=" << state.length << "}\n";
    return os;
  }
};

class SolutionTest : public testing::TestWithParam<solution_check> {
  public:
  SolutionTest() {};
};

TEST_P(SolutionTest, solutionSize) {
  solution_check state = GetParam();
  arma::mat result = SolverSchrodinger::solve1D(state.e, state.m, state.zmin, state.zmax, state.n, state.step);

  EXPECT_EQ(state.n, result.n_rows);
  EXPECT_EQ(state.length, result.n_cols);
}

INSTANTIATE_TEST_SUITE_P(BasicCases, SolutionTest, testing::Values(
      solution_check{1,1,-1,1,1,1,2},
      solution_check{1,1,-10,10,1,1,20},
      solution_check{1,1,-1,1,0.1,1,20}
    ));
