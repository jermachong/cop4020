// Inventory Class
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <memory>
#include "Book.h"
#include "SpellBook.h"
using namespace std;

/*
This class will have a vector instance variable, vec, that stores unique pointers to Book instances.
Storing pointers will allow us to use inheritance and polymorphism.
Storing unique pointers will save us from the burden of memory management.
*/
class Inventory
{
private:
    // Vector of unique pointers to Book instances
    vector<unique_ptr<Book>> vec;

public:
    // Constructor
    Inventory(string fname);
    // Destructor
    ~Inventory();
    // Functions
    void readData(string fname);
    void add(unique_ptr<Book> book);
    bool isEmpty();
    string str();
    double getRealTotal();
    void searchBook(string bname);
    void menu();
};

#endif