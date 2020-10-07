#include "main.h"
#include "hermite.h"
using namespace std;

int main(int argc, char** argv) {

  cout << "Hello world" << endl;

  arma::vec z = arma::regspace(0,0.1, 10);
  Hermite::ComputeMatrix(30, z).print("The Matrix");

  return 0;
}

