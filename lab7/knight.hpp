#pragma once
#include "npc.hpp"

struct Knight : public NPC
{
    Knight(int x, int y);
    Knight(std::istream &is);

    void print() override;

    bool fight(std::shared_ptr<Ork> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Bear> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};