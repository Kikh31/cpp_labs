#include <iostream>
#include <vector>
#include "CircularBuffer.h"

int main() {
    CircBuff<int> buff(4);

    cout << "push_front() & pop_front test:\n";
    buff.push_front(0);
    buff.push_front(-1);
    buff.push_front(-2);
    buff.push_front(-3);
    cout << "{0, -1, -2, -3} pushed in front: ";
    buff.print();
    buff.pop_front();
    cout << "front popped: ";
    buff.print();

    cout << '\n';

    cout << "push_back() & pop_back test:\n";
    buff.push_back(1);
    buff.push_back(2);
    cout << "{1,2} pushed: ";
    buff.print();
    buff.pop_back();
    cout << "back popped: ";
    buff.print();

    cout << '\n';

    cout << "insert() & erase() test:\n";
    buff.insert(buff.begin(), 0);
    cout<<"Insert 0 in [0]: ";
    buff.print();
    buff.insert(buff.begin() + 1, 1);
    cout<<"Insert 1 in [1]: ";
    buff.print();
    buff.insert(buff.begin() + 2, 2);
    cout<<"Insert 2 in [2]: ";
    buff.print();
    buff.erase(buff.begin() + 1);
    cout<<"Erase [1]: ";
    buff.print();

    cout << '\n';

    cout << "begin(), end(), front(), back() test:\n";
    cout<<"begin() & end() iterators: ";
    cout<<*(buff.begin())<<" "<<*(buff.end() - 1)<<'\n';
    cout<<"front() & back() ";
    cout<<buff.front()<<" "<<buff.back()<<'\n';

    cout<<'\n';

    cout << "indexation test:\n";
    printf("[0] - %d\n", buff[0]);
    printf("[1] - %d\n", buff[1]);
    printf("[2] - %d\n", buff[2]);

    cout<<'\n';

    cout << "resize test:\n";
    printf("Capacity = %d\t", buff.get_capacity());
    buff.print();
    cout<<"Resizing...\n";
    buff.resize(5);
    printf("Capacity = %d\t", buff.get_capacity());
    buff.print();
    buff.push_back(3);
    buff.push_back(4);
    buff.push_back(5);
    buff.push_back(6);
    buff.print();
}