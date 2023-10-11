#pragma once

#include <iostream>
#include <string>

class Six{
private:
    size_t _size;
    unsigned char *_value;
    void _resize();
public:
    Six();
    Six(const size_t & n, unsigned char t = '0');
    Six(const std::initializer_list< unsigned char> &t);
    Six(const std::string &t);
    Six(const Six& other);
    Six(Six&& other) noexcept; 
    ~Six() noexcept;

    Six operator+(const Six& other);
    Six operator-(const Six& other);
    bool operator>(const Six& other);
    bool operator<(const Six& other);
    bool operator==(const Six& other);
    size_t get_size();
    std::string get_string();

};
