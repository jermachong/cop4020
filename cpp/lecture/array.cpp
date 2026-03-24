#include <iostream>
#include <string>
using namespace std;
int main()
{
    // Declare and initialize an array of strings
    string fruits[] = {"elem1", "elem2", "elem3", "elem4"};
    // Access and print each element of the array
    for (int i = 0; i < 4; i++)
    {
        cout << "Element at index " << i << ": " << fruits[i] << endl;
    }
    return 0;
}