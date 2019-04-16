#include <iostream>
//#include <fstring>
#include <cmath>

/*
Final project: Loan Payment Schedule
Date 16th April 2019
Names Giada, Fabio, Lillian 
 ///**/


using namespace std;

// General Set-up Environment

//Create Rate of Repayment

void Frequency(int i=0) {
    double f;
    if (i==0){
    cout << "Hello," << endl;
    cout
            << "Considering your repayment schedule, how often would you like install repayment rates install payments per year?\n";
    cout << "Available rate options are:\n";
    }
    cout << " 1 = annually \n 2 = semi-annually \n 3 = quarterly \n 4 = monthly\n";
    cout << "Insert your choice by the provided numbers: \n";
    cin >> f;

    if (f==1){
    cout<<"You selected annual repayment rate\n";
    }else if(f==2){
        cout<<"You selected semi-annual repayment rates\n";
    }else if(f==3){
        cout<<"You selected quarterly repayment rates\n";
    }else if(f==4){
        cout<<"You selected monthly repayment rates\n";
    }else {
        cout<<"Please insert a valid input.\n\n";
        Frequency(i=1);
    }
}


// 3.1 Exercises
// Program answering the question whether the number is prime or not
int main()
{
    Frequency();
    return 0;
}
