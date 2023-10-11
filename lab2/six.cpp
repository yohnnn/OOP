#include "six.hpp"
#include <iostream>
#include <string>
#include <exception>


//resize:

void Six::_resize(){
    unsigned char *resized_value = new unsigned char[_size];
    for (int i = 0; i < _size; i++){
        resized_value[i] = _value[i];
    }
    delete[] _value;
    _value = resized_value;
}

//constructors:

Six::Six(){
    _size = 0;
    _value = nullptr;
}

Six::Six(const size_t & n, unsigned char t){
    if (t < 48 || t > 53)
        throw std::invalid_argument("Ne shesterichnoe chislo!");
    _size = n;
    _value = new unsigned char[n];
    for (int i = 0; i < n; i++)
        _value[i] = t;
}

Six::Six(const std::initializer_list< unsigned char> &t){
    _size = t.size();
    _value = new unsigned char[_size];
    int i = 0;
    for (const unsigned char &el : t){
        if (el < 48 || el > 53)
            throw std::invalid_argument("Ne shesterichnoe chislo!");
        _value[i] = el;
        i++;
    }
}

Six::Six(const std::string &t){
    _size = t.size();
    _value = new unsigned char[_size];
    for (int i = 0; i < _size; i++){
        if (t[i] < 48 || t[i] > 53)
            throw std::invalid_argument("Ne shesterichnoe chislo!");
        _value[i] = t[i];
    }
}

Six::Six(const Six &other){
    _size = other._size;
    _value = new unsigned char[_size];
    for (int i = 0; i < _size; i++)
        _value[i] = other._value[i];
}

Six::Six(Six &&other) noexcept {
    _size = other._size;
    _value = other._value;
    
    other._value = nullptr;
    other._size = 0;
}

Six::~Six() noexcept{
    delete[] _value;
    _size = 0;
    _value = nullptr;
}

//getters:

size_t Six::get_size(){
    return _size;
}

std::string Six::get_string(){
    std::string res = "";
    for (int i = 0; i < _size; i++)
        res += _value[i];
    return res;
}

//operators:

bool Six::operator==(const Six &other){
    if (_size != other._size)
        return false;
    for(int i = 0; i < _size; i++){
        if (_value[i] != other._value[i])
            return false;
    }
    return true;
}

bool Six::operator>(const Six &other){
    if (_size > other._size)
        return true;
    if (_size < other._size)
        return false;
    for (int i = _size - 1; i >= 0; i--){
        if (_value[i] < other._value[i])
            return false;
    }
    return true;
}

bool Six::operator<(const Six &other){
    if (_size < other._size)
        return true;
    if (_size > other._size)
        return false;
    for (int i = _size - 1; i >= 0; i--){
        if (_value[i] > other._value[i])
            return false;
    }
    return true;
}

Six Six::operator+(const Six &other){
    int number1, number2, sum, x = 0, number; 
    char biggest;
    size_t maxsize = std::max(_size, other._size);
    size_t minsize = std::min(_size, other._size);
    if (maxsize == _size) biggest = 'a';
    else biggest = 'b';
    Six res = Six(maxsize);
    for (int i = 0; i < minsize; i++){
        number1 = _value[i] - 48;
        number2 = other._value[i] - 48;
        sum = number1 + number2 + x;
        x = sum / 6;
        res._value[i] = (sum % 6) + 48;
    }
    for (int i = minsize; i < maxsize; i++){
        if (biggest == 'a')
            number = _value[i] - 48;
        else
            number = other._value[i] - 48;
        sum = number + x;
        x = sum / 6;
        res._value[i] = (sum % 6) + 48;
    }
    if (x != 0){
        ++res._size;
        res._resize();
        res._value[maxsize] = x + 48;
    }
    return res;
}

Six Six::operator-(const Six &other){
    if (_size < other._size)
        throw std::invalid_argument("Vtoroe chislo bolshe");
    int number1, number2, raz, x = 0, number; 
    char biggest;
    size_t maxsize = std::max(_size, other._size);
    size_t minsize = std::min(_size, other._size);
    if (maxsize == _size) biggest = 'a';
    else biggest = 'b';
    Six res = Six(maxsize);
    for (int i = 0; i < minsize; i++){
        number1 = _value[i] - 48;
        number2 = other._value[i] - 48;
        raz = number1 - number2 - x;
        if (raz < 0){
            res._value[i] = raz + 6 + 48;
            x = 1;
        }
        else{
            res._value[i] = raz + 48;
            x = 0;
        }
    }
    for (int i = minsize; i < maxsize; i++){
        if (biggest = 'a')
            number = _value[i] - 48;
        else
            number = other._value[i] - 48;
        raz = number - x;
        if (raz < 0){
            res._value[i] = raz + 6 + 48;
            x = 1;
        }
        else{
            res._value[i] = raz + 48;
            x = 0;
        }       
    }
    for (int i = maxsize - 1; i >= 0; i--){
        if (res._value[i] != '0')
            break;
        res._size--;
    }
    res._resize();
    return res;
}

