// Inventory.cpp
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
Inventory::Inventory(string fname)
{
    this->readData(fname);
}
// Destructor
Inventory::~Inventory()
{
}
// Functions
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
void Inventory::add(unique_ptr<Book> book)
{
    // appends book to vec
    this->vec.push_back(std::move(book));
}
bool Inventory::isEmpty()
{
    // returns true if vec is empty, false otherwise
    return this->vec.empty();
}
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
            cout << "\nThe book/s in the inventory is/are\n";
            cout << this->str();
            cout << endl;
        }
        else if (option == "total")
        {
            cout << "\nTotal price of the books is " << fixed << setprecision(6) << this->getRealTotal() << "\n\n";
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
