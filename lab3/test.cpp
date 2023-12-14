#include <gtest/gtest.h>
#include "array.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "triangle.hpp"

std::vector<std::pair<double, double>> v1 = {{1, 1}, {2, 2}, {3, 3}};
std::vector<std::pair<double, double>> v2 = {{6, 6}, {7, 7}, {8, 8}};

TEST(Triangle, empty_constructor) {
    Triangle p;
    std::pair<double, double> center{0, 0};
    EXPECT_EQ(p.get_middle(), center);
    EXPECT_EQ(p.get_s(), 0);
}

TEST(Triangle, vector_constructor) {
    Triangle p(v1);
    std::pair<double, double> center{2, 2};
    EXPECT_EQ(p.get_points(), v1);
    EXPECT_EQ(p.get_middle(), center);
}

TEST(Triangle, equality) {
    Triangle p1(v1);
    Triangle p2(v1);
    Triangle p3(v2);
    EXPECT_EQ(p1, p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(Triangle, copy) {
    Triangle p1;
    Triangle p2(v1);
    Triangle p3(v2);
    p1 = p2;
    EXPECT_EQ(p1, p2);
    Triangle p4;
    p4 = p1;
    p2 = p3;
    EXPECT_EQ(p1, p4);
}

TEST(Triangle, assignment) {
    Triangle p;
    p = Triangle(v1);
    std::pair<double, double> center{2, 2};
    EXPECT_EQ(p.get_points(), v1);
    EXPECT_EQ(p.get_middle(), center);
}

TEST(Triangle, double_cast) {
    Triangle p(v1);
    double a = (double)p;
    EXPECT_EQ(a, p.get_s());
}

std::vector<std::pair<double, double>> v3 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};
std::vector<std::pair<double, double>> v4 = {{7, 7}, {8, 8}, {9, 9}, {10, 10}, {11, 11}, {12, 12}};

TEST(Hexagon, empty_constructor) {
    Hexagon h;
    std::pair<double, double> center{0, 0};
    EXPECT_EQ(h.get_middle(), center);
    EXPECT_EQ(h.get_s(), 0);
}

TEST(Hexagon, vector_constructor) {
    Hexagon h(v3);
    std::pair<double, double> center{3.5, 3.5};
    EXPECT_EQ(h.get_points(), v3);
    EXPECT_EQ(h.get_middle(), center);
}

TEST(Hexagon, equality) {
    Hexagon h1(v3);
    Hexagon h2(v3);
    Hexagon h3(v4);
    EXPECT_EQ(h1, h2);
    EXPECT_FALSE(h1 == h3);
}

TEST(Hexagon, copy) {
    Hexagon h1;
    Hexagon h2(v3);
    Hexagon h3(v4);
    h1 = h2;
    EXPECT_EQ(h1, h2);
    Hexagon h4;
    h4 = h1;
    h2 = h3;
    EXPECT_EQ(h1, h4);
}

TEST(Hexagon, assignment) {
    Hexagon h;
    h = Hexagon(v3);
    std::pair<double, double> center{3.5, 3.5};
    EXPECT_EQ(h.get_points(), v3);
    EXPECT_EQ(h.get_middle(), center);
}

TEST(Hexagon, double_cast) {
    Hexagon h(v3);
    double a = (double)h;
    EXPECT_EQ(a, h.get_s());
}

std::vector<std::pair<double, double>> v5 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}};
std::vector<std::pair<double, double>> v6 = {{9, 9}, {10, 10}, {11, 11}, {12, 12}, {13, 13}, {14, 14}, {15, 15}, {16, 16}};

TEST(Octagon, empty_constructor) {
    Octagon o;
    std::pair<double, double> center{0, 0};
    EXPECT_EQ(o.get_middle(), center);
    EXPECT_EQ(o.get_s(), 0);
}

TEST(Octagon, vector_constructor) {
    Octagon o(v5);
    std::pair<double, double> center{4.5, 4.5};
    EXPECT_EQ(o.get_points(), v5);
    EXPECT_EQ(o.get_middle(), center);
}

TEST(Octagon, equality) {
    Octagon o1(v5);
    Octagon o2(v5);
    Octagon o3(v6);
    EXPECT_EQ(o1, o2);
    EXPECT_FALSE(o1 == o3);
}

TEST(Octagon, copy) {
    Octagon o1;
    Octagon o2(v5);
    Octagon o3(v6);
    o1 = o2;
    EXPECT_EQ(o1, o2);
    Octagon o4;
    o4 = o1;
    o2 = o3;
    EXPECT_EQ(o1, o4);
}

TEST(Octagon, assignment) {
    Octagon o;
    o = Octagon(v5);
    std::pair<double, double> center{4.5, 4.5};
    EXPECT_EQ(o.get_points(), v5);
    EXPECT_EQ(o.get_middle(), center);
}

TEST(Octagon, double_cast) {
    Octagon o(v5);
    double a = (double)o;
    EXPECT_EQ(a, o.get_s());
}

TEST(Array, basic_constructor) {
    Array a;

    for (size_t i = 0; i != 100; ++i)
        EXPECT_EQ(a[i], nullptr);
}

TEST(Array, size_conrtuctor) {
    Array a(10);

    for (size_t i = 0; i != 10; ++i)
        EXPECT_EQ(a[i], nullptr);
}

TEST(Array, update_element) {
    Array a(10);
    Triangle* p = new Triangle();
    a.add_fig(1, p);
    EXPECT_EQ(a[1], p);
    EXPECT_EQ(a[2], nullptr);
    EXPECT_EQ(a[0], nullptr);
}

TEST(Array, delete_element) {
    Array a(10);
    Triangle* p = new Triangle();
    a.add_fig(1, p);
    EXPECT_EQ(a[1], p);
    a.delete_fig(1);
    EXPECT_EQ(a[1], nullptr);
}

TEST(Array, common_get_s) {
    Array a(2);
    Triangle* p1 = new Triangle();
    Triangle* p2 = new Triangle();
    a.add_fig(0, p1);
    a.add_fig(1, p2);
    EXPECT_EQ(a.area(), 0.0);
}