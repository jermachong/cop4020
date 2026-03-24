#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Declaration and initialization of a 2D array
    int arr[3][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}};
    cout << "Element at arr[0][0]: " << arr[0][0] << endl;
    cout << "Element at arr[1][2]: " << arr[1][2] << endl;
    arr[2][3] = 20;
    cout << "Modified element at arr[2][3]: " << arr[2][3] << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}