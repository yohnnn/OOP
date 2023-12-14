#pragma once
#include "figure.hpp"
#include <iostream>
#include <vector>



class Triangle : public Figure{
    friend std::ostream& operator<<(std::ostream& os, const Triangle& t);
    friend std::istream& operator>>(std::istream& is, Triangle& t);
    public:
        Triangle();
        Triangle(std::vector<std::pair<double , double >>& t);
        virtual ~Triangle();

        std::vector<std::pair<double , double >> get_points() const;
        std::pair<double, double> get_middle() const override;
        double get_s() const override;

        operator double() const override;

        bool operator==(const Triangle& other);
        Triangle& operator=(const Triangle& other);
        Triangle& operator=(const Triangle&& other);
        
    private:
        std::vector<std::pair<double , double >> _points;
        std::pair<double, double> _middle;
        double _s;
};

inline std::istream& operator>>(std::istream& is, Triangle& t){
    std::vector<std::pair<double , double >> points(3);
    for (int i = 0; i < 3; i ++){
        is >> points[i].first >> points[i].second;
    }
    t = Triangle(points);
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Triangle& t){
    std::vector<std::pair<double , double >> points = t.get_points();
    for(int i = 0 ; i < 3; i++){
        os << " x: " << points[i].first << " y: " << points[i].second;
    }
    return os;
}
