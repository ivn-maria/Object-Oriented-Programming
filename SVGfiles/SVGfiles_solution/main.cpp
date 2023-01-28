#include "ShapeCollection.cpp"
#include "readFromFile.h"

int main()
{
    ShapeCollection s;

    char source[20];
    cout << "open" << endl << "File source: ";
    cin >> source;
    cout << endl;

   // readFromFile(s, source);

    char operation[20], type[10], choice[10], color[10];
    int coordinates[4];
    int r = 0, ind = 0, addToX = 0, addToY = 0;
    Shape* shape;

    while(true)
    {
        cout << "Chose operation: print, erase, create, translate, within, pointIn, areas, pers, save, exit." << endl;
        cin >> operation;
        cout << endl;

        if (strcmp(operation, "print") == 0)
            s.print();
        else if (strcmp(operation, "erase") == 0)
        {
            cout << "Which figure: ";
            cin >> ind;
            cout << endl;

            s.deleteShapeByIndex(ind - 1);
        }
        else if (strcmp(operation, "create") == 0)
        {
            cout << "What type of figure: ";
            cin >> type;
            cout << endl;
            cout << "Color: ";
            cin >> color;
            cout << endl;

            if(strcmp(type, "line") == 0)
            {
                cout << "Coordinates of 2 points: ";
                for(int & coordinate : coordinates)
                    cin >> coordinate;
                cout << endl;
                s.addLine(coordinates[0], coordinates[1], coordinates[2], coordinates[3], color);
                cout << "Successfully created line";
            }

            if(strcmp(type, "rectangle") == 0)
            {
                cout << "Coordinates of 2 points: ";
                for(int & coordinate : coordinates)
                    cin >> coordinate;
                cout << endl;
                s.addRectangle(coordinates[0], coordinates[1], coordinates[2], coordinates[3], color);
                cout << "Successfully created rectangle";
            }

            if(strcmp(type, "circle") == 0)
            {
                cout << "Coordinates of 1 point: ";
                for(int i = 0; i < 2; i ++)
                    cin >> coordinates[i];
                cout << endl;
                cout << "Radius: ";
                cin >> r;
                cout << endl;
                s.addCircle(coordinates[0], coordinates[1], r, color);
                cout << "Successfully created circle";
            }

            cout << endl;
        }
        else if (strcmp(operation, "translate") == 0)
        {
            cout << "How much to add for x and y: ";
            cin >> addToX >> addToY;
            cout << endl;

            cout << "To all or one figure: ";
            cin >> choice;
            cout << endl;

            if (strcmp(choice, "all") == 0) {
                s.translateAll(addToX, addToY);
            }

            if (strcmp(choice, "one") == 0) {
                cout << "Which figure: ";
                cin >> ind;
                cout << endl;
                s.translateByIndex(ind - 1, addToX, addToY);
            }
        }
        else if (strcmp(operation, "within") == 0)
        {
            cout << "Circle or rectangle: ";
            cin >> choice;
            cout << endl;

            shape = nullptr;

            if(strcmp(choice, "circle") == 0)
            {
                cout << "Coordinates of 1 point: ";
                for(int i = 0; i < 2; i ++)
                    cin >> coordinates[i];
                cout << endl;
                cout << "Radius: ";
                cin >> r;
                cout << endl;
                char* Color = new char[1024];
                shape = new Circle(coordinates[0], coordinates[1], r, Color);
            }

            if(strcmp(choice, "rectangle") == 0)
            {
                cout << "Coordinates of 2 points: ";
                for(int & coordinate : coordinates)
                    cin >> coordinate;
                cout << endl;
                char* Color = new char[1024];
                shape = new Rectangle(coordinates[0], coordinates[1], coordinates[2], coordinates[3], Color);
            }

            if(shape != nullptr) s.getIfShapesAreIn(*shape);
        }
        else if (strcmp(operation, "pointIn") == 0)
        {
            cout << "Coordinates of the point: ";
            cin >> coordinates[0] >> coordinates[1];
            cout << endl;

            for(int i = 0; i < s.getShapesCount(); i++)
                if(s.getIfPointInShapeByIndex(i, coordinates[0], coordinates[1])) {
                    s.printByIndex(i);
                    cout << endl;
                }
        }
        else if (strcmp(operation, "areas") == 0)
        {
            for(int i = 0; i < s.getShapesCount(); i++)
                cout << s.getAreaOfFigureByIndex(i) << endl;
        }
        else if (strcmp(operation, "pers") == 0)
        {
            for(int i = 0; i < s.getShapesCount(); i++)
                cout << s.getPerOfFigureByIndex(i) << endl;
        }
        else if (strcmp(operation, "save") == 0) {
            s.SaveToFile(source);
        }
        else if (strcmp(operation, "exit") == 0) {
            break;
        }
        else cout << "non-valid operation" << endl;
    }

    return 0;
}