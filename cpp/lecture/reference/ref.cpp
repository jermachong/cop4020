#include <iostream>
using namespace std;
#define globalBar 0 // A global variable
int globalVar = 0;  // A global variable
int &modifyGlobalVariable(int newValue)
{
    globalVar = newValue;
    return globalVar;
}
int main()
{
    int &ref = modifyGlobalVariable(42);
    cout << "ref Value after modification: "
         << ref << endl;
    // Modify the global variable again
    // using the reference
    ref = 100;
    cout << "New value of globalVar: " << globalVar;
    return 0;
}