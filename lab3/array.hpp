#pragma once
#include "figure.hpp"


class Array{
    private:
        int _size;
        Figure** _fig;
    public:
        Array();
        Array(int size);
        virtual ~Array();
        void delete_fig(int i);
        void add_fig(int i, Figure* f);
        double area();
        Figure* operator[](int i) const;
};