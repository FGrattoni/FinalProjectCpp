#ifndef InputValidation.h
#define InputValidation.h

#include <iostream>
#include <string>

using namespace std;

// Verifies that the input when choosing an option is valid
int ChoiceOption(int lbound, int ubound) 
{
    string x, tempStr = "";
    int y;
    int error = 0;
    
    do 
    {
        if (error == 1)
            cout << "Error. You inserted an invalid input. Please try again: ";
        else if (error == 2)
            cout << "Error. You should choose an option between " << lbound << " and " << ubound << ". Please try again: ";
            
        cin >> x;
        
        tempStr = "";
        error = 0;
        for (char c : x)
        {
            if (isdigit(c)) tempStr += c;
            else error = 1;
        }
        
        if (error==0) 
        {
            y = stoi(tempStr);
            if (y < lbound || y > ubound) 
            {
                error = 2;
            }
        }
    } while (error != 0);
    
    return y;
}

#endif
