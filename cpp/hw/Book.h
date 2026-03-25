/*
    Author:       Jeremy Achong
    NID:          5124781
    Course:       COP4020

    Title: Book.h
    Description: Header file for the Book class. This class represents a book with
    a name and price, and includes virtual functions for getting the real price and
    string representation of the book. The class also includes constructors, a
    destructor, getters, and setters.
*/
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
private:
    string name;
    double price;

public:
    // Constructors
    /**
     * @brief Construct a default Book object.
     * @param None.
     * @return None.
     */
    Book();

    /**
     * @brief Construct a Book object with a title and price.
     * @param btitle The book title.
     * @param gprice The base price of the book.
     * @return None.
     */
    Book(string btitle, double gprice);

    /**
     * @brief Construct a Book object from a formatted text line.
     * @param text A line in the format: b <title possibly with spaces> <price>.
     * @return None.
     */
    Book(string text);
    // Destructor
    /**
     * @brief Destroy the Book object.
     * @param None.
     * @return None.
     */
    virtual ~Book();
    // Getters
    /**
     * @brief Get the book title.
     * @param None.
     * @return The current title of the book.
     */
    string getName();

    /**
     * @brief Get the base price of the book.
     * @param None.
     * @return The current base price.
     */
    double getPrice();
    // Setters
    /**
     * @brief Set the book title.
     * @param name The new title to assign.
     * @return None.
     */
    void setName(string name);

    /**
     * @brief Set the base price of the book.
     * @param price The new base price to assign.
     * @return None.
     */
    void setPrice(double price);
    // Virtual functions
    /**
     * @brief Compute the discounted real price for a literature book.
     * @param None.
     * @return The real price after applying a 20% discount.
     */
    virtual double getRealPrice();

    /**
     * @brief Build a display string for the book.
     * @param None.
     * @return A formatted string containing the book type, name, and real price.
     */
    virtual string str();
};

#endif