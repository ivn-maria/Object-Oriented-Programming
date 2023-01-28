#ifndef SVG_FILES_SHAPE_H
#define SVG_FILES_SHAPE_H

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Shape
{
protected:
    struct point
    {
        point() :x(0), y(0){}
        point(double x, double y) :x(x), y(y){}

        double x;
        double y;

        double getDist(const point& other) const
        {
            double dx = x - other.x;
            double dy = y - other.y;

            return sqrt(dx*dx + dy*dy);
        }
    };

    char* color;
    point* points;
    size_t pointsCount;

private:
    void copyFrom(const Shape& other);
    void free();

public:
    explicit Shape(size_t pointsCount);
    Shape(const Shape& other);
    Shape& operator=(const Shape& other);
    virtual ~Shape();

    const point& getPointAtIndex(size_t index) const;
    void setPoint(size_t pointIndex, double x, double y);
    void translate(double addToX, double addToY);

    virtual double getArea() const = 0;
    virtual double getPer()  const = 0;
    virtual double getRadius() const = 0;
    virtual bool isPointIn(double x, double y) const = 0;
    virtual bool isItIn(Shape& shape) const = 0;
    virtual void print() const = 0;
    virtual void saveToFile(char* source) const = 0;
    virtual Shape* clone() const = 0;
};

#endif //SVG_FILES_SHAPE_H
