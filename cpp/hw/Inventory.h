/*
    Author:       Jeremy Achong
    NID:          5124781
    Course:       COP4020

    Title:  Inventory.h
    Description:    Header file for the Inventory class. This class represents an inventory
    of books, which can include both regular books and spell books. The class includes a
    vector of unique pointers to Book instances, as well as functions for reading book data
    from a file, adding books to the inventory, checking if the inventory is empty,
    getting a string representation of the inventory, calculating the total price of the
    books, searching for a specific book by name, and displaying a menu for user interaction.
*/
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <memory>
#include "Book.h"
#include "SpellBook.h"
using namespace std;

class Inventory
{
private:
    // Vector of unique pointers to Book instances
    vector<unique_ptr<Book>> vec;

public:
    // Constructor
    /**
     * @brief Construct an Inventory and load book data from a file.
     * @param fname The path to the input data file.
     * @return None.
     */
    Inventory(string fname);
    // Destructor
    /**
     * @brief Destroy the Inventory object.
     * @param None.
     * @return None.
     */
    ~Inventory();
    // Functions
    /**
     * @brief Read book records from a file and populate the inventory.
     * @param fname The path to the input data file.
     * @return None.
     */
    void readData(string fname);

    /**
     * @brief Add a book object to the inventory.
     * @param book A unique pointer to a Book (or derived type) to store.
     * @return None.
     */
    void add(unique_ptr<Book> book);

    /**
     * @brief Check whether the inventory contains any books.
     * @param None.
     * @return True if the inventory is empty; otherwise false.
     */
    bool isEmpty();

    /**
     * @brief Build a multi-line string of all books in the inventory.
     * @param None.
     * @return A newline-separated string representation of all books.
     */
    string str();

    /**
     * @brief Calculate the total real price of all books.
     * @param None.
     * @return The sum of getRealPrice() for every stored book.
     */
    double getRealTotal();

    /**
     * @brief Search for books whose names contain a given substring.
     * @param bname The substring to match against each book name.
     * @return None.
     */
    void searchBook(string bname);

    /**
     * @brief Run the interactive inventory menu loop.
     * @param None.
     * @return None.
     */
    void menu();
};

#endif