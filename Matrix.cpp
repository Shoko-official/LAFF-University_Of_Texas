#include "Matrix.hpp"

/**
 * Basic implementation of matrices
 * Created the 15/02/2026 by Shoko_ofi
 */

Matrix::Matrix(int rows, int cols) : m(rows), n(cols), data(rows * cols) {
  for (int i = 0; i < rows * cols; i++) {
    data.push_back(0.0);
  }
}

double &Matrix::operator()(int i, int j) {
    return data[i * n + j];
}

const double& Matrix::operator()(int i, int j) const {
    return data[i * n + j];
}

