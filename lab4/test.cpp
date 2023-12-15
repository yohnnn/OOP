#include <gtest/gtest.h>
#include "functions.hpp"
#include "array.hpp"
#include "octagon.hpp"
#include "hexagon.hpp"
#include "triangle.hpp"

TEST(Triangle, empty_constructor)
{
    Triangle<double> t;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = get_middle<Triangle<double>, double>(t);
    double get_sace = get_s<Triangle<double>, double>(t);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(0, get_sace);
}

TEST(Triangle, vect_const)
{
    std::vector<double> x{1, 2, 3};
    std::vector<double> y{1, 2, 3};
    std::vector<std::pair<double, double>> three(3);
    for (int i = 0; i < 3; ++i)
    {
        three[i].first = x[i];
        three[i].second = y[i];
    }
    Triangle<double> t(three);

    std::pair<double, double> dot = {2, 2};
    std::pair<double, double> time = get_middle<Triangle<double>, double>(t);
    EXPECT_EQ(time, dot);
}

TEST(Octagon, empty)
{
    Octagon<double> r;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = get_middle<Octagon<double>, double>(r);
    double get_sace = get_s<Octagon<double>, double>(r);
    EXPECT_NEAR(time.first, dot.first, 1e-6);
    EXPECT_NEAR(time.second, dot.second, 1e-6);
    EXPECT_NEAR(0, get_sace, 1e-6);
}

TEST(Octagon, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 1, 2, 3, 1};
    std::vector<double> y{1, 2, 3, 1, 1, 2, 3, 1};
    std::vector<std::pair<double, double>> ei(8);
    for (int i = 0; i < 8; ++i)
    {
        ei[i].first = x[i];
        ei[i].second = y[i];
    }
    Octagon<double> r(ei);

    std::pair<double, double> dot = {1.75, 1.75};  
    std::pair<double, double> time = get_middle<Octagon<double>, double>(r);
    EXPECT_NEAR(time.first, dot.first, 1e-6);
    EXPECT_NEAR(time.second, dot.second, 1e-6);
}

TEST(Hexagon, empty)
{
    Hexagon<double> s;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = get_middle<Hexagon<double>, double>(s);
    double get_sace = get_s<Hexagon<double>, double>(s);
    EXPECT_NEAR(time.first, dot.first, 1e-6);
    EXPECT_NEAR(time.second, dot.second, 1e-6);
    EXPECT_NEAR(0, get_sace, 1e-6);
}

TEST(Hexagon, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 1, 2};
    std::vector<std::pair<double, double>> four(6);
    for (int i = 0; i < 6; ++i)
    {
        four[i].first = x[i];
        four[i].second = y[i];
    }
    Hexagon<double> s(four);

    std::pair<double, double> dot = {10.0/6.0, 10.0/6.0};  
    std::pair<double, double> time = get_middle<Hexagon<double>, double>(s);
    EXPECT_NEAR(time.first, dot.first, 1e-6);
    EXPECT_NEAR(time.second, dot.second, 1e-6);
}

TEST(Array, common_get_s)
{
    Array<Triangle<double>> a(2);
    Triangle<double> *t1 = new Triangle<double>();
    Triangle<double> *t2 = new Triangle<double>();
    a[0] = *t1;
    a[1] = *t2;
    EXPECT_EQ(a.area(), 0.0);
}