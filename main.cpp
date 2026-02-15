/*
 * Basic test file
 * Created by Shoko on 2026/02/15
 */

#include "Matrix.hpp"

extern "C" int printf(const char *, ...);

/**
 * Copies the contents of vector x into vector y.
 * Handles all combinations of row and column vectors
 * @param x Source matrix
 * @param y Destination matrix
 * @return true if copy succeeded, false: if dimensions are invalid or incompatible
 */
bool copy(const Matrix &x, Matrix &y) {
    /*
     * In case you need :
     * m_x, m_y: Number of rows
     * n_x, n_y: number of columns
     */
    int m_x = x.m;
    int n_x = x.n;
    int m_y = y.m;
    int n_y = y.n;

    /*
     * Vector Validation:
     * A matrix is a vector only if it has a singleton dimension
     * If neither dimension is 1, the input is NOT a vector
     */
    if ((m_x != 1 && n_x != 1) || (m_y != 1 && n_y != 1)) {
        return false; // FAILED
    }

    // Cardinality must match for element wise assignment 
    if (m_x * n_x != m_y * n_y) {
        return false; // FAILED
    }

    if (n_x == 1) {
        if (n_y == 1) {
            for (int i = 0; i < m_x; i++) {
                y(i, 0) = x(i, 0);
            }
        } else {
            for (int i = 0; i < m_x; i++) {
                y(0, i) = x(i, 0);
            }
        }
    } else {
        if (n_y == 1) {
            for (int i = 0; i < n_x; i++) {
                y(i, 0) = x(0, i);
            }
        } else {
            for (int i = 0; i < n_x; i++) {
                y(0, i) = x(0, i);
            }
        }
    }

    return true; // PASSED
}

void print_matrix(const char *name, Matrix &A) {
    printf("%s =\n", name);
    for (int i = 0; i < A.m; i++) {
        printf("   ");
        for (int j = 0; j < A.n; j++) {
            printf("%4.1f", A(i, j));
            if (j < A.n - 1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // x = [1; 2; 3]
    Matrix x(3, 1);
    x(0, 0) = 1.0;
    x(1, 0) = 2.0;
    x(2, 0) = 3.0;

    // y_old = [0; -1; -2] (Used to reset y)
    Matrix y_old(3, 1);
    y_old(0, 0) = 0.0;
    y_old(1, 0) = -1.0;
    y_old(2, 0) = -2.0;

    Matrix y(3, 1); // Destination vector

    copy(y_old, y); 
    if (copy(x, y)) {
        print_matrix("y (Col <- Col)", y);
    } else {
        printf("y (Col <- Col) FAILED\n");
    }

    // Reset y to be a row vector of correct size
    Matrix y_row(1, 3);
    
    // y = copy(x, y_row)
    if (copy(x, y_row)) {
        print_matrix("y_row (Row <- Col)", y_row);
    } else {
        printf("y_row (Row <- Col) FAILED\n");
    }

    return 0;
}