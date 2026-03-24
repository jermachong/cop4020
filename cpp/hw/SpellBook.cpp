// Spellbook.cpp
#include <iostream>
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
        return "Speaking Book:" + this->getName() + ", price:" + to_string(this->getPrice()) + ", can talk: true";
    }
    return "Spell Book:" + this->getName() + ", price:" + to_string(this->getPrice()) + ", can talk: false";
}