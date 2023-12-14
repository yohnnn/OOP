#include "array.hpp"
#include <exception>



Array::Array(){
    _size = 1000;
    _fig = new Figure*[_size];
    for (int i = 0; i < _size; i++){
        _fig[i] = nullptr;
    }
}

Array::Array(int size){
    _size = size;
    _fig = new Figure*[_size];
    for (int i = 0; i < _size; i++){
        _fig[i] = nullptr;
    }    
}

Array::~Array(){
    delete[] _fig;
    _fig = nullptr;
    _size = 0;
}

Figure* Array::operator[](int i) const{
    if (i >= _size)
        throw std::invalid_argument("razmer menshe!");
    return _fig[i];
}

void Array::delete_fig(int i){
    if (i >= _size)
        throw std::invalid_argument("razmer menshe!");
    delete _fig[i];
    _fig[i] = nullptr;
}

void Array::add_fig(int i, Figure* f){
    if (i >= _size)
        throw std::invalid_argument("razmer menshe!");
    delete _fig[i];
    _fig[i] = f;
}

double Array::area(){
    double res = 0;
    for (int i = 0; i < _size; i++){
        if (_fig[i] != nullptr)
            res += (double)*_fig[i];
    }
    return res;
}

