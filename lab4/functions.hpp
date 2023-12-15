#pragma once


template <typename C, typename T>
std::pair<T, T> get_middle(C &f){
    int size = f.size;
    std::pair<T, T> mid = {0, 0};
    
    for (int i = 0; i < size; i++){
        mid.first += f.points[i].first;
        mid.second += f.points[i].second;
    }
    mid.first /= size;
    mid.second /= size;
    return mid;
}

template <typename C, typename T>
T get_s(const C &f){
    T s = 0.0;
    for(int i = 0; i < f.size; i++){
        int j = (i + 1) % f.size;
        s += f.points[i].first * f.points[j].second - f.points[j].first * f.points[i].second;
    }
    return abs(1.0/2.0* s);
}