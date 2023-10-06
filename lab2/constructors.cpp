#include <six.hpp>
#include <exception>

Six::Six(){
    _size = 0;
    _value = nullptr;
}

Six::Six(const size_t & n, unsigned char t){
    if (t < 48 && t > 53)
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
        if (el < 48 && el > 53)
            throw std::invalid_argument("Ne shesterichnoe chislo!");
        _value[i] = el;
        i++;
    }
}

Six::Six(const std::string &t){
    _size = t.size();
    _value = new unsigned char[_size];
    for (int i = 0; i < _size; i++){
        if (t[i] < 48 && t[i] > 53)
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
    _value = new unsigned char[_size];
    for (int i = 0; i < _size; i++)
        _value[i] = other._value[i];
    delete other._value;
    other._size = 0;
}

Six::~Six() noexcept{
    delete _value;
    _size = 0;
}
