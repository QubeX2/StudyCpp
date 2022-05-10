#include <iostream>
#include "format.hpp"

struct Point3
{
    Point3(float x, float y, float z) : x(x), y(y), z(z) {}
    float x, y, z;
};

void printPoint(std::unique_ptr<Point3>& point)
{
    std::cout << std::format("Point: ({}, {}, {})\n", point->x, point->y, point->z);
}

int main()
{
    auto p1 { std::make_unique<Point3>(1, 0, 0) };
    auto p2 { std::make_unique<Point3>(3.2, 4.5, 7.8) };
    printPoint(p1);
    printPoint(p2);
}