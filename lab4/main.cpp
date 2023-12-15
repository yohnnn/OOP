#include <iostream>
#include <vector>
#include <cmath>
#include "array.hpp"
#include "figure.hpp"
#include "functions.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "triangle.hpp"

int main(){
    std::vector<std::pair<double,double>> points_3={{2.0,2.0},{4.0,4.0},{5.0,5.0}};
    Triangle<double> Tria(points_3);


    std::vector<std::pair<double, double>> points_6 = {{2.0, 2.0}, {4.0, 4.0}, {6.0, 6.0}, {4.0, 4.0}, {2.0, 2.0}, {4.0, 4.0}};
    std::vector<std::pair<double, double>> points_8 = {{2.0, 2.0}, {4.0, 4.0}, {5.0, 5.0}, {6.0, 6.0}, {2.0, 2.0}, {4.0, 4.0}, {6.0, 6.0}, {4.0, 4.0}};
    Hexagon<double> Hex(points_6);
    Octagon<double> Octa(points_8);

    std::cout<<(double)Tria<<std::endl<<(double)Octa<<std::endl<<(double)Hex<<std::endl;
    return 0;
}