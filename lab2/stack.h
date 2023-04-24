#pragma once

class Stack {
private:
    int *arr;
    int maxSize;
    int size;
    int top;

public:
    Stack(int);
    Stack(const Stack&);

    void push(int);
    int pop();
    int lenght();
    bool isEmpty();
    int getTop();
    void printStack();
};
