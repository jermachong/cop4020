#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    // Creation of ofstream class object
    ofstream fout;
    string line;
    fout.open("sample.txt", ios::app);
    // To append the content, open in ios:app
    //  Execute a loop If file successfully opened
    while (fout)
    {
        // Read a Line from standard input
        getline(cin, line); // Press -1 to exit
        if (line == "-1")
            break;
        fout << line << endl; // Write line in file
    }
    fout.close(); // Close the File
    return 0;
}