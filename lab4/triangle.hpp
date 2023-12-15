#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "figure.hpp"

template <typename T>
class Triangle : public Figure{
    public:
        int size;
        std::vector < std::pair <T, T>> points;

        Triangle(){
            size=3;
            points={{0,0},{0,0},{0,0}};
        }
        Triangle(std::vector < std::pair <T, T>> &input){
            size = 3;
            points = input;
        }
        ~Triangle(){
            size = 0;
            points = {};
        }

        Triangle<T> &operator=(const Triangle<T> &other);
        Triangle<T> &operator=(Triangle<T> &&other);
        operator double() const override; 
};
template <typename T>
inline std::istream& operator>>(std::istream& is, Triangle<T>& t){
    std::vector<std::pair<double , double >> points(3);
    for (int i = 0; i < 3; i ++){
        is >> t.points[i].first >> t.points[i].second;
    }
    return is;
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Triangle<T>& t){
    for(int i = 0 ; i < 3; i++){
        os << " x: " << t.points[i].first << " y: " << t.points[i].second;
    }
    return os;
}
template <typename T>
inline bool operator==(const Triangle<T>& one, const Triangle<T>& two){
    if (one.size() != two.size())
        return false;
    bool flag;
    for (int i = 0; i < 3; i++){
        flag = false;
        for (int j = 0; j < 3; j++){
            if (one.points[i] == two.points[j])
                flag = true;
        }
        if (flag == false)
            return false;
    }
    return true;
}
template <typename T>
inline Triangle<T>& Triangle<T>::operator=(const Triangle<T>& other){
    size = other.size;
    points = other.points;

    return *this;
}


template <typename T>
inline Triangle<T>& Triangle<T>::operator=(Triangle<T>&& other){
    size = std::move(other.size);
    points = std::move(other.points);

    return *this;
}

template <typename T>
inline Triangle<T>::operator double() const {
    return get_s<Triangle<T>, T>(*this);
}