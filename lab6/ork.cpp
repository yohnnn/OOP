#include "bear.hpp"
#include "ork.hpp"
#include "knight.hpp"
#include <algorithm>

Ork::Ork(const int& _x, const int& _y, const std::string& _name) {
    x = _x;
    y = _y;
    name = _name;
    alive = true;
}

void Ork::print(std::ostream& out) {
    out << *this;
}

void Ork::accept(NPC* attacker, const int& distance) {
    if (alive && dynamic_cast<Knight*>(attacker) && attacker != this) {
        bool win = is_close(*attacker, distance);
        if (win) 
            alive = false;
        notify(attacker, win);
    }
}

std::ostream& operator<<(std::ostream& out, const Ork& other) {
    return out << "Ork " << other.name << " {" << other.x << ", " << other.y << '}';
}