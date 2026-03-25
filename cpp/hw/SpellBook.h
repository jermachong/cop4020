/*
    Author:       Jeremy Achong
    NID:          5124781
    Course:       COP4020

    Title:  SpellBook.h
    Description:    Header file for the SpellBook class. This class represents a spell book,
    which is a type of book that has an additional attribute, canTalk, indicating whether the
    spell book can talk. The class includes constructors, a destructor, a getter for
    the canTalk attribute, and overrides for the getRealPrice and str virtual functions
    from the Book class.
*/
#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <string>
#include "Book.h"
using namespace std;

class SpellBook : public Book
{
private:
    bool canTalk;

public:
    // Constructors
    /**
     * @brief Construct a default SpellBook object.
     * @param None.
     * @return None.
     */
    SpellBook();

    /**
     * @brief Construct a SpellBook object with explicit values.
     * @param gname The spell book title.
     * @param gprice The base price of the spell book.
     * @param cantalkparam Whether the spell book can talk.
     * @return None.
     */
    SpellBook(string gname, double gprice, bool cantalkparam);

    /**
     * @brief Construct a SpellBook object from a formatted text line.
     * @param text A line in the format: s <title possibly with spaces> <price> <canTalk>.
     * @return None.
     */
    SpellBook(string text);
    // Destructor
    /**
     * @brief Destroy the SpellBook object.
     * @param None.
     * @return None.
     */
    ~SpellBook() override;
    // Getters
    /**
     * @brief Check whether the spell book can talk.
     * @param None.
     * @return True if the spell book can talk; otherwise false.
     */
    bool getCanTalk();
    // Virtual functions
    /**
     * @brief Compute the real price for a spell book.
     * @param None.
     * @return The base price, with a 10% increase when the spell book can talk.
     */
    double getRealPrice() override;

    /**
     * @brief Build a display string for the spell book.
     * @param None.
     * @return A formatted string containing type label, name, and real price.
     */
    string str() override;
};

#endif
