#include "main.h"
#include "hermite.h"
using namespace std;

int main(int argc, char** argv) {

  cout << "Hello world" << endl;

  Hermite::ComputeMatrix(30, 0, 5, 0.1).print("The Matrix");

  return 0;
}

