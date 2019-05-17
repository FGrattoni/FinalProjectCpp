#ifndef FloatingRate_hpp
#define FloatingRate_hpp


#include<iostream>
#include<cmath>
#include <stdio.h>


using namespace std;

// Fixed principal

double * Floatingrate(int i = 0, int f = 1)
{

    double PV, P,m;
    int Floatingrate,n;
    double* data = new double[2];

    cout << "This program calculates the missing values for the case of a Floating Rate. \n " << endl;
    cout << "In order to do so, what is the total of the loan taken? (in Euros) \n " << endl;
    cin >> PV;


    cout << "Please enter the fixed margin in percentage (e.g. 1 % = 1): \n "<< endl;
    cin >> m;

    cout << "Please enter the number of times a reinstallment is demanded: \n "<< endl;
    cin >> n;

    P=PV/n;

    data[0] = PV;
    data[1] = P;
    data[2] = n;
    data[3] = m;

    return data;
}

#endif
