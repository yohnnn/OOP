#include "octagon.hpp"
#include <exception>
#include <vector>

Octagon::Octagon(){
    _points.resize(3);
    _middle.first = 0;
    _middle.second = 0;
    _s = 0;
}

Octagon::Octagon(std::vector<std::pair<double , double >>& t){
    if (t.size() != 8)
        throw std::invalid_argument("ne shestiugolnik!");
    for (int i = 0; i < 8; i++){
        _points.push_back(t[i]);
        _middle.first += t[i].first;
        _middle.second += t[i].second;
    }
    _middle.first /= 8;
    _middle.second /= 8;
    for(int i = 0; i < 8; i++){
        int j = (i + 1) % 8;
        _s += _points[i].first * _points[j].second - _points[j].first * _points[i].second;
    }
    _s = abs(1/2 * _s);
}

Octagon::~Octagon(){}

std::pair<double , double > Octagon::get_middle() const{
    return _middle;
}

std::vector<std::pair<double , double >> Octagon::get_points() const{
    return _points;
}

double Octagon::get_s() const{
    return _s;
}

bool Octagon::operator==(const Octagon& other){
    if (_points.size() != other.get_points().size())
        return false;
    bool flag;
    for (int i = 0; i < 8; i++){
        flag = false;
        for (int j = 0; j < 8; j++){
            if (_points[i] == other.get_points()[j])
                flag = true;
        }
        if (flag == false)
            return false;
    }
    return true;
}

Octagon& Octagon::operator=(const Octagon& other){
    _middle = other.get_middle();
    _s = other.get_s();
    _points = other.get_points();

    return *this;
}



Octagon& Octagon::operator=(const Octagon&& other){
    _middle = std::move(other._middle);
    _s = std::move(other._s);
    _points = std::move(other._points);

    return *this;

}

Octagon::operator double() const{
    return get_s();
}