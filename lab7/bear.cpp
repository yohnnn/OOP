#include "bear.hpp"
#include "ork.hpp"
#include "knight.hpp"

Bear::Bear(int x, int y) : NPC(BearType, x, y) {}
Bear::Bear(std::istream &is) : NPC(BearType, is) {}

bool Bear::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Bear>(this,[](Bear*){}));
}

void Bear::print()
{
    std::cout << *this;
}

void Bear::save(std::ostream &os)
{
    os << BearType << std::endl;
    NPC::save(os);
}


bool Bear::fight(std::shared_ptr<Ork> other)
{
    fight_notify(other, false);
    return true;
}

bool Bear::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, true);
    return true;
}

bool Bear::fight(std::shared_ptr<Bear> other)
{
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Bear &bear)
{
    os << "Bear: " << *static_cast<NPC *>(&bear) << std::endl;
    return os;
}