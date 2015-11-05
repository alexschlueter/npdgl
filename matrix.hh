
// This file is part of the Praktikum zur Vorl. Num. PDGL, Wintersemester 2015/2016
// http://dune-project.uni-muenster.de/repos/projects/praktikum-numpde-2015-2016.git
// Copyright holders: Christoph Lehrenfeld, Felix Schindler
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <valarray>
#include <iostream>

typedef std::valarray<double> Vector;

class Matrix
{
public:
  // constructor (creates an object based on input arguments)
  Matrix();
  // returns number of cols
  virtual int Cols() const = 0;
  // returns number of rows
  virtual int Rows() const = 0;
  // implementation of the multiplication
  virtual void Mult( const Vector & x, Vector & y ) const = 0;

  Vector operator* (const Vector & x);
};

class IdMatrix : public Matrix
{
private:
  int _dim;

public:
  // constructor (creates an object based on input arguments)
  IdMatrix(int dim);
  // returns number of cols
  virtual int Cols() const;
  // returns number of rows
  virtual int Rows() const;
  // implementation of the multiplication
  virtual void Mult( const Vector & x, Vector & y ) const;
};

class Partial_xx : public Matrix
{
private:
  int _a;
  int _h;
  int _N;

public:
  // constructor (creates an object based on input arguments)
  Partial_xx(int a, int h, int N);
  // returns number of cols
  virtual int Cols() const;
  // returns number of rows
  virtual int Rows() const;
  // implementation of the multiplication
  virtual void Mult( const Vector & x, Vector & y ) const;
};
