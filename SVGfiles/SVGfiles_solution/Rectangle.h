#ifndef SVG_FILES_RECTANGLE_H
#define SVG_FILES_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(double x1, double y1, double x3, double y3, const char* setColor);

    double getArea() const override;
    double getPer() const override;
    double getRadius() const override;
    bool isPointIn(double x, double y) const override;
    bool isItIn(Shape& shape) const override;
    void print() const override;
    void saveToFile(char* source) const override;
    Shape* clone() const override;
};

#endif //SVG_FILES_RECTANGLE_H
