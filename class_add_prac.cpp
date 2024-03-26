#include <iostream>
using namespace std;

class Number {
public:
    int num1;
    int num2;
};

int main() {
    Number numInst1;
    Number numInst2;

    numInst1.num1 = 10;
    numInst1.num2 = 20;

    numInst2.num1 = 30;
    numInst2.num2 = 40;

    std::cout << "Address of numInst1: " << &numInst1 << std::endl;
    std::cout << "Address of numInst1.num1: " << &(numInst1.num1) << std::endl;
    std::cout << "Address of numInst1.num2: " << &(numInst1.num2) << std::endl;

    std::cout << "Address of numInst2: " << &numInst2 << std::endl;
    std::cout << "Address of numInst2.num1: " << &(numInst2.num1) << std::endl;
    std::cout << "Address of numInst2.num2: " << &(numInst2.num2) << std::endl;

    string s1, s2;
    s1 = "hello ";
    s2 = "world!";
    cout << s1+s2;

    pair <int, char> p;
    return 0;
}