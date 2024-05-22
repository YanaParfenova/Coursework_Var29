#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "include.h"

using namespace std;

struct Point {
    double x, y;
};

class Figure
{
public:
    Figure() = default;
    virtual void Delete(size_t index) = 0;
    virtual void Show(size_t index) const = 0;
    virtual bool Verification(size_t index) const = 0;
    virtual void MoveO(size_t index, double x, double y) = 0;
    vector<Point>Intersect(size_t index);
    ~Figure() = default;
};