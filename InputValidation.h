#ifndef InputValidation.h
#define InputValidation.h

#include <iostream>
#include <string>
#include <stdlib.h>

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



// verifies that the input is a real number and inside the boundaries
double RealInputBounded( double lbound, double ubound ) 
{
    string x, tempStr = "";
    int error = 0;
    bool hitDecimal = 0, hitNegative = 0;
    double y;
    
    do 
    {
        if ( error == 1 )
            cout << "Error. You inserted an invalid input. Please try again: ";
        if ( error == 2 )
            cout << "Error. You should choose an option between " << lbound << " and " << ubound << ". Please try again: ";

        
        cin >> x;
        
        tempStr = "";
        error = 0;
        hitDecimal = 0;
        hitNegative = 0;
        
        for (char c : x)
        {
            if ( c=='.' && !hitDecimal )
            {
                hitDecimal = 1;
                hitNegative = 1;
            }
            else if ( c=='-' && !hitNegative)
                hitNegative = 1;
            else if( isdigit(c) )
                hitNegative = 1;
            else if( !isdigit(c) ) 
                error = 1;
        
            if (isdigit(c) || c=='.' || c=='-')
                tempStr += c;
            else error = 1;
        }
        
        if (error==0)
        {
            y = atof(tempStr.c_str());
            if (y <= lbound || y > ubound) 
            {
                error = 2;
            }
        }
        
    } while (error != 0);
    
    return y;
}




// verifies that the input is a real number greater than "lbound"
double RealInputLowerBound( double lbound = 0 ) 
{
    string x, tempStr = "";
    int error = 0;
    bool hitDecimal = 0, hitNegative = 0;
    double y;
    
    do 
    {
        if ( error == 1 )
            cout << "Error. You inserted an invalid input. Please try again: ";
        if ( error == 2 )
            cout << "Error. You should choose an option greater than " << lbound << ". Please try again: ";

        
        cin >> x;
        
        tempStr = "";
        error = 0;
        hitDecimal = 0;
        hitNegative = 0;
        
        for (char c : x)
        {
            if ( c=='.' && !hitDecimal )
            {
                hitDecimal = 1;
                hitNegative = 1;
            }
            else if ( c=='-' && !hitNegative)
                hitNegative = 1;
            else if( isdigit(c) )
                hitNegative = 1;
            else if( !isdigit(c) ) 
                error = 1;
        
            if (isdigit(c) || c=='.' || c=='-')
                tempStr += c;
            else error = 1;
        }
        
        if (error==0)
        {
            y = atof(tempStr.c_str());
            if (y <= lbound) 
            {
                error = 2;
            }
        }
        
    } while (error != 0);
    
    return y;
}



#endif
