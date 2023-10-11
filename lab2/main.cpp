#include <iostream>
#include "six.hpp"
#include <string>

int main(){
    std::string a, b;
    std::cin >> a >> b;
    Six num1 = Six(a);
    Six num2 = Six(b);
    std::cout << (num1 < num2) << "\n";
    std::cout << (num1 > num2) << "\n";
    std::cout << (num1 == num2) << "\n";
    std::cout << (num1 - num2).get_string() << "\n";
    std::cout << (num1 + num2).get_string() << "\n";
    }