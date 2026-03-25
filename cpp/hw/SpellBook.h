// Spellbook class
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
    SpellBook();
    SpellBook(string gname, double gprice, bool cantalkparam);
    SpellBook(string text);
    // Destructor
    ~SpellBook();
    // Getters
    bool getCanTalk();
    // Virtual functions
    double getRealPrice();
    string str();
};

#endif
