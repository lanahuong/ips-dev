#include "hermite.h"
#include "solverschrodinger.h"
#include "check_orthogonality.h"

using namespace std;


int main() {
    arma::mat m;
    m = solverSchrodinger::solve1D(0, 1, 1);
    m.print("The Matrix");


    auto *checker = new orthogonalityChecker(5, 2);

    cout << checker->checkFor(5, 5);


    return 0;
}