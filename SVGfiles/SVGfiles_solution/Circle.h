#ifndef SVG_FILES_CIRCLE_H
#define SVG_FILES_CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
    double radius;

public:
    Circle(double x, double y, double radius, const char* setColor);

    double getArea() const override;
    double getPer() const override;
    double getRadius() const override;
    bool isPointIn(double x, double y) const override;
    bool isItIn(Shape& shape) const override;
    void print() const override;
    void saveToFile(char* source) const override;
    Shape* clone() const override;
};

#endif //SVG_FILES_CIRCLE_H
