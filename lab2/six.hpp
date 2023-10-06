#pragma once

#include <iostream>
#include <string>

class Six{
private:
    size_t _size;
    unsigned char *_value;
public:
    Six();
    Six(const size_t & n, unsigned char t = 0);
    Six(const std::initializer_list< unsigned char> &t);
    Six(const std::string &t);
    Six(const Six& other);
    Six(Six&& other) noexcept; 
    virtual ~Six() noexcept;

    Six operator+(const Six& other);
    Six operator-(const Six& other);
    Six operator=(const Six& other);
    bool operator>(const Six& other);
    bool operator<(const Six& other);
    bool operator==(const Six& other);
    int get_size();
    unsigned char* get_value();

};
