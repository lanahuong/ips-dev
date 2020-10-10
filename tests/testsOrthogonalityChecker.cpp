#include <gtest/gtest.h>
#include "../src/OrthogonalityChecker.h"

struct orthoSolutionCheckOnePair {
    int n;
    int m;
    int nMaxIndex;
    int nQuadra;

    /**
     * @brief format when printing a solution_check object
     */
    friend std::ostream &operator<<(std::ostream &os, const orthoSolutionCheckOnePair &state) {
        os << "{n=" << state.n << "; m=" << state.m << "}\n";
        return os;
    }
};


/**
 * @class SolutionTest
 * This class defines parameterized tests using instances of solution_check as parameter
 */
class OrthogonalityCheckerTest : public testing::TestWithParam<orthoSolutionCheckOnePair> {
public:
    OrthogonalityCheckerTest() = default;;
    OrthogonalityChecker *checker = new OrthogonalityChecker(GetParam().nMaxIndex, GetParam().nQuadra);
};

/**
 * @brief Creates an instance of SolutionTest that will run the given test
 */
TEST_P(OrthogonalityCheckerTest, onePair) {
    orthoSolutionCheckOnePair state = GetParam();
    double res = checker->checkFor(state.n, state.m);
    if (state.n > state.nMaxIndex || state.m > state.nMaxIndex || state.n + state.m > (2 * state.nQuadra) - 1) {
        ASSERT_TRUE(std::isnan(res));
    } else {
        if (state.n != state.m) {
            ASSERT_TRUE(abs(res) < EPSILON);
        } else {
            ASSERT_TRUE(abs(res - 1) < EPSILON);
        }
    }
}

/**
 * Run all SolutionTest tests with given values
 */
INSTANTIATE_TEST_SUITE_P(AllPairs, OrthogonalityCheckerTest, testing::Values(
        orthoSolutionCheckOnePair{100, 2, 10, 10}
));
