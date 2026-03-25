// Book Class
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
    // Consstructor
    Book();
    Book(string btitle, double gprice);
    Book(string text);
    // Destructor
    virtual ~Book();
    // Getters
    string getName();
    double getPrice();
    // Setters
    void setName(string name);
    void setPrice(double price);
    // Virtual functions
    virtual double getRealPrice();
    virtual string str();
};

#endif