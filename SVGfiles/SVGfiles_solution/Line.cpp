#include "Line.h"

Line::Line(double x1, double y1, double x2, double y2, const char* setColor) : Shape(2)
{
    setPoint(0, x1, y1);
    setPoint(1, x2, y2);

    this->color = new char[strlen(setColor) + 1];
    strcpy(this->color, setColor);
}

double Line::getArea() const
{
    return 0;
}

double Line::getPer() const {
    Shape::point p0 = getPointAtIndex(0);
    Shape::point p1 = getPointAtIndex(1);

    return p0.getDist(p1);
}

double Line::getRadius() const
{
    return 0;
}

bool Line::isPointIn(double x, double y) const
{
    return x >= getPointAtIndex(0).x && x <= getPointAtIndex(1).x &&
           y >= getPointAtIndex(0).y && y <= getPointAtIndex(1).y;
}

bool Line::isItIn(Shape& shape) const
{
    return shape.isPointIn(this->getPointAtIndex(0).x, this->getPointAtIndex(0).y) &&
           shape.isPointIn(this->getPointAtIndex(1).x, this->getPointAtIndex(1).y);
}

void Line::print() const
{
    point p0 = getPointAtIndex(0);
    point p1 = getPointAtIndex(1);

    cout << "Line: " << "x0 = " << p0.x << " y0 = " << p0.y << "x1 = " << p1.x << " y1 = " << p1.y
         << " color: " << color << endl;
}

void Line::saveToFile(char* source) const
{
    std::ofstream file(source);

    Shape::point p0 = getPointAtIndex(0);
    Shape::point p1 = getPointAtIndex(1);

    file << "<line" << ' ';
    file << "x1=' " << p0.x <<" '" << ' ' << "y1=' " << p0.y <<" '" << ' ' << "x2=' " << p1.x <<" '" << ' ' << "y2=' "
         << p1.y <<" '" << ' '<< "fill=' " << color <<" '" << ' ' << "/>" << endl;
}

Shape* Line::clone() const
{
    Shape* copy = new Line(*this);
    return copy;
}