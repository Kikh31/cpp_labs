#include <iostream>
#include "complex.h"
#include "set.h"

int main() {
    ComplexNum num1(3, 4);
    ComplexNum num2(2, 2);
    ComplexNum num3;

    std::cout << "Operator*(double)\n";
    num3 = num2 * 2.1; //неявный вызов
    num3 = num2.operator*(2.1); //явный вызов
    num3.printCplx();

    std::cout << "Operator+(ComplexNum)\n";
    num3 = num1 + num2; //неявный вызов
    num3 = num1.operator+(num2); //явный вызов
    num3.printCplx();

    std::cout << "Operator*(ComplexNum)\n";
    num3 = num1 * num2; //неявный вызов
    num3 = num1.operator*(num2); //явный вызов
    num3.printCplx();

    std::cout << "Operator double()\n";
    double dbl = num1; //неявный вызов
    dbl = num1.operator double(); //явный вызов
    std::cout << dbl << '\n';

    std::cout<<'\n';

    Set set1;
    std::cout << "Operator+=(int)\n";
    set1 += 1;
    set1 += 2;
    set1 += 3;
    set1 += 4;
    set1 += 9;
    set1.printSet();

    Set set2;
    set2 += 1;
    set2 += 2;
    set2 += 3;
    set2 += 4;
    set2 += 5;

    std::cout << "Operator-=(int)\n";
    set1 -= 9;
    set1.printSet();

    std::cout << "Operator!=(Set)\n";
    if(set1 != set2) std::cout<<"Sets aren't equal\n";

    std::cout << "Operator==(Set)\n";
    set1+=5;
    if(set1 == set2) {
        std::cout<<"Sets are equal\n";
        set1-=5;
    }

    std::cout << "Operator+(Set)\n";
    Set set3 = set1 + set2;
    set3.printSet();
}