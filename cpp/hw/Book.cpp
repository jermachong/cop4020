/*
    Author:       Jeremy Achong
    NID:          5124781
    Course:       COP4020

    Title:  Book.cpp
    Description:    Implementation file for the Book class. This class represents a book with
    a name and price, and includes virtual functions for getting the real price and
    string representation of the book. The class also includes constructors, a
    destructor, getters, and setters.
*/
#include <sstream>
#include <vector>
#include "Book.h"
using namespace std;

// Book Class
// Constructors
/**
 * @brief Construct a default Book object.
 * @param None.
 * @return None.
 */
Book::Book()
{
    this->name = "";
    this->price = 100;
}

/**
 * @brief Construct a Book object with a title and price.
 * @param btitle The book title.
 * @param gprice The base price of the book.
 * @return None.
 */
Book::Book(string btitle, double gprice)
{
    this->name = btitle;
    this->price = gprice;
}

/**
 * @brief Construct a Book object from a formatted text line.
 * @param text A line in the format: b <title possibly with spaces> <price>.
 * @return None.
 */
Book::Book(string text)
{
    // format: b <title possibly with spaces> <price>
    istringstream iss(text);
    string typeToken;
    iss >> typeToken;

    string token;
    vector<string> tokens;
    while (iss >> token)
    {
        tokens.push_back(token);
    }

    if (tokens.size() >= 2)
    {
        this->price = stod(tokens.back());
        this->name = tokens[0];
        for (size_t i = 1; i + 1 < tokens.size(); ++i)
        {
            this->name += " " + tokens[i];
        }
    }
    else
    {
        this->name = "";
        this->price = 0;
    }
}
// Destructor
/**
 * @brief Destroy the Book object.
 * @param None.
 * @return None.
 */
Book::~Book()
{
}
// Getters
/**
 * @brief Get the book title.
 * @param None.
 * @return The current title of the book.
 */
string Book::getName()
{
    return this->name;
}

/**
 * @brief Get the base price of the book.
 * @param None.
 * @return The current base price.
 */
double Book::getPrice()
{
    return this->price;
}
// Setters
/**
 * @brief Set the book title.
 * @param name The new title to assign.
 * @return None.
 */
void Book::setName(string name)
{
    this->name = name;
}

/**
 * @brief Set the base price of the book.
 * @param price The new base price to assign.
 * @return None.
 */
void Book::setPrice(double price)
{
    this->price = price;
}
// Virtual functions
/**
 * @brief Compute the discounted real price for a literature book.
 * @param None.
 * @return The real price after applying a 20% discount.
 */
double Book::getRealPrice()
{
    return this->price * 0.8;
}

/**
 * @brief Build a display string for the book.
 * @param None.
 * @return A formatted string containing the book type, name, and real price.
 */
string Book::str()
{
    return "Literature Book:" + this->name + " price:" + to_string(this->getRealPrice());
}

// int main()
// {
//     Book book1;                 // Default constructor
//     Book book2("Macbeth", 178); // Parameterized constructor
//     Book book3("b hamlet 158"); // String constructor

//     cout << "Book 1: " << book1.getName() << ", Price: " << book1.getPrice() << endl;
//     cout << "Book 2: " << book2.getName() << ", Price: " << book2.getPrice() << endl;
//     cout << "Book 3: " << book3.getName() << ", Price: " << book3.getPrice() << endl;

//     return 0;
// }