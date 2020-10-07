#include "hermite.h"
#include "solverschrodinger.h"

using namespace std;

int main() {
    arma::mat m;
    m = SolverSchrodinger::solve1D(0, 10, 3, 1);
    m.print("The Matrix");
    return 0;
}

