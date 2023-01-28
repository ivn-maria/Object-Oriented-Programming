#ifndef SVG_FILES_SHAPECOLLECTION_H
#define SVG_FILES_SHAPECOLLECTION_H

#include "Shape.h"

class ShapeCollection
{
    Shape** shapes;
    size_t shapesCount;
    size_t capacity;

    void free();
    void copyFrom(const ShapeCollection& other);
    void resize();

    void addShape(Shape* shape);

public:
    ShapeCollection();
    ShapeCollection(const ShapeCollection& other);
    ShapeCollection& operator=(const ShapeCollection& other);
    ~ShapeCollection();

    void addRectangle(double x1, double y1, double x3, double y3, char* color);
    void addCircle(double x1, double y1, double r, char* color);
    void addLine(double x1, double y1, double x2, double y2, char* color);
    void deleteShapeByIndex(size_t ind);

    double getPerOfFigureByIndex(size_t ind) const;
    double getAreaOfFigureByIndex(size_t ind) const;
    size_t getShapesCount() const;
    bool getIfPointInShapeByIndex(size_t ind, double x,double y) const;
    void getIfShapesAreIn(Shape& shape) const;
    void print() const;
    void printByIndex(size_t ind) const;
    void translateByIndex(size_t ind, double addToX, double addToY) const;
    void translateAll(double addToX, double addToY) const;
    void SaveToFile(char* source) const;
};


#endif //SVG_FILES_SHAPECOLLECTION_H
