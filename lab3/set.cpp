#include "set.h"
#include <iostream>


Set::Set() {
    arr = new int[10];
    ptr = -1;
    this->size = 0;
}

Set::~Set() {
    delete[] arr;
}

void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            std::swap(arr[j - 1], arr[j]);
        }
    }
}

int Set::find(int x) {
    if (size == 0) return -1;

    int res = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) res = i;
    }

    return res;
}

Set &Set::operator+=(int x) {
    if (size < 10 && find(x) == -1 && (0 <= x && x <= 9)) {
        ptr++;
        size++;
        arr[ptr] = x;
        insertionSort(arr, size);
    }

    return *this;
}

Set &Set::operator-=(int x) {
    int x_pos = find(x);

    if (size > 0 && x_pos != -1 && (0 <= x && x <= 9)) {
        for (int i = x_pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        ptr--;
        size--;
    }

    return *this;
}

Set Set::operator+(Set &s) {
    int uniq = 0;
    for (int i = 0; i < s.size; i++) {
        if (find(s.arr[i]) == -1) uniq++;
    }
    int new_size = size + uniq;
    int *new_arr = new int[10];

    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    int iter = -1;
    for (int i = 0; i < s.size; i++) {
        if (find(s.arr[i]) == -1) {
            iter++;
            new_arr[size + iter] = s.arr[i];
        }
    }

    insertionSort(new_arr, new_size);
    Set new_set;
    new_set.arr = new_arr;
    delete[] new_arr;
    new_set.size = new_size;
    new_set.ptr = new_size - 1;

    return new_set;
}

bool Set::operator==(Set &s) {
    if (size != s.size) return false;

    for (int i = 0; i < size; i++) {
        if (arr[i] != s.arr[i]) return false;
    }

    return true;
}

bool Set::operator!=(Set &s) {
    if (size != s.size) return true;

    for (int i = 0; i < size; i++) {
        if (arr[i] != s.arr[i]) return true;
    }

    return false;
}

void Set::printSet() {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}


