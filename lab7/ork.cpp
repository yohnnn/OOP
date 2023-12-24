#include "ork.hpp"
#include "knight.hpp"
#include "bear.hpp"

Ork::Ork(int x, int y) : NPC(OrkType, x, y) {}
Ork::Ork(std::istream &is) : NPC(OrkType, is) {}

bool Ork::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Ork>(this,[](Ork*){}));
}

void Ork::print()
{
    std::cout << *this;
}


bool Ork::fight(std::shared_ptr<Ork> other) 
{
    fight_notify(other, false);
    return false;
}

bool Ork::fight(std::shared_ptr<Knight> other) 
{
    fight_notify(other, false);
    return false;
}

bool Ork::fight(std::shared_ptr<Bear> other) 
{
    fight_notify(other, true);
    return false;
}

void Ork::save(std::ostream &os) 
{
    os << OrkType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Ork &ork)
{
    os << "Ork: " << *static_cast<NPC *>(&ork) << std::endl;
    return os;
}