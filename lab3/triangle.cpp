#include "triangle.hpp"
#include <exception>
#include <vector>

Triangle::Triangle(){
    _points.resize(3);
    _middle.first = 0;
    _middle.second = 0;
    _s = 0;
}

Triangle::Triangle(std::vector<std::pair<double , double >>& t){
    if (t.size() != 3)
        throw std::invalid_argument("ne treugolnik!");
    for (int i = 0; i < 3; i++){
        _points.push_back(t[i]);
        _middle.first += t[i].first;
        _middle.second += t[i].second;
    }
    _middle.first /= 3;
    _middle.second /= 3;
    double x1 = _points[0].first;
    double x2 = _points[1].first;
    double x3 = _points[2].first;
    double y1 = _points[0].second;
    double y2 = _points[1].second;
    double y3 = _points[2].second;
    _s = abs(1/2 * ((x1 - x3) * (y2 - y3) - (y1 - y3) * (x2 - x3)));
}

Triangle::~Triangle(){}

std::pair<double , double > Triangle::get_middle() const{
    return _middle;
}

std::vector<std::pair<double , double >> Triangle::get_points() const{
    return _points;
}

double Triangle::get_s() const{
    return _s;
}

bool Triangle::operator==(const Triangle& other){
    if (_points.size() != other.get_points().size())
        return false;
    bool flag;
    for (int i = 0; i < 3; i++){
        flag = false;
        for (int j = 0; j < 3; j++){
            if (_points[i] == other.get_points()[j])
                flag = true;
        }
        if (flag == false)
            return false;
    }
    return true;
}

Triangle& Triangle::operator=(const Triangle& other){
    _middle = other.get_middle();
    _s = other.get_s();
    _points = other.get_points();

    return *this;
}



Triangle& Triangle::operator=(const Triangle&& other){
    _middle = std::move(other._middle);
    _s = std::move(other._s);
    _points = std::move(other._points);

    return *this;

}

Triangle::operator double() const{
    return get_s();
}