#include "hexagon.hpp"
#include <exception>
#include <vector>

Hexagon::Hexagon(){
    _points.resize(3);
    _middle.first = 0;
    _middle.second = 0;
    _s = 0;
}

Hexagon::Hexagon(std::vector<std::pair<double , double >>& t){
    if (t.size() != 6)
        throw std::invalid_argument("ne shestiugolnik!");
    for (int i = 0; i < 6; i++){
        _points.push_back(t[i]);
        _middle.first += t[i].first;
        _middle.second += t[i].second;
    }
    _middle.first /= 6;
    _middle.second /= 6;
    for(int i = 0; i < 6; i++){
        int j = (i + 1) % 6;
        _s += _points[i].first * _points[j].second - _points[j].first * _points[i].second;
    }
    _s = abs(1/2 * _s);
}

Hexagon::~Hexagon(){}

std::pair<double , double > Hexagon::get_middle() const{
    return _middle;
}

std::vector<std::pair<double , double >> Hexagon::get_points() const{
    return _points;
}

double Hexagon::get_s() const{
    return _s;
}

bool Hexagon::operator==(const Hexagon& other){
    if (_points.size() != other.get_points().size())
        return false;
    bool flag;
    for (int i = 0; i < 6; i++){
        flag = false;
        for (int j = 0; j < 6; j++){
            if (_points[i] == other.get_points()[j])
                flag = true;
        }
        if (flag == false)
            return false;
    }
    return true;
}

Hexagon& Hexagon::operator=(const Hexagon& other){
    _middle = other.get_middle();
    _s = other.get_s();
    _points = other.get_points();

    return *this;
}



Hexagon& Hexagon::operator=(const Hexagon&& other){
    _middle = std::move(other._middle);
    _s = std::move(other._s);
    _points = std::move(other._points);

    return *this;

}

Hexagon::operator double() const{
    return get_s();
}