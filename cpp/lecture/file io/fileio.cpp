#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ofstream outputFile("example.txt");
    // Open the file for writing
    if (outputFile.is_open())
    {
        outputFile << "Hello, World!" << endl;
        outputFile << 42 << endl;
        outputFile.close(); // Close the file
    }
    else
    {
        // Failed to open the file
        cout << "Error opening the file for writing."
             << endl;
        return -1;
    }
    return 0;
}