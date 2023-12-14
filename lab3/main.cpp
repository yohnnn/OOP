#include "array.hpp"
#include "triangle.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "figure.hpp"
#include <iostream>


int main(){
    Triangle tr1;
    Octagon oct1;
    Hexagon hex1;
    std::cout << "input triangle: ";
    std::cin >> tr1;
    std::cout << "input octagon: ";
    std::cin >> oct1;
    std::cout << "input hexagon: ";
    std::cin >> hex1;

    std::cout << "triangle: \n";
    std::cout << tr1 << "\n";
    std::cout << tr1.get_middle().first << " " << tr1.get_middle().second << "\n";
    std::cout << tr1.get_s() << "\n";

    std::cout << "octagon: \n";
    std::cout << oct1 << "\n";
    std::cout << oct1.get_middle().first << " " << oct1.get_middle().second << "\n";
    std::cout << oct1.get_s() << "\n";

    std::cout << "hexagon: \n";
    std::cout << hex1 << "\n";
    std::cout << hex1.get_middle().first << " " << hex1.get_middle().second << "\n";
    std::cout << hex1.get_s() << "\n";

}