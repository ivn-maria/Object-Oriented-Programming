#include "ShapeCollection.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

void ShapeCollection::free()
{
    for (size_t i = 0; i < shapesCount; i++)
        delete shapes[i];
    delete[] shapes;
}

void ShapeCollection::copyFrom(const ShapeCollection& other)
{
    shapes = new Shape* [other.shapesCount];
    shapesCount = other.shapesCount;
    capacity = other.capacity;

    for (size_t i = 0; i < shapesCount; i++)
        shapes[i] = other.shapes[i]->clone();
}

void ShapeCollection::resize()
{
    auto** newCollection = new Shape * [capacity *= 2];
    for (size_t i = 0; i < shapesCount; i++)
        newCollection[i] = shapes[i];
    delete[] shapes;
    shapes = newCollection;
}

ShapeCollection::ShapeCollection()
{
    capacity = 8;
    shapesCount = 0;
    shapes = new Shape * [capacity];
}

ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
    copyFrom(other);
}

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

ShapeCollection::~ShapeCollection()
{
    free();
}

void ShapeCollection::addShape(Shape* shape)
{
    if (shapesCount == capacity)
        resize();
    shapes[shapesCount++] = shape;
}

void ShapeCollection::addRectangle(double x1, double y1, double x3, double y3, char* Color)
{
    auto rect = new Rectangle(x1, y1, x3, y3, Color);
    addShape(rect);
}

void ShapeCollection::addCircle(double x1, double y1, double r, char* Color)
{
    auto* circle = new Circle(x1, y1, r, Color);
    addShape(circle);
}

void ShapeCollection::addLine(double x1, double y1, double x2, double y2, char* Color)
{
    auto* line = new Line(x1, y1, x2, y2, Color);
    addShape(line);
}

void ShapeCollection::deleteShapeByIndex(size_t ind)
{
    if (ind >= shapesCount || ind < 0)
        return;

    auto** tempShapes = new Shape* [shapesCount - 1];

    if(shapesCount == 1)
        tempShapes[0] = nullptr;
    else
    {
        for(int i = 0; i < shapesCount; i++)
        {
            if (i < ind)
                tempShapes[i] = shapes[i];
            else tempShapes[i] = shapes[i + 1];
        }
    }
    shapesCount--;
    shapes = tempShapes;
}

double ShapeCollection::getPerOfFigureByIndex(size_t ind) const
{
    if (ind >= shapesCount || ind < 0)
        return 0;
    return shapes[ind]->getPer();
}

double ShapeCollection::getAreaOfFigureByIndex(size_t ind) const
{
    if (ind >= shapesCount || ind < 0)
        return 0;
    return shapes[ind]->getArea();
}

size_t ShapeCollection::getShapesCount() const
{
    return shapesCount;
}

bool ShapeCollection::getIfPointInShapeByIndex(size_t ind, double x, double y) const
{
    if (ind >= shapesCount || ind < 0)
        return false;
    return shapes[ind]->isPointIn(x, y);
}

void ShapeCollection::getIfShapesAreIn(Shape& shape) const
{
    for(int i = 0; i < shapesCount; i++)
        if(shapes[i]->isItIn(shape))
            shapes[i]->print();
}

void ShapeCollection::print() const
{
    for(int i = 0; i < shapesCount; i++)
        shapes[i]->print();
}

void ShapeCollection::printByIndex(size_t ind) const
{
    if (ind >= shapesCount || ind < 0)
        return;
    shapes[ind]->print();
}

void ShapeCollection::translateByIndex(size_t ind, double addToX, double addToY) const
{
    if (ind >= shapesCount || ind < 0)
        return;
    shapes[ind]->translate(addToX, addToY);
}

void ShapeCollection::translateAll(double addToX, double addToY) const
{
    for (int i = 0; i < shapesCount; i++)
        shapes[i]->translate(addToX, addToY);
}

void ShapeCollection::SaveToFile(char* source) const
{
    std::ofstream file(source);

    file << "<?xml version='1.0' standalone ='no'?>" << endl;
    file <<	"<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN'"<< endl;
    file << "'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'>" << endl;
    file << "<svg xmlns='http://www.w3.org/2000/svg' version='1.1' width = '100' height = '100' viewBox = '0 0 100 100'>\n";

    for (int i = 0; i < shapesCount; i++)
        shapes[i]->saveToFile(source);

    file << "</svg>\n";
}