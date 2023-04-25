#pragma once

class Set {
private:
    int *arr;
    int ptr;
    int size;
public:

    Set();

    ~Set();

    int find(int x);

    Set operator+(Set &);

    bool operator==(Set &);

    bool operator!=(Set &);

    Set &operator+=(int);

    Set &operator-=(int);

    void printSet();
};

void insertionSort(int *, int);