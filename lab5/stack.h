#pragma once
#include <iostream>

using std::string;

class Exception : public std::exception {
private:
    string errMsg;
public:
    Exception(string errMsg) {
        this->errMsg = std::move(errMsg);
    };

    const char * what() const noexcept override {
        return errMsg.c_str();
    };
};

template<int N, typename T>
class Stack {
private:
    T *arr;
    int maxSize{};
    int size;
    T top;

public:
    Stack() {
        arr = new int[N];
        maxSize = N;
        size = 0;
        top = -1;
    };

    void push(T x) {
        if(size == maxSize) {
            throw Exception("Stack is full\n");
        }

        top++;
        size++;
        arr[top] = x;
    };

    T pop() {
        if(isEmpty()) {
            throw Exception("Stack is empty\n");
        }

        T buff = arr[top];
        top--;
        size--;
        return buff;
    };

    int lenght() {
        return size;
    };

    bool isEmpty() {
        return size == 0;
    };

    T getTop() {
        if(isEmpty()) {
            throw Exception("Stack is empty\n");
        }

        return arr[top];
    }

    void printStack() {
        if(isEmpty()) {
            throw Exception("Stack is empty\n");
        }

        for(int i = top; i >= 0; i--) {
            std::cout<<arr[i]<<" ";
        }
    }
};

template<typename T>
void MySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

