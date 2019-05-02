#include<iostream>
#include<cmath>
#include <stdio.h>


using namespace std;
int ValidInput(int lbound, int ubound)
{
 int x;
 cin >> x;
 
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Bad entry. Enter a NUMBER: ";
        cin >> x;
    }

    if(x<lbound || x>ubound)
    {
        cout << "error";
        ValidInput(lbound, ubound); 
    }
        
    return x;
}

        
int main()
 {
    ValidInput(1,4);
    
    }
