#include "hermite.h"
#include "solverschrodinger.h"
#include "check_orthogonality.h"

using namespace std;


int main() {
    arma::mat m = solverSchrodinger::solve1D(0, 1, 1);
    m.print("The Matrix");

    auto *checker = new orthogonalityChecker();

    for (int i = 0; i < HERM_QUADRA_N_MAX; i++) {
        for (int j = 0; j < HERM_QUADRA_N_MAX; j++) {
            cout << "params: " << i << " " << j << "res: " << checker->checkFor(i, j) << '\n';
        }
    }
    //free(checker);


    return 0;
}