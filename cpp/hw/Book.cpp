// Book.cpp
#include <iostream>
#include "Book.h"
using namespace std;

// Book Class
// Constructor
Book::Book()
{
    this->name = "";
    this->price = 100;
}
Book::Book(string btitle, double gprice)
{
    this->name = btitle;
    this->price = gprice;
}
Book::Book(string text)
{
    // splits on spaces, discards leading 'b' and uses next token as name and third token as price
    size_t pos1 = text.find(' ');
    size_t pos2 = text.find(' ', pos1 + 1);
    this->name = text.substr(pos1 + 1, pos2 - pos1 - 1);
    this->price = stod(text.substr(pos2 + 1));
}
// Destructor
Book::~Book()
{
}
// Getters
string Book::getName()
{
    return this->name;
}
double Book::getPrice()
{
    return this->price;
}
// Setters
void Book::setName(string name)
{
    this->name = name;
}
void Book::setPrice(double price)
{
    this->price = price;
}
// Virtual functions
double Book::getRealPrice()
{
    return this->price * 0.8;
}
string Book::str()
{
    return "Literature Book:" + this->name + ", price:" + to_string(this->price);
}

int main()
{
    Book book1;                 // Default constructor
    Book book2("Macbeth", 178); // Parameterized constructor
    Book book3("b hamlet 158"); // String constructor

    cout << "Book 1: " << book1.getName() << ", Price: " << book1.getPrice() << endl;
    cout << "Book 2: " << book2.getName() << ", Price: " << book2.getPrice() << endl;
    cout << "Book 3: " << book3.getName() << ", Price: " << book3.getPrice() << endl;

    return 0;
}