#include <cstdio>
#include <iostream>
#include "eqTriangle.h"
#include "cmath"

using namespace std;

double eqTriangle::lenght() const {
    return sqrt(pow(a.y-b.y, 2) + pow(a.x-b.x, 2));
}

double eqTriangle::square() {
    return pow(eqTriangle::lenght(), 2) * sqrt(3) / 2;
}

double eqTriangle::perimeter() {
    return 3*lenght();
}

double eqTriangle::mass() const {
    return weight;
}

CVector2D eqTriangle::position() {
    double x0, y0;
    x0 = (a.x + b.x + c.x) / 3;
    y0 = (a.y + b.y + c.y) / 3;

    return {x0, y0};
}

bool eqTriangle::operator==(const IPhysObject &ob) const {
    return mass() == ob.mass();
}

bool eqTriangle::operator<(const IPhysObject &ob) const {
    return mass() < ob.mass();
}

void eqTriangle::draw() {
    cout<<"Equilateral triangle:\n";
    printf("A(%f, %f), ", a.x, a.y);
    printf("B(%f, %f), ", b.x, b.y);
    printf("C(%f, %f);\n", c.x, c.y);
    cout<<"Weight = "<<weight<<'\n';
}

void eqTriangle::initFromDialog() {
    cout<<"Enter coordinates:\n";
    cout<<"A(x,y):";
    cin>>a.x>>a.y;
    cout<<"B(x,y):";
    cin>>b.x>>b.y;
    cout<<"C(x,y):";
    cin>>c.x>>c.y;

    cout<<"Enter weight:\n";
    cin>>weight;
}

eqTriangle::eqTriangle() {
    eqTriangle::initFromDialog();
}

const char *eqTriangle::classname() {
    return typeid(*this).name();
}

unsigned int eqTriangle::size() {
    return sizeof(*this);
}
