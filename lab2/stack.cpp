#include "stack.h"
#include "iostream"

Stack::Stack(int maxSize) {
    arr = new int[maxSize];
    this->maxSize = maxSize;
    size = 0;
    top = -1;
}

Stack::Stack(const Stack &st) {
    arr = st.arr;
    maxSize = st.maxSize;
    size = st.size;
    top = st.top;
}

void Stack::push(int x) {
    if(size == maxSize) {
        throw "Stack is full\n";
    }

    top++;
    size++;
    arr[top] = x;
}

int Stack::pop() {
    if(isEmpty()) {
        throw "Stack is empty\n";
    }

    int buff = arr[top];
    top--;
    size--;
    return buff;
}

int Stack::lenght() {
    return size;
}

bool Stack::isEmpty() {
    return size == 0;
}

int Stack::getTop() {
    if(isEmpty()) {
        throw "Stack is empty\n";
    }

    return arr[top];
}

void Stack::printStack() {
    if(isEmpty()) {
        throw "Stack is empty\n";
    }

    for(int i = top; i >= 0; i--) {
        std::cout<<arr[i]<<" ";
    }
}