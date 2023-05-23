#include "HexViewer.h"
#include "operations.h"

int main()
{
    char source[100];
    cout << "Enter file path:" << endl;
    cin >> source;

    HexViewer h(source);
    size_t sizeOfSource = h.getSize();
    cout << "File loaded successfully! Size: " << sizeOfSource << " bytes" << endl;

    operations(h);
}