/*
    Author:       Jeremy Achong
    NID:          5124781
    Course:       COP4020

    Title:  SpellBook.cpp
    Description:    Implementation file for the SpellBook class. This class represents a spell book,
    which is a type of book that has an additional attribute, canTalk, indicating whether the
    spell book can talk. The class includes constructors, a destructor, a getter for
    the canTalk attribute, and overrides for the getRealPrice and str virtual functions
    from the Book class.
*/
#include <sstream>
#include <string>
#include <vector>
#include "SpellBook.h"
using namespace std;

// SpellBook class
//  Constructors
/**
 * @brief Construct a default SpellBook object.
 * @param None.
 * @return None.
 */
SpellBook::SpellBook() : Book()
{
    this->canTalk = true;
}

/**
 * @brief Construct a SpellBook object with explicit values.
 * @param gname The spell book title.
 * @param gprice The base price of the spell book.
 * @param cantalkparam Whether the spell book can talk.
 * @return None.
 */
SpellBook::SpellBook(string gname, double gprice, bool cantalkparam) : Book(gname, gprice)
{
    this->canTalk = cantalkparam;
}

/**
 * @brief Construct a SpellBook object from a formatted text line.
 * @param text A line in the format: s <title possibly with spaces> <price> <canTalk>.
 * @return None.
 */
SpellBook::SpellBook(string text) : Book(text)
{
    // format: s <title possibly with spaces> <price> <canTalk>
    istringstream iss(text);
    string typeToken;
    iss >> typeToken;

    string token;
    vector<string> tokens;
    while (iss >> token)
    {
        tokens.push_back(token);
    }

    if (tokens.size() >= 3)
    {
        string canTalkToken = tokens.back();
        tokens.pop_back();

        string priceToken = tokens.back();
        tokens.pop_back();

        this->setPrice(stod(priceToken));

        string title = tokens[0];
        for (size_t i = 1; i < tokens.size(); ++i)
        {
            title += " " + tokens[i];
        }
        this->setName(title);

        this->canTalk = (canTalkToken == "1");
    }
    else
    {
        this->setName("");
        this->setPrice(0);
        this->canTalk = false;
    }
}
// Destructor
/**
 * @brief Destroy the SpellBook object.
 * @param None.
 * @return None.
 */
SpellBook::~SpellBook()
{
}
// Getters
/**
 * @brief Check whether the spell book can talk.
 * @param None.
 * @return True if the spell book can talk; otherwise false.
 */
bool SpellBook::getCanTalk()
{
    return this->canTalk;
}
// Virtual functions
/**
 * @brief Compute the real price for a spell book.
 * @param None.
 * @return The base price, with a 10% increase when the spell book can talk.
 */
double SpellBook::getRealPrice()
{
    if (canTalk)
    {
        return this->getPrice() * 1.1;
    }
    return this->getPrice();
}

/**
 * @brief Build a display string for the spell book.
 * @param None.
 * @return A formatted string containing type label, name, and real price.
 */
string SpellBook::str()
{
    // if can talk is false, "Spell Book:" otherwise "Speaking Book:"
    if (this->canTalk)
    {
        return "Speaking Book:" + this->getName() + " price:" + to_string(this->getRealPrice());
    }
    return "Spell Book:" + this->getName() + " price:" + to_string(this->getRealPrice());
}
// int main()
// {
//     SpellBook spellbook1; // Default constructor
//     cout << spellbook1.str() << endl;

//     SpellBook spellbook2("The Art of Magic", 29.99, true); // Parameterized constructor
//     cout << spellbook2.str() << endl;

//     SpellBook spellbook3("s The Book of Spells 19.99 0"); // String constructor
//     cout << spellbook3.str() << endl;

//     SpellBook spellbook4("s The Enchanted Grimoire 39.99 1"); // String constructor with canTalk true
//     cout << spellbook4.str() << endl;

//     return 0;
// }