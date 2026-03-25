// Spellbook.cpp
#include <sstream>
#include <string>
#include <vector>
#include "SpellBook.h"
using namespace std;

// SpellBook class
//  Constructors
SpellBook::SpellBook() : Book()
{
    this->canTalk = true;
}
SpellBook::SpellBook(string gname, double gprice, bool cantalkparam) : Book(gname, gprice)
{
    this->canTalk = cantalkparam;
}
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
SpellBook::~SpellBook()
{
}
// Getters
bool SpellBook::getCanTalk()
{
    return this->canTalk;
}
// Virtual functions
double SpellBook::getRealPrice()
{
    if (canTalk)
    {
        return this->getPrice() * 1.1;
    }
    return this->getPrice();
}
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