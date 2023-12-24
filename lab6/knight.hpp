#pragma once
#include "npc.hpp"

class Knight : public NPC{
    public:
        Knight(const int&, const int&, const std::string&);

        void print(std::ostream&) override;

        void accept(NPC*, const int&) override;

        friend std::ostream& operator<<(std::ostream&, const Knight&);

};