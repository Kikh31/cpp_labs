#include "funcs.h"

void fun3(int &x, int &y) {
    if(x > y) x = x % y;
    else if(x < y) y = y % x;
}

void _fun3(int *x, int *y) {
    if(*x > *y) *x = *x % *y;
    else if(*x < *y) *y = *y % *x;
}

void fun6(double &x) {
    int res = (int)x;
    if(x - res < 0.5) x = (double)res;
    else x = (double)res + 1;
}

void _fun6(double *x) {
    int res = (int)(*x);
    if(*x - res < 0.5) *x = (double)res;
    else *x = (double)res + 1;
}

void fun11(Circle& c, int x) {
    c.rad -= x;
}

void _fun11(Circle* c, int x) {
    c->rad -= x;
}

void fun14(int (&m)[3][3]) {
    int x;
    for(int i = 0; i < 3; i++) {
        for(int j = i; j < 3; j++) {
            x = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = x;
        }
    }
}
void _fun14(int *m) {
    int x;
    for(int i = 0; i < 3; i++) {
        for(int j = i; j < 3; j++) {
            x = m[i*3 + j];
            m[i*3 + j] = m[j*3 + i];
            m[j*3 + i] = x;
        }
    }
}