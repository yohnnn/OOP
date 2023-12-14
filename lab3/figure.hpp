#pragma once
#include <iostream>

class Figure{
    public:
        Figure() = default;
        virtual ~Figure() = default;

        virtual std::pair<double, double> get_middle() const = 0;
        virtual double get_s() const = 0;

        virtual explicit operator double() const = 0;

};