#include "hermite.h"
#include "solverschrodinger.h"
#include "check_orthogonality.h"

using namespace std;


int main() {
    arma::mat m;
    // m = solverSchrodinger::solve1D(0, 1, 1);
    // m.print("The Matrix");


    auto *checker = new orthogonalityChecker(5, 5);

    cout << checker->checkFor(4, 4) << '\n';
    cout << checker->checkFor(2, 4) << '\n';
    cout << checker->checkFor(1, 4) << '\n';

    return 0;
}