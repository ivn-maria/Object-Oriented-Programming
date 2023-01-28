#include "Circle.h"

const double PI = 3.1415;

Circle::Circle(double x, double y, double radius, const char* setColor) : Shape(1)
{
    setPoint(0, x, y);
    this->radius = radius;

    this->color = new char[strlen(setColor) + 1];
    strcpy(this->color, setColor);
}

double Circle::getArea() const
{
    return PI * radius * radius;
}

double Circle::getPer() const
{
    return 2 * PI * radius;
}

double Circle::getRadius() const
{
    return radius;
}

bool Circle::isPointIn(double x, double y) const
{
    point p(x, y);
    return p.getDist(getPointAtIndex(0)) <= radius;
}

bool Circle::isItIn(Shape& shape) const
{
    if(pointsCount == 1) {
        point p0(shape.getPointAtIndex(0));
        return (shape.getRadius() > this->getPointAtIndex(0).getDist(p0) + this->radius);
    } else if(pointsCount == 4)
        return this->getPointAtIndex(0).x + radius <= shape.getPointAtIndex(2).x &&
               this->getPointAtIndex(2).x - radius >= shape.getPointAtIndex(0).x &&
               this->getPointAtIndex(0).y + radius <= shape.getPointAtIndex(2).y &&
               this->getPointAtIndex(2).y - radius >= shape.getPointAtIndex(0).y;
    return false;
}

void Circle::print() const
{
    point p0 = getPointAtIndex(0);

    cout << "Circle: " << "x0 = " << p0.x << " radius = " << radius << " color: " << color << endl;
}

void Circle::saveToFile(char* source) const
{
    std::ofstream file(source);

    Shape::point p0 = getPointAtIndex(0);

    file << "<circle" << ' ';
    file << "cx=' " << p0.x << " '" << ' ' << "cy=' " << p0.y << " '" << ' ' << "r=' " << radius << " '" << ' '
         << " fill=' " << color << " '" << " />" << endl;
}

Shape* Circle::clone() const
{
    Shape* copy = new Circle(*this);
    return copy;
}
