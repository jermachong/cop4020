#include<iostream> 

int main()
{
    int x, y;
    int sum;
    std::string c;
    std::cout << "Type a number: ";
    std::cin >> x;
    std::cout << "Type another number: ";
    std::cin >> y;
    sum = x + y;
    std::cout << "Type a string : ";
    std::cin >> c;
    std::cout << "Sum is: " << sum << " " << c << std::endl;
    return 0;
}