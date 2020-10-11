#include "main.h"

using namespace std;

int main() {
    double bound = 7;
    uint n = 3;
    arma::mat m = SolverSchrodinger::solve1D(-bound, bound, n);
    m.print("The Matrix");

    auto *checker = new OrthogonalityChecker();

    for (uint i = 0; i < HERM_QUADRA_N_MAX; i++) {
        for (uint j = 0; j < HERM_QUADRA_N_MAX; j++) {
            cout << "params: " << i << " " << j << "res: " << checker->checkFor(i, j) << '\n';
        }
    }
    free(checker);

    arma::rowvec z = arma::regspace(-bound, STEP, bound).as_row();
    bool test = SolverSchrodinger::test1DSolution(z, m);

    cout << to_string(test);

    Saver::saveToCSV(z, m);

    return 0;
}
