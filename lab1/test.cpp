#include <gtest/gtest.h>
#include "func.hpp"

TEST(a, a){
    EXPECT_EQ(task_1(0, 0), 0);
}
TEST(a, b){
    EXPECT_EQ(task_1(1, 1), 0);
}
TEST(a, c){
    EXPECT_EQ(task_1(5, 6), 29);
}
TEST(a, d){
    EXPECT_EQ(task_1(1, 8), 7);
}
TEST(a, e){
    EXPECT_EQ(task_1(1, 3), 2);
}