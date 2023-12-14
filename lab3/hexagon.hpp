#pragma once
#include "figure.hpp"
#include <iostream>
#include <vector>



class Hexagon: public Figure{
    friend std::ostream& operator<<(std::ostream& os, const Hexagon& t);
    friend std::istream& operator>>(std::istream& is, Hexagon& t);
    public:
        Hexagon();
        Hexagon(std::vector<std::pair<double , double >>& t);
        virtual ~Hexagon();

        std::vector<std::pair<double , double >> get_points() const;
        std::pair<double, double> get_middle() const override;
        double get_s() const override;

        operator double() const override;

        bool operator==(const Hexagon& other);
        Hexagon& operator=(const Hexagon& other);
        Hexagon& operator=(const Hexagon&& other);
        
    private:
        std::vector<std::pair<double , double >> _points;
        std::pair<double, double> _middle;
        double _s;
};

inline std::istream& operator>>(std::istream& is, Hexagon& t){
    std::vector<std::pair<double , double >> points(6);
    for (int i = 0; i < 6; i ++){
        is >> points[i].first >> points[i].second;
    }
    t = Hexagon(points);
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Hexagon& t){
    std::vector<std::pair<double , double >> points = t.get_points();
    for(int i = 0 ; i < 6; i++){
        os << " x: " << points[i].first << " y: " << points[i].second;
    }
    return os;
}
