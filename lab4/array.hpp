#pragma once
#include <iostream>
#include <memory>
#include "figure.hpp"
#include "functions.hpp"

template <typename T>
class Array{
    private:
        int _size;
        std::shared_ptr<T[]> _fig;
    public:
        Array(){
            _size = 0;
            _fig = nullptr;
        }

        Array(int size){
            _size = size;
            _fig = std::shared_ptr<T[]>(new T[_size]);
        }

        ~Array(){
            _size = 0;
            _fig = nullptr;
        }

        T &operator[](int i){
            if (i >= _size)
                throw std::invalid_argument("razmer menshe!");
            return _fig[i];
        }

        double area(){
            double res = 0;
            for (int i = 0; i < _size; i++){
                res += (double)_fig[i];
            }
            return res;
        }
};

