#include <iostream>
#include "Inventory.h"
using namespace std;

int main()
{
    string fname;
    cout << "Enter filename\n";

    getline(cin, fname); // clear cin buffer

    Inventory inventory(fname);
    inventory.menu();

    return 0;
}
