#pragma once
#include "figure.hpp"
#include <iostream>
#include <vector>



class Octagon: public Figure{
    friend std::ostream& operator<<(std::ostream& os, const Octagon& t);
    friend std::istream& operator>>(std::istream& is, Octagon& t);
    public:
        Octagon();
        Octagon(std::vector<std::pair<double , double >>& t);
        virtual ~Octagon();

        std::vector<std::pair<double , double >> get_points() const;
        std::pair<double, double> get_middle() const override;
        double get_s() const override;

        operator double() const override;

        bool operator==(const Octagon& other);
        Octagon& operator=(const Octagon& other);
        Octagon& operator=(const Octagon&& other);
        
    private:
        std::vector<std::pair<double , double >> _points;
        std::pair<double, double> _middle;
        double _s;
};

inline std::istream& operator>>(std::istream& is, Octagon& t){
    std::vector<std::pair<double , double >> points(8);
    for (int i = 0; i < 8; i ++){
        is >> points[i].first >> points[i].second;
    }
    t = Octagon(points);
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Octagon& t){
    std::vector<std::pair<double , double >> points = t.get_points();
    for(int i = 0 ; i < 8; i++){
        os << " x: " << points[i].first << " y: " << points[i].second;
    }
    return os;
}
