#include "func.hpp"

int task_1(int a, int b){
    if (a == 0 || b == 0){
        return 0;
    }
    return a * b - 1;
}