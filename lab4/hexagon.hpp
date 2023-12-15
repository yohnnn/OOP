#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "figure.hpp"

template <typename T>
class Hexagon : public Figure{
    public:
        int size;
        std::vector < std::pair <T, T>> points;

        Hexagon(){
            size=6;
            points={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
        }
        Hexagon(std::vector < std::pair <T, T>> &input){
            size = 6;
            points = input;
        }
        ~Hexagon(){
            size = 0;
            points = {};
        }

        Hexagon<T> &operator=(const Hexagon<T> &other);
        Hexagon<T> &operator=(Hexagon<T> &&other);
        operator double() const override; 
};
template <typename T>
inline std::istream& operator>>(std::istream& is, Hexagon<T>& t){
    for (int i = 0; i <= 6; i ++){
        is >> t.points[i].first >> t.points[i].second;
    }
    return is;
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Hexagon<T>& t){
    for(int i = 0 ; i < 6; i++){
        os << " x: " << t.points[i].first << " y: " << t.points[i].second;
    }
    return os;
}
template <typename T>
inline bool operator==(const Hexagon<T>& one, const Hexagon<T>& two){
    if (one.size() != two.size())
        return false;
    bool flag;
    for (int i = 0; i < 6; i++){
        flag = false;
        for (int j = 0; j < 6; j++){
            if (one.points[i] == two.points[j])
                flag = true;
        }
        if (flag == false)
            return false;
    }
    return true;
}
template <typename T>
inline Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& other){
    size = other.size;
    points = other.points;

    return *this;
}


template <typename T>
inline Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& other){
    size = std::move(other.size);
    points = std::move(other.points);

    return *this;
}

template <typename T>
inline Hexagon<T>::operator double() const {
    return get_s<Hexagon<T>, T>(*this);
}