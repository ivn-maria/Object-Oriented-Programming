#ifndef SVG_FILES_READFROMFILE_H
#define SVG_FILES_READFROMFILE_H

#include "ShapeCollection.h"

void readFromFile(ShapeCollection& collection, char* source)
{
    std::ifstream file(source);

    while (!file.eof())
    {
        char* type = new char[1024];
        file >> type;

        if (strcmp(type, "<circle") == 0)
        {
            char* element = new char[1024];
            file >> element;

            double x = 0, y = 0, r = 0;
            char* color = new char[1024];

            if (strcmp(element, "cx='") == 0)
                file >> x;

            char* coma = new char[1024];
            file >> coma;
            file >> element;

            if (strcmp(element, "cy='") == 0)
                file >> y;

            file >> coma;
            file >> element;

            if (strcmp(element, "r='") == 0)
                file >> r;

            file >> coma;
            file >> element;

            if (strcmp(element, "fill='") == 0)
                file >> color;

            collection.addCircle(x, y, r, color);

            delete[] color;
            delete[] element;
            delete[] coma;
        }
        else if (strcmp(type, "<rect") == 0)
        {
            char* element = new char[1024];
            file >> element;
            double x1 = 0, y1 = 0, w = 0, h = 0;
            char* color = new char[1024];

            if (strcmp(element, "x1='") == 0)
                file >> x1;

            char* coma = new char[1024];
            file >> coma;
            file >> element;

            if (strcmp(element, "y1='") == 0)
                file >> y1;

            file >> coma;
            file >> element;

            if (strcmp(element, "width='") == 0)
                file >> w;

            file >> coma;
            file >> element;

            if (strcmp(element, "height='") == 0)
                file >> h;

            file >> coma;
            file >> element;

            if (strcmp(element, "fill='") == 0)
                file >> color;

            collection.addRectangle(x1, y1, x1 + w, y1 + h, color);

            delete[] color;
            delete[] coma;
            delete[] element;
        }
        else if (strcmp(type, "<line") == 0)
        {
            char* element = new char[1024];
            file >> element;
            double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            char* color = new char[1024];

            if (strcmp(element, "x1='") == 0)
                file >> x1;

            char* coma = new char[1024];
            file >> coma;
            file >> element;

            if (strcmp(element, "y1='") == 0)
                file >> y1;

            file >> coma;
            file >> element;

            if (strcmp(element, "x2='") == 0)
                file >> x2;

            file >> coma;
            file >> element;

            if (strcmp(element, "y2='") == 0)
                file >> y2;

            file >> coma;
            file >> element;

            if (strcmp(element, "fill='") == 0)
                file >> color;

            collection.addLine(x1, y1, x2, y2, color);

            delete[] color;
            delete[] coma;
            delete[] element;
        }
        delete[] type;
    }
}

#endif //SVG_FILES_READFROMFILE_H
