#include "Shape.h"

const Shape::point& Shape::getPointAtIndex(size_t index) const
{
    if (index >= pointsCount)
        std::cout << "Invalid point index!" << std::endl;

    return  points[index];
}

void Shape::copyFrom(const Shape& other)
{
    color = new char[strlen(other.color) + 1];
    color = other.color;

    points = new point[other.pointsCount];

    for (int i = 0; i < other.pointsCount; i++)
        points[i] = other.points[i];

    pointsCount = other.pointsCount;
}

void Shape::free()
{
    delete[] color;
    delete[] points;
}

Shape::Shape(size_t pointsCount) : pointsCount(pointsCount)
{
    points = new point[pointsCount];
}

Shape::Shape(const Shape& other)
{
    copyFrom(other);
}

Shape& Shape::operator= (const Shape& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Shape::~Shape()
{
    free();
}

void Shape::setPoint(size_t pointIndex, double x, double y)
{
    if (pointIndex >= pointsCount)
        return;

    points[pointIndex] = point(x, y);
}

void Shape::translate(double addToX, double addToY)
{
    for(int i = 0; i < pointsCount; i++)
    {
        point p = getPointAtIndex(i);
        p.x += addToX;
        p.y += addToY;
        setPoint(i, p.x, p.y);
    }
}
