#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
    cout << "Func 3:\n";
    int a = 4, b = 2;
    cout << "Refs:\n";
    cout << a << " " << b << '\n';
    fun3(a, b);
    cout << a << " " << b << '\n';
    a = 4, b = 2;
    cout << "Pointers:\n";
    cout << a << " " << b << '\n';
    _fun3(&a, &b);
    cout << a << " " << b << '\n';

    cout << "Func 6:\n";
    double c = 5.5;
    cout << "Refs:\n";
    cout << c << '\n';
    fun6(c);
    cout << c << '\n';
    c = 5.5;
    cout << "Pointers:\n";
    cout << c << '\n';
    _fun6(&c);
    cout << c << '\n';

    cout << "Func 11:\n";
    Circle circ1(0, 0, 5);
    int decr = 2;
    cout << "Refs:\n";
    circ1.displayRad();
    circ1.fun11(decr);
    circ1.displayRad();
    Circle circ2(0, 0, 5);
    cout << "Pointers:\n";
    circ2.displayRad();
    circ2._fun11(&decr);
    circ2.displayRad();

    cout << "Func 14:\n";
    int m0[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    cout << "Refs:\n";
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout<<m0[i][j]<<" ";
        cout<<'\n';
    }
    fun14(m0);
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout<<m0[i][j]<<" ";
        cout<<'\n';
    }
    int m1[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    cout << "Pointers:\n";
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout<<m1[i][j]<<" ";
        cout<<'\n';
    }
    _fun14(m1[0]);
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout<<m1[i][j]<<" ";
        cout<<'\n';
    }
}
