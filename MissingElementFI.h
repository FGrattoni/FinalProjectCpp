#include <iostream>
#include <cmath>

using namespace std;

void MissingElementFI () {

    int i;
    double PMT, PV, n, r;
    cout << "This program calculate the missing element for the Fixed Installment case." << endl;
    cout << "In order to do so, which one of the four component you don't want to insert manually?" << endl;
    cout
            << " 1 = PV (Closing Balance) \n 2 = PMT (Fixed Installment) \n 3 = n (Number of Payment) \n 4 = r (Fixed Interest Rate)\n";
    cout << "Insert your choice by the provided numbers: \n";
    cin >> MissingElementFI;

    if ( MissingElementFI == 1 ) {
        cout << "You choose not to insert PV, Closing Balance.\n";
        cout << "Please insert PMT. \n";
        cin >> PMT;
        cout << "Please insert n.\n";
        cin >> n;
        cout << "Please insert r.\n";
        cin >> r;

        double CalculatePV (long precision){

            PV = (double) 1 / [PMT * [r * ( 1 + (double)(1 / (1+r)^n -1))]

            return PV;
        }
    } else if ( MissingElementFI == 2 ) {
        cout << "You choose not to insert PMT, Fixed Installment.\n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert n.\n";
        cin >> n;
        cout << "Please insert r.\n";
        cin >> r;

        double CalculatePMT (long precision){

            PMT = r*[1 + (double)(1 / (1+r)^n -1) ] * PV

            return PMT;
        }
    } else if ( MissingElementFI == 3 ) {
        cout << "You choose not to insert n, number of payment\n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert PMT.\n";
        cin >> PMT;
        cout << "Please insert r.\n";
        cin >> r;

        double Calculaten (long precision){

            n = ((double)log(PMT / (PMT - r * PV) / log(1 + n)

            return n;
        }
    } else if ( MissingElementFI == 4 ) {
        cout << "You choose not to insert r, fixed interest rate \n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert PMT.\n";
        cin >> PMT;
        cout << "Please insert n.\n";
        cin >> n;
    } else {
        cout << "Please insert a valid input.\n\n";
        MissingElementFI (i = 1);
    }


}
