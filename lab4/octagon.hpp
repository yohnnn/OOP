#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "figure.hpp"

template <typename T>
class Octagon : public Figure{
    public:
        int size;
        std::vector < std::pair <T, T>> points;

        Octagon(){
            size=8;
            points={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
        }
        Octagon(std::vector < std::pair <T, T>> &input){
            size = 8;
            points = input;
        }
        ~Octagon(){
            size = 0;
            points = {};
        }

        Octagon<T> &operator=(const Octagon<T> &other);
        Octagon<T> &operator=(Octagon<T> &&other);
        operator double() const override; 
};
template <typename T>
inline std::istream& operator>>(std::istream& is, Octagon<T>& t){
    for (int i = 0; i <= 8; i ++){
        is >> t.points[i].first >> t.points[i].second;
    }
    return is;
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Octagon<T>& t){
    for(int i = 0 ; i < 8; i++){
        os << " x: " << t.points[i].first << " y: " << t.points[i].second;
    }
    return os;
}
template <typename T>
inline bool operator==(const Octagon<T>& one, const Octagon<T>& two){
    if (one.size() != two.size())
        return false;
    bool flag;
    for (int i = 0; i < 8; i++){
        flag = false;
        for (int j = 0; j < 8; j++){
            if (one.points[i] == two.points[j])
                flag = true;
        }
        if (flag == false)
            return false;
    }
    return true;
}
template <typename T>
inline Octagon<T>& Octagon<T>::operator=(const Octagon<T>& other){
    size = other.size;
    points = other.points;

    return *this;
}


template <typename T>
inline Octagon<T>& Octagon<T>::operator=(Octagon<T>&& other){
    size = std::move(other.size);
    points = std::move(other.points);

    return *this;
}

template <typename T>
inline Octagon<T>::operator double() const {
    return get_s<Octagon<T>, T>(*this);
}