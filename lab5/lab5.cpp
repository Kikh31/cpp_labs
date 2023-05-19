#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout<<"Swap test:\n";
    int x = 1, y = 2;
    printf("int x = %d, int y = %d\n", x, y);
    MySwap(x, y);
    printf("Swaped!\nint x = %d, int y = %d\n", x, y);

    cout<<"\nStack(3 elems) and Exception test:\n";
    Stack<3, int> stack;
    int a = 1, b = 2, c = 3, d = 4;
    try {
        stack.push(a);
        cout << "Number " << a << " pushed\n";
        stack.push(b);
        cout << "Number " << b << " pushed\n";
        stack.push(c);
        cout << "Number " << c << " pushed\n";
        cout<<"Try to push 4th element...\n";
        stack.push(d);
    } catch (Exception& ex) {
        cout << ex.what();
    }
}
