# Introduction to scientific programming project

## Subject

The goal was to compute numerical solution to the time-independent Schrodinger
equation and numerically check the energy and the orthonormality of the
solutions.

Unit tests and a good management of the git repository were also required.

## Usage

To build the whole project, go to the root of the project and run :

```
make
```

To run the unit tests you can either, run `bin/tests` after building the whole
project or run from the root :

```
make check
```

to build and run the tests

To generate the documentation, run from the root :

```
make doc
```

The documentation is then available in HTML format at `doc/html/index.html`.

To get the solutions, run :

```
bin/solver
```

The solutions are saved in CSV format in `tmp/schrodinger_solutions.csv`, you
can copy it elsewhere to save the results otherwise they will be replaced when
you run the program again.

You can then plot the solutions with the script `scripts/csv_plotter.py` by
running :

```
scripts/csv_plotter.py path/to/solutions.csv
```

To have readable plots be careful not to plot to many curves.

To clear the project build, run :

```
make clean
```

## Change the conditions

You can change some parameters of the Schrodinger equation located in
`src/constants.h` :
* the `MASS`
* the angular frequency `OMEGA`
* the `STEP`

In `src/main.cpp`, you can also change the value of `n` the number of energy
levels and `bound` that sets the interval on which the function is computed.

Don't forget to rebuild the project with `make -B` after changing one of these
values.