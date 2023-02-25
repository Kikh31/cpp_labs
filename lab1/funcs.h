#pragma once

void fun3(int&, int&);
void _fun3(int*, int*);

void fun6(double&);
void _fun6(double*);

struct Circle {
private:
    int x, y, rad;

public:
    void fun11(int&);
    void _fun11(int*);
    void displayRad();

    Circle(int x, int y, int rad) {
        this->x = x;
        this->y = y;
        this->rad = rad;
    }
};

void fun14(int (&)[3][3]);
void _fun14(int *);