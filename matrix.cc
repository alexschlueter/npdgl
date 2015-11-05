
// This file is part of the Praktikum zur Vorl. Num. PDGL, Wintersemester 2015/2016
// http://dune-project.uni-muenster.de/repos/projects/praktikum-numpde-2015-2016.git
// Copyright holders: Christoph Lehrenfeld, Felix Schindler
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)

#include "matrix.hh"

Matrix::Matrix()
{
}

Vector Matrix::operator* (const Vector & x)
{
  Vector y(Rows());
  Mult(x, y);
  return y;
}

IdMatrix::IdMatrix(int dim) : _dim(dim)
{
}

int IdMatrix::Cols() const
{
  return _dim;
}

int IdMatrix::Rows() const
{
  return _dim;
}

void IdMatrix::Mult(const Vector & x, Vector & y) const
{
  y = x;
}

Partial_xx::Partial_xx(int a, int h, int N) : _a(a), _h(h), _N(N)
{
}

int Partial_xx::Cols() const
{
  return _N + 1;
}

int Partial_xx::Rows() const
{
  return _N + 1;
}

void Partial_xx::Mult(const Vector & x, Vector & y) const
{
  for (int i = 0; i <= _N; i++)
  {
    if (i != 0)
    {
      y[i - 1] = - _a * x[i - 1] / (_h * _h);
    }

    y[i] = 2 * _a * x[i] / (_h * _h);

    if (i != _N)
    {
      y[i + 1] = - _a * x[i + 1] / (_h * _h);
    }
  }
}
