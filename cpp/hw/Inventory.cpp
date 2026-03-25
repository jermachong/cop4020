/*
    Author:       Jeremy Achong
    NID:          5124781
    Course:       COP4020

    Title:  Inventory.cpp
    Description:    Implementation file for the Inventory class. This class represents an inventory
    of books, which can include both regular books and spell books. The class includes a
    vector of unique pointers to Book instances, as well as functions for reading book data
    from a file, adding books to the inventory, checking if the inventory is empty,
    getting a string representation of the inventory, calculating the total price of the
    books, searching for a specific book by name, and displaying a menu for user interaction.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <utility>
#include "Inventory.h"
using namespace std;

// Inventory Class
// Constructor
/**
 * @brief Construct an Inventory and load book data from a file.
 * @param fname The path to the input data file.
 * @return None.
 */
Inventory::Inventory(string fname)
{
    this->readData(fname);
}
// Destructor
/**
 * @brief Destroy the Inventory object.
 * @param None.
 * @return None.
 */
Inventory::~Inventory()
{
}
// Functions
/**
 * @brief Read book records from a file and populate the inventory.
 * @param fname The path to the input data file.
 * @return None.
 */
void Inventory::readData(string fname)
{
    // opens fname, on failure prints Error opening file {fname} and returns
    ifstream infile(fname);
    if (!infile.is_open())
    {
        cout << "Error opening file " << fname << endl;
        return;
    }
    // otherwise reads each line, uses line[0] to choose Book or Spellbook
    // constructs accordingly, then calls add()
    string line;
    while (getline(infile, line))
    {
        if (line[0] == 'b')
        {
            unique_ptr<Book> book = make_unique<Book>(line);
            this->add(std::move(book));
        }
        else if (line[0] == 's')
        {
            unique_ptr<SpellBook> spellbook = make_unique<SpellBook>(line);
            this->add(std::move(spellbook));
        }
    }
    infile.close();
}

/**
 * @brief Add a book object to the inventory.
 * @param book A unique pointer to a Book (or derived type) to store.
 * @return None.
 */
void Inventory::add(unique_ptr<Book> book)
{
    // appends book to vec
    this->vec.push_back(std::move(book));
}

/**
 * @brief Check whether the inventory contains any books.
 * @param None.
 * @return True if the inventory is empty; otherwise false.
 */
bool Inventory::isEmpty()
{
    // returns true if vec is empty, false otherwise
    return this->vec.empty();
}

/**
 * @brief Build a multi-line string of all books in the inventory.
 * @param None.
 * @return A newline-separated string representation of all books.
 */
string Inventory::str()
{
    // returns each book element's str() joinwed with newlines
    string result = "";
    for (const auto &book : this->vec)
    {
        result += book->str() + "\n";
    }
    return result;
}

/**
 * @brief Calculate the total real price of all books.
 * @param None.
 * @return The sum of getRealPrice() for every stored book.
 */
double Inventory::getRealTotal()
{
    // returns the sum of each book element's getRealPrice()
    double total = 0.000000;
    for (const auto &book : this->vec)
    {
        total += book->getRealPrice();
    }
    return total;
}

/**
 * @brief Search for books whose names contain a given substring.
 * @param bname The substring to match against each book name.
 * @return None.
 */
void Inventory::searchBook(string bname)
{
    // if a book with name bname exists in vec, prints its str() and returns, otherwise prints No result found
    // if more than one entry is found, each Book is printed on a new
    // use occurences of the getName() function to find matches
    cout << "Searched book name: " << bname << endl;
    bool found = false;
    for (const auto &book : this->vec)
    {
        // case-sensitive search for bname in book->getName()
        if (book->getName().find(bname) != string::npos)
        {
            cout << book->str() << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No result found" << endl;
}

/**
 * @brief Run the interactive inventory menu loop.
 * @param None.
 * @return None.
 */
void Inventory::menu()
{
    // if isEmpty() is true, reutns without printing anything
    if (this->isEmpty())
        return;

    string option = "";
    // cin >> ws;

    while (option != "done")
    {
        cout << "Enter option search BOOKNAME/all/total/done\n";
        getline(cin, option);
        if (option == "all")
        {
            cout << "The book/s in the inventory is/are\n";
            cout << this->str();
            cout << endl;
        }
        else if (option == "total")
        {
            cout << "Total price of the books is " << fixed << setprecision(6) << this->getRealTotal() << "\n\n";
        }
        else if (option.find("search ") == 0)
        {
            string bname = option.substr(7);
            this->searchBook(bname);
            cout << endl;
        }
        else if (option == "")
        {
            continue;
        }
        else if (option == "done")
        {
            break;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }
}
