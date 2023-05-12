#include <cstdio>
#include <iostream>
#include "parallelogram.h"
#include "cmath"

using namespace std;

pair<double, double> parallelogram::lenghts() const {
    double ab = sqrt(pow(a.y-b.y, 2) + pow(a.x-b.x, 2));
    double ac = sqrt(pow(a.y-c.y, 2) + pow(a.x-c.x, 2));

    return {ab, ac};
}

double parallelogram::square() {
    pair<double, double> sides = parallelogram::lenghts();

    return sides.first * sides.second * sin(angle);
}

double parallelogram::perimeter() {
    pair<double, double> sides = parallelogram::lenghts();

    return 2*(sides.first + sides.second);
}

double parallelogram::mass() const {
    return weight;
}

CVector2D parallelogram::position() {
    double x0 = (b.x+c.x)/2;
    double y0 = (b.y+c.y)/2;

    return {x0, y0};
}

bool parallelogram::operator==(const IPhysObject &ob) const {
    return mass() == ob.mass();
}

bool parallelogram::operator<(const IPhysObject &ob) const {
    return mass() < ob.mass();
}

void parallelogram::draw() {
    cout<<"Parallelogram:\n";
    printf("A(%f, %f), ", a.x, a.y);
    printf("B(%f, %f), ", b.x, b.y);
    printf("C(%f, %f);\n", c.x, c.y);
    cout<<"Angle = "<<angle<<'\n';
    cout<<"Weight = "<<weight<<'\n';
}

void parallelogram::initFromDialog() {
    cout<<"Enter coordinates:\n";
    cout<<"A(x,y):";
    cin>>a.x>>a.y;
    cout<<"B(x,y):";
    cin>>b.x>>b.y;
    cout<<"C(x,y):";
    cin>>c.x>>c.y;

    cout<<"Enter angle:\n";
    cin>>angle;

    cout<<"Enter weight:\n";
    cin>>weight;
}

parallelogram::parallelogram() {
    parallelogram::initFromDialog();
}

const char *parallelogram::classname() {
    return typeid(*this).name();
}

unsigned int parallelogram::size() {
    return sizeof(*this);
}
