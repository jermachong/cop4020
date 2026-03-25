// Book.cpp
#include <sstream>
#include <vector>
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