
// This file is part of the Praktikum zur Vorl. Num. PDGL, Wintersemester 2015/2016
// http://dune-project.uni-muenster.de/repos/projects/praktikum-numpde-2015-2016.git
// Copyright holders: Christoph Lehrenfeld, Felix Schindler
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "matrix.hh"

using namespace std;

int main(int argc, char* argv[])
{
  Partial_xx A(2, 5, 10);
  Vector y(11);
  Vector x(11);
  x = 1.0;
  cout << "A.Rows() = " << A.Rows() << endl;

  y = A * x;
  cout << "y = " << endl;;
  for (auto entry : y )
    cout << entry << endl;
}
