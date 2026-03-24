#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream fio;
    string line;
    fio.open("sample.txt", ios::trunc | ios::out | ios::in);
    while (fio)
    { // if the file is still open
        getline(cin, line);
        // Read a Line from standard input
        if (line == "-1") // Press -1 to exit
            break;
        fio << line << endl; // Write line in file
    }
    fio.seekg(0, ios::beg); // move the cursor to beginning
    if (fio)
    { // if file is opened
        while (getline(fio, line))
        {
            cout << line << endl; // Print line in Console
        }
    }
    fio.close(); // Close the file
    return 0;
}
