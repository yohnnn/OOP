#include <gtest/gtest.h>
#include <memory>
#include "npc.hpp"
#include "knight.hpp"
#include "ork.hpp"
#include "bear.hpp"

TEST(test_01, Bear_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_02, Bear_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x, y);
    EXPECT_EQ(BearType,a->get_type());
}

TEST(test_03, Bear_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x, y);
    EXPECT_TRUE(a->is_alive());
}



TEST(test_04, Ork_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Ork>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_05, Ork_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Ork>(x, y);
    EXPECT_EQ(OrkType,a->get_type());
}

TEST(test_06, Ork_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Ork>(x, y);
    EXPECT_TRUE(a->is_alive());
}


TEST(test_07, Ork_constructor){
    int x{10};
    int y{10};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Ork>(x, y);

    a->move(50,50,100,100);
    EXPECT_EQ((a->position()).first,60);
}


TEST(test_08, Knight_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);

    EXPECT_EQ((a->position()).second,100);
}

TEST(test_09, Knight_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);
    EXPECT_EQ(KnightType,a->get_type());
}

TEST(test_10, Knight_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);
    EXPECT_TRUE(a->is_alive());
}