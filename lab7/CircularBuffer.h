#pragma once

#include <iostream>
#include <iterator>

using namespace std;

template<typename T>
class CircIterator : public iterator<random_access_iterator_tag, T> {
private:
    T *buffer;
    int capacity;
    int index;
public:
    CircIterator(T *_buffer, int _capacity, int _index) : buffer(_buffer), capacity(_capacity), index(_index) {}

    T &operator*() {
        return buffer[index];
    }

    CircIterator &operator++() {
        index = (index + 1) % capacity;
        return *this;
    }

    CircIterator operator++(int) {
        CircIterator temp(*this);
        ++(*this);
        return temp;
    }

    CircIterator &operator--() {
        index = (index - 1 + capacity) % capacity;
        return *this;
    }

    CircIterator operator--(int) {
        CircIterator temp(*this);
        --(*this);
        return temp;
    }

    CircIterator &operator+=(int n) {
        index = (index + n) % capacity;
        return *this;
    }

    CircIterator &operator-=(int n) {
        index = (index - n + capacity) % capacity;
        return *this;
    }

    CircIterator operator+(int n) const {
        CircIterator temp(*this);
        temp.index = (temp.index + n) % capacity;
        return temp;
    }

    CircIterator operator-(int n) const {
        CircIterator temp(*this);
        temp.index = (temp.index - n + capacity) % capacity;
        return temp;
    }

    ptrdiff_t operator-(const CircIterator &it) const {
        return this->index - it.index;
    }

    bool operator==(const CircIterator &it) const {
        return this->index == it.index;
    }

    bool operator!=(const CircIterator &it) const {
        return !(*this == it);
    }

    bool operator<(const CircIterator &it) {
        return this->index < it.index;
    }

    bool operator>(const CircIterator &it) {
        return this->index > it.index;
    }

    bool operator<=(const CircIterator &it) {
        return !(*this > it);
    }

    bool operator>=(const CircIterator &it) {
        return !(*this < it);
    }
};

template<typename T>
class CircBuff {
private:
    T *buffer;
    int capacity;
    int size;
    int tail, head;
public:
    explicit CircBuff(int _capacity) : capacity(_capacity), size(0), tail(0), head(0) {
        buffer = new T[_capacity];
    }

    ~CircBuff() {
        delete[] buffer;
    }

    int get_capacity() {
        return capacity;
    }

    int get_size() {
        return size;
    }

    bool is_empty() {
        return size == 0;
    }

    bool is_full() {
        return size == capacity;
    }

    void push_back(T value) {
        if (is_full()) {
            pop_front();
        }
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
    }

    void push_front(T value) {
        if (is_full()) {
            pop_back();
        }
        head = (head - 1 + capacity) % capacity;
        buffer[head] = value;
        size++;
    }

    void pop_front() {
        if (is_empty()) {
            cout << "Buffer is empty!"<<'\n';
            return;
        }
        head = (head + 1) % capacity;
        size--;
    }

    void pop_back() {
        if (is_empty()) {
            cout << "Buffer is empty!"<<'\n';
            return;
        }
        tail = (tail - 1 + capacity) % capacity;
        size--;
    }

    void insert(CircIterator<T> it, T val) {
        int index = it - begin();
        (*this)[index] = val;
    }

    void erase(CircIterator<T> it) {
        int index = it - begin();
        (*this)[index] = -INT_MAX;
    }

    T &front() {
        return buffer[head];
    }

    T &back() {
        return buffer[(tail - 1 + capacity) % capacity];
    }

    T &operator[](int i) {
        return buffer[(head + i) % capacity];
    }

    CircIterator<T> begin() {
        return CircIterator(buffer, capacity, head);
    }

    CircIterator<T> end() {
        return begin() + size;
    }

    void resize(int new_capacity) {
        if (new_capacity < get_size()) {
            cout<<"New capacity is less than current size!"<<'\n';
        }
        T* new_buffer = new T[new_capacity];
        for (int i = 0; i < get_size(); i++) {
            new_buffer[i] = (*this)[i];
        }
        delete[] buffer;
        buffer = new_buffer;
        capacity = new_capacity;
        head = 0;
        tail = get_size();
    }

    void print() {
        for(int i = 0; i < get_size(); i++) {
            cout<<(*this)[i]<<" ";
        }
        cout<<'\n';
    }
};