#ifndef MissingElementFI_H
#define MissingElementFI_H

#include<iostream>
#include<cmath>
// Fabio> I only included in MissingElementFI,the sentence "the number of payments"
//  in the lines 103,118.148. It was missing!
using namespace std;

// CASE 1: PV computation
double PVComputation(double PMT, int n, double r)
{
	double PV;
	double temp;
	temp = pow(1+r,n);
	PV = PMT * ((temp-1)/(r*temp));
	return PV;
}

// CASE 2: PMT computation
double PMTComputation(double PV, int n, double r)
{
	double PMT;
	PMT = r * (1+ 1/(pow(1+r,n)-1)) * PV;
	return PMT;
}

// CASE 3: n computation
double NComputation(double PV, double PMT, double r)
{
	int n;
	double tempN;
	tempN = log(PMT/(PMT-r*PV))/log(1+r);

	tempN = roundf(tempN * 10000) / 10000;

	if ( fmod(tempN, 1) > 0.01 )
	{
		if ( fmod(tempN, 1) > 0.1 )
		{
			cout << "\nWarning! \nThe n computed is not a whole number. Therefore, we added a period more, which will have a smaller installment in order to extinguish the loan's debt.\n";
			tempN++;
		}
		else
		{
			cout << "\nWarning! \nThe n computed is not a whole number. Therefore, since after " << roundf(tempN) << " periods what is left to pay is a small amount we included it in the last payment.\n";
		}

		n = tempN;
	}
	else n = tempN;

	return n;
}

// CASE 4: interest rate computation with secant algorithm
double Function(double PV, double PMT, int n, double r)
{
	double temp;
	temp = r * (PV/PMT) * ( 1 + (1) / (pow(1+r,n) - 1) ) -1 ;
	return temp;
}

double InterestComputation(double PV, double PMT, int n)
{
	double r = 0.001, rNext = 1, temp;

	while(abs(Function(PV, PMT, n, rNext)) > 0.000001)
	{
		temp = rNext;
		rNext = rNext - (Function(PV, PMT, n, rNext)*(rNext-r))/(Function(PV,PMT,n,rNext)-Function(PV, PMT, n , r));
		r = temp;
	}

	return rNext;
}


double * MissingElementFI(int i = 0, int f = 1)
{
    double PMT, PV, n, r;
    int MissingElement;
    double* data = new double[4];

    if (i=0)
	{
    	cout << "This program calculates the missing element for the Fixed Installment case." << endl;
    	cout << "In order to do so, which one of the four component you don't want to insert manually?" << endl;
	} else
	{
		cout << "These are the possible inputs. Which one would you like NOT to insert?" << endl;
	}

    cout << " 1 = PV (Opening balance) \n 2 = PMT (Fixed installment amount) \n 3 = n (Number of payments) \n 4 = r (Fixed annual interest rate)\n";
    cout << "Insert your choice by the provided numbers: \n";
    cin >> MissingElement;

    if ( MissingElement == 1 )
	{
        cout << "You choose not to insert PV, the opening balance.\n";
        cout << "Please insert PMT. \n";
        cin >> PMT;
        cout << "Please insert n, the number of payments\n";
        cin >> n;
        cout << "Please insert annual r.\n";
        cin >> r;
        r = r / f;
        cout << "Interest rate for every installment is: " << r << "." << endl;

		PV = PVComputation(PMT, n, r);
		cout << "\nThe PV (opening balance) is: " << PV;

    } else if ( MissingElement == 2 )
	{
        cout << "You choose not to insert PMT, the fixed installment amount.\n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert n, the number of payments\n";
        cin >> n;
        cout << "Please insert annual r.\n";
        cin >> r;
        r = r / f;
        cout << "Interest rate for every installment is: " << r << "." << endl;

		PMT = PMTComputation(PV, n, r);
		cout << "\nThe PMT (fixed installment amount) is: " << PMT << "." << endl;

    } else if ( MissingElement == 3 ) {
        cout << "You choose not to insert n, the number of payments.\n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert PMT.\n";
        cin >> PMT;
        cout << "Please insert annual r.\n";
        cin >> r;
        r = r / f;
        cout << "Interest rate for every installment is: " << r << "." << endl;

		n = NComputation(PV, PMT, r);
		cout << "\nThe n (number of payments) is: " << n << "." << endl;

    } else if ( MissingElement == 4 ) {
        cout << "You choose not to insert r, the fixed interest rate.\n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert PMT.\n";
        cin >> PMT;
        cout << "Please insert n, the number of payments\n";
        cin >> n;

        r = InterestComputation(PV, PMT, n);
        cout << "\nThe r (fixed interest rate for every payment) is: " << r;
        cout << "\nThe annual fixed interest rate would be: " << r*f << endl;

    } else {
        cout << "Please insert a valid input.\n\n";
        MissingElementFI(i = 1, f);
    }

    data[0] = PV;
	data[1] = PMT;
    data[2] = n;
    data[3] = r;

	return data;

}


#endif