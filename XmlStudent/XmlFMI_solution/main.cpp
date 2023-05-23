#include "read_and_operations.h"

int main()
{
    char source[100];
    cout << "Enter file path:" << endl;
    cin >> source;
    cout << "File loaded successfully!" << endl;

    read(source);

    operations(source);
}