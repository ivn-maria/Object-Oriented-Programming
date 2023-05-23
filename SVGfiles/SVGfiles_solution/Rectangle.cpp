#include "Rectangle.h"

Rectangle::Rectangle(double x1, double y1, double x3, double y3, const char* setColor) : Shape(4)
{
    setPoint(0, x1, y1);
    setPoint(1, x1, y3);
    setPoint(2, x3, y3);
    setPoint(3, x3, y1);

    this->color = new char[strlen(setColor) + 1];
    strcpy(this->color, setColor);
}

double Rectangle::getArea() const
{
    Shape::point p0 = getPointAtIndex(0);
    Shape::point p1 = getPointAtIndex(1);
    Shape::point p3 = getPointAtIndex(3);

    return p0.getDist(p1) * p0.getDist(p3);
}

double Rectangle::getPer() const
{
    Shape::point p0 = getPointAtIndex(0);
    Shape::point p1 = getPointAtIndex(1);
    Shape::point p3 = getPointAtIndex(3);

    return 2*(p0.getDist(p1) + p0.getDist(p3));
}

double Rectangle::getRadius() const
{
    return 0;
}

bool Rectangle::isPointIn(double x, double y) const
{
    return x >= getPointAtIndex(0).x && x <= getPointAtIndex(3).x &&
           y >= getPointAtIndex(0).y && y <= getPointAtIndex(3).y;
}

bool Rectangle::isItIn(Shape& shape) const
{
    return shape.isPointIn(this->getPointAtIndex(0).x, this->getPointAtIndex(0).y) &&
           shape.isPointIn(this->getPointAtIndex(3).x, this->getPointAtIndex(3).y);
}

void Rectangle::print() const
{
    point p0 = getPointAtIndex(0);
    point p3 = getPointAtIndex(3);

    cout << "Rectangle " << "x0=" << p0.x << " y0=" << p0.y << " x3=" << p3.x << " y3=" << p3.y <<
         " color: "<< color << endl;
}

void Rectangle::saveToFile(char* source) const
{
    std::ofstream file(source);

    Shape::point p0 = getPointAtIndex(0);
    Shape::point p1 = getPointAtIndex(1);
    Shape::point p2 = getPointAtIndex(2);
    Shape::point p3 = getPointAtIndex(3);

    file << "<rect" << ' ';
    file <<"x1=' " << p0.x << " '" << ' ' << "y1=' " << p0.y <<" '" << ' ' << "width=' " << p3.x - p2.x <<" '" << ' '
         << "height=' " << p3.y - p1.y <<" '" << ' ' << "fill=' " << color <<" '" << " />" << endl;
}

Shape* Rectangle::clone() const
{
    Shape* copy = new Rectangle(*this);
    return copy;
}