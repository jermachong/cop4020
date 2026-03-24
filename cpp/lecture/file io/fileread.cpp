#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    // Reading from a file
    ifstream inputFile("example.txt");
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            // Print each line
            cout << line << endl; // print each line
        }
        inputFile.close(); // close the file
    }
    else
    {
        // Failed to open the file
        cout << "Error opening the file for reading."
             << endl;
        return -1;
    }
    return 0;
}