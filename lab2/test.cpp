#include <gtest/gtest.h>
#include "six.hpp"

TEST(test1, default_){
    Six val = Six();
    ASSERT_EQ(val.get_size(), 0);
    ASSERT_EQ(val.get_string(), "");
}
TEST(test1, t_n){
    Six val = Six(3, '2');
    ASSERT_EQ(val.get_size(), 3);
    ASSERT_EQ(val.get_string(), "222");
}
TEST(test1, ini_list){
    Six val = Six({'4', '4', '3', '2'});
    ASSERT_EQ(val.get_size(), 4);
    ASSERT_EQ(val.get_string(), "4432");
}
TEST(test1, str){
    Six val = Six("24145");
    ASSERT_EQ(val.get_size(), 5);
    ASSERT_EQ(val.get_string(), "24145");
}
TEST(test1, other){
    Six val1 = Six("24145");
    Six val = Six(val1);
    ASSERT_EQ(val.get_size(), 5);
    ASSERT_EQ(val.get_string(), "24145");
}
TEST(test1, op_plus){
    Six val1 = Six("00001");
    Six val2 = Six("5555");
    ASSERT_EQ((val1 + val2).get_string(), "55551");
}
TEST(test1, op_minus){
    Six val1 = Six("00001");
    Six val2 = Six("5555");
    ASSERT_EQ((val1 - val2).get_string(), "1");
}
TEST(test1, op_eq){
    Six val1 = Six("1212");
    Six val2 = Six("1212");
    ASSERT_EQ((val1 == val2), 1);
}
TEST(test1, op_max){
    Six val1 = Six("23514");
    Six val2 = Six("5555");
    ASSERT_EQ(val1 > val2, 1);
}
TEST(test1, op_min){
    Six val1 = Six("33");
    Six val2 = Six("23");
    ASSERT_EQ(val1 < val2, 0);
}
TEST(test1, op_minus_wrong){
    Six val1 = Six("12");
    Six val2 = Six("23");
    ASSERT_ANY_THROW(val1 - val2);
}

TEST(test1, t_n_wrong){
    EXPECT_ANY_THROW(Six num = Six("a2"));
}


TEST(test1, str_wrong){
    EXPECT_ANY_THROW(Six num = Six("a2"));
}


