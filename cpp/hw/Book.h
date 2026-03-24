// Book Class
#include <string>
using namespace std;
class Book
{
    string name;
    double price;

public:
    // Consstructor
    Book();
    Book(string btitle, double gprice);
    Book(string text);
    // Destructor
    ~Book();
    // Getters
    string getName();
    double getPrice();
    // Setters
    void setName(string name);
    void setPrice(double price);
    virtual double getRealPrice();
    virtual string str();
};