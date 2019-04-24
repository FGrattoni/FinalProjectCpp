#ifndef frequency_H
#define frequency_H

#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int Frequency(int i=0) {
    int f;
    if (i == 0){
    cout << "Hello," << endl;
    cout << "Considering your repayment schedule, how often would you like install repayment rates install payments per year?\n";
    cout << "Available rate options are:\n";
    }
    cout << " 1 = annually \n 2 = semi-annually \n 3 = quarterly \n 4 = monthly\n";
    cout << "Insert your choice by the provided numbers: \n";
    cin >> f;

    if (f == 1) {
    cout<<"You selected annual repayment rate\n";
    } else if(f == 2) {
        cout<<"You selected semi-annual repayment rates\n";
    } else if(f == 3) {
        cout<<"You selected quarterly repayment rates\n";
        f = 4;
    } else if(f == 4) {
        cout<<"You selected monthly repayment rates\n";
        f = 12;
    } else {
        cout<<"Please insert a valid input.\n\n";
        Frequency(i = 1);
    }
    
    return f;
}


#endif
