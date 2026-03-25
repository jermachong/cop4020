/*
    Author:       Jeremy Achong
    NID:          5124781
    Course:       COP4020

    Description:  This program reads in book data from a file and allows the user
    to interact with the inventory of books through a menu. The user can view all
    books, calculate the total price of the books, and search for a specific book by name.
*/

#include <iostream>
#include "Inventory.h"
using namespace std;

/**
 * @brief Program entry point for the inventory application.
 * @param None.
 * @return 0 when program execution completes successfully.
 */
int main()
{
    string fname;
    cout << "Enter filename\n";

    getline(cin, fname); // get user input for filename

    Inventory inventory(fname); // create Inventory object with the filename
    inventory.menu();

    return 0;
}
