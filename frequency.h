#ifndef frequency_H
#define frequency_H

#include<iostream>
#include<cmath>
#include<string>

#include "InputValidation.h"

using namespace std;

int Frequency() {
    cout << "Considering your repayment schedule, how often per year would you like the installments?\n";
    cout << "Available rate options are:\n";
    cout << "[1] annually \n[2] semi-annually \n[3] quarterly \n[4] monthly\n";
    cout << "Please, select by entering the number corresponding to your choice: ";
    int f = ChoiceOption(1,4);

    if (f == 1) {
        cout << "\nYou selected annual repayment rate.\n";
    } else if(f == 2) {
        cout << "\nYou selected semi-annual repayment rates.\n";
    } else if(f == 3) {
        cout << "\nYou selected quarterly repayment rates.\n";
        f = 4;
    } else if(f == 4) {
        cout << "\nYou selected monthly repayment rates.\n";
        f = 12;
    } else {
        cout<<"ERROR. Something went wrong, please restart the program.";
    }

    return f;
}


#endif
