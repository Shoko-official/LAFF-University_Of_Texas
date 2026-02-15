#ifndef VECTOR_HPP
#define VECTOR_HPP

/**
 * Basic header of vectors
 * Created the 15/02/2026 by Shoko_ofi
 */

struct Vector {
    double* data;
    int length;
    int capacity;

    Vector(int start_capacity = 4);
    ~Vector();

    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    void push_back(double val);
    
    double& operator[](int index);
    const double& operator[](int index) const;
};

#endif // VECTOR_HPP