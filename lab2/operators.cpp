#include <six.hpp>
#include <algorithm>

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
    size_t maxsize = std::max(_size, other._size);
    size_t minsize = std::max(_size, other._size);
    Six res = Six(maxsize);
    int number1, number2, sum, x = 0;
    for (int i = 0; i < maxsize; i++){
        number1 = _value[i] - 48;
        number1 = other._value[i] - 48;
        sum = number1 + number2 + x;
        if (sum > 5){
            res._value[i] = (sum % 6) + 48;
            x = 1;
        }
        else
            res._value[i] = sum + 48;
    }
}