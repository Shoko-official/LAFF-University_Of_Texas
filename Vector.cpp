#include "Vector.hpp"

/**
 * Basic implementation of vectors
 * Created the 15/02/2026 by Shoko_ofi
 */

Vector::Vector(int start_capacity) {
    length = 0;
    capacity = start_capacity;
    
    if (capacity <= 0) capacity = 1;
    data = new double[capacity];
}

Vector::~Vector() { delete[] data;}

void Vector::push_back(double val) {
    if (length == capacity) {
        capacity *= 2;
        double* temp = new double[capacity];
        for (int i = 0; i < length; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
    
    data[length] = val;
    length++;
}


double& Vector::operator[](int index) {
    return data[index];
}

const double& Vector::operator[](int index) const {
    return data[index];
}