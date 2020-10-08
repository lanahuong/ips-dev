#include "main.h"

using namespace std;

int main() {
    double bound = 7;
    int n = 3;
    arma::mat m = solverSchrodinger::solve1D(-bound, bound, n);
    m.print("The Matrix");

    auto *checker = new orthogonalityChecker(5);
    cout << checker->checkFor(4, 4) << '\n';
    cout << checker->checkFor(2, 4) << '\n';
    cout << checker->checkFor(1, 4) << '\n';

    arma::rowvec z = arma::regspace(-bound, STEP, bound).as_row();
    Saver::saveToCSV(z, m);

    return 0;
}
