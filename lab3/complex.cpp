#include <iostream>
#include "complex.h"
#include <cmath>

ComplexNum::ComplexNum(double ReZ, double ImZ) {
    this->ReZ = ReZ;
    this->ImZ = ImZ;
}

ComplexNum::ComplexNum() {
    this->ReZ = 0;
    this->ImZ = 0;
}

ComplexNum ComplexNum::operator*(double x) {
    return {ReZ * x, ImZ * x};
}

ComplexNum ComplexNum::operator+(ComplexNum &cn) {
    return {ReZ + cn.ReZ, ImZ + cn.ImZ};
}

ComplexNum ComplexNum::operator*(ComplexNum &cn) {
    return {ReZ * cn.ReZ - ImZ * cn.ImZ, ImZ * cn.ReZ + ReZ * cn.ImZ};
}

ComplexNum::operator double() const {
    return sqrt(pow(ReZ, 2) + pow(ImZ, 2));
}

void ComplexNum::printCplx() const {
    if (ImZ > 0) {
        std::cout << ReZ << " + " << ImZ << "i\n";
    } else if (ImZ == 0) {
        std::cout << ReZ << '\n';
    } else if (ImZ < 0) {
        std::cout << ReZ << " - " << -ImZ << "i\n";
    }
}


