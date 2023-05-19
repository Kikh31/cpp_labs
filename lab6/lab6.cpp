#include <iostream>
#include <vector>
#include "MyFuncs.h"

using namespace std;

template<class T>
class CPair {
private:
    T first;
    T second;
public:
    CPair(T _first, T _second) : first(_first), second(_second) {}

    bool operator > (const T &x) const {
        return first > x && second > x;
    }
};

int main() {
    vector<int> vector1{-1, -2, -3, 4, -5};
    vector<double> vector2{1.2, 2.3, 3.3, 4.5, 5.6, -6.7, -7.8, -8.9};
    vector<int> vector3{1, -2, 3, -4, 5};
    vector<CPair<int>> vector4 {{-1,-2}, {3, 4}, {-5, 6}};

    cout << "any_of test: ";
    cout << boolalpha << my_any_of(vector1.begin(), vector1.end(), positive<int>) << '\n';

    cout << "is_partitioned test: ";
    cout << boolalpha << my_is_partitioned(vector2.begin(), vector2.end(), positive<double>) << '\n';

    cout << "is_palindrome test: ";
    cout << boolalpha << my_is_palindrome(vector3.begin(), vector3.end(), positive<int>) << '\n';

    cout << "any_of test(with my class): ";
    cout << boolalpha << my_any_of(vector4.begin(), vector4.end(), positive<CPair<int>>) << '\n';

}