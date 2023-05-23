#include <iostream>
#include <vector>
#include "CircularBuffer.h"

int main() {
    CircBuff<int> buff(4);

    buff.push_back(1);
    buff.push_back(2);
    buff.push_back(3);
    buff.push_back(4);
    buff.push_front(-1);
    buff.resize(5);
    buff.push_back(4);

    for(auto &i : buff) {
        cout<<i<<" ";
    }

}