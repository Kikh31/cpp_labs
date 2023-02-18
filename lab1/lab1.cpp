#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "‘унци€ є3:\n";
    int a = 4, b = 2;
    cout << "—сылки:\n";
    cout << a << " " << b << '\n';
    fun3(a, b);
    cout << a << " " << b << '\n';
    a = 4, b = 2;
    cout << "”казатели:\n";
    cout << a << " " << b << '\n';
    _fun3(&a, &b);
    cout << a << " " << b << '\n';

    cout << "‘унци€ є6:\n";
    double c = 5.5;
    cout << "—сылки:\n";
    cout << c << '\n';
    fun6(c);
    cout << c << '\n';
    c = 5.5;
    cout << "”казатели:\n";
    cout << c << '\n';
    _fun6(&c);
    cout << c << '\n';

    cout << "‘унци€ є11:\n";
    Circle circ(0, 0, 5);
    cout << "—сылки:\n";
    cout << circ.rad << '\n';
    fun11(circ, 2);
    cout << circ.rad << '\n';
    circ.rad = 5;
    cout << "”казатели:\n";
    cout << circ.rad << '\n';
    _fun11(&circ, 2);
    cout << circ.rad << '\n';

    cout << "‘унци€ є14:\n";
    /*int **m = new int*[3];
    for(int i = 0; i < 3; i++) m[i] = new int[3];
    int p = 1;
    for(int i = 0; i<3; i++) {
        for(int j = 0; j <3; j++) {
            m[i][j] = p++;
        }
    }*/
    int m0[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    cout << "—сылки:\n";
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
    cout << "”казатели:\n";
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
