#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <memory>
#include "ork.hpp"
#include "knight.hpp"
#include "bear.hpp"
#include "factory.hpp"

TEST(Constructors, Ork) {
    Ork s(0, 0, "erik");
    std::stringstream out;
    s.print(out);
    ASSERT_EQ(out.str(), "Ork erik {0, 0}");
}

TEST(Constructors, Knight) {
    Knight t(1, 1, "Dru");
    std::stringstream out;
    t.print(out);
    ASSERT_EQ(out.str(), "Knight Dru {1, 1}");
}

TEST(Constructors, Bear) {
    Bear e(2, 2, "Dobbi");
    std::stringstream out;
    e.print(out);
    ASSERT_EQ(out.str(), "Bear Dobbi {2, 2}");
}

TEST(Fabric, basic) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Ork", "Name", 0, 0));
    persons.push_back(factory("Knight", "Name", 0, 0));
    persons.push_back(factory("Bear", "Name", 0, 0));

    std::stringstream out;
    for (auto& elem : persons) {
        elem->print(out);
    }
    ASSERT_EQ(out.str(), "Ork Name {0, 0}Knight Name {0, 0}Bear Name {0, 0}");
}

TEST(Fighting, basic) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Ork", "Name", 0, 0));
    persons.push_back(factory("Knight", "Name", 0, 0));
    persons.push_back(factory("Bear", "Name", 0, 0));

    for (auto& defender : persons) {
        for (auto& attacker : persons) {
            defender->accept(attacker.get(), 0);
        }
    }
    for (auto& elem : persons) {
        ASSERT_FALSE(elem->is_alive());
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}