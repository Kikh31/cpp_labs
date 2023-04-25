#pragma once

class ComplexNum {
private:
    double ReZ;
    double ImZ;

public:
    ComplexNum(double, double);

    ComplexNum();

    ComplexNum operator*(double);

    ComplexNum operator+(ComplexNum &);

    ComplexNum operator*(ComplexNum &);

    operator double() const;

    void printCplx() const;
};