#ifndef MissingElementFI_H
#define MissingElementFI_H

#include<iostream>
#include<cmath>

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

    cout << "\nYou choose the Fixed Installment case." << endl;
    cout << "In order to compute the payment schedule, the program needs the initial amount of the loan, the fixed installment amount, the number of payments and the interest rate applied to the due amount." << endl;
    cout << "Which one of the four component you don't want to insert manually?" << endl;
    cout << "[1] PV (Opening balance) \n";
    cout << "[2] PMT (Fixed installment amount)\n";
    cout << "[3] n (Number of payments) \n";
    cout << "[4] r (Fixed annual interest rate)\n";
    cout << "Insert your choice by inserting one of the provided numbers: ";
    MissingElement = ChoiceOption(1,4);

    if ( MissingElement == 1 )
	{
        cout << "You choose not to insert PV, the opening balance.\n\n";
        cout << "Please insert PMT, the installment amount: ";
        PMT = RealInputLowerBound(0);
        cout << "Please insert n, the number of payments: ";
        n = ChoiceOption(1, 999);
        cout << "Please insert annual r, the yearly interest rate (given in %): ";
        r = RealInputBounded(0, 100);
        r = (r/100) / f;
        cout << "Interest rate for every installment is: " << r*100 << "%." << endl;

		PV = PVComputation(PMT, n, r);
		cout << "\nThe PV (opening balance) is: " << PV;

    } else if ( MissingElement == 2 )
	{
        cout << "You chooe not to insert PMT, the fixed installment amount.\n\n";
        cout << "Please insert PV, the amount of the loan: ";
        PV = RealInputLowerBound(0);
        cout << "Please insert n, the number of payments: ";
        n = ChoiceOption(0, 999);
        cout << "Please insert annual r, the yearly interest rate (given in %): ";
        r = RealInputBounded(0, 100);
        r = (r/100) / f;
        cout << "Interest rate for every installment is: " << r*100 << "%." << endl;

		PMT = PMTComputation(PV, n, r);
		cout << "\nThe PMT (fixed installment amount) is: " << PMT << "." << endl;

    } else if ( MissingElement == 3 ) {
        cout << "You choose not to insert n, the number of payments.\n\n";
        cout << "Please insert PV, the amount of the loan: ";
        PV = RealInputLowerBound(0);
        cout << "Please insert PMT, the fixed installed amount: ";
        PMT = RealInputBounded(0, PV);
        cout << "Please insert annual r, the yearly interest rate (given in %): ";
        r = RealInputBounded(0, 100);
        r = (r/100) / f;
        cout << "Interest rate for every installment is: " << r*100 << "%." << endl;

		n = NComputation(PV, PMT, r);
		cout << "\nThe n (number of payments) is: " << n << "." << endl;

    } else if ( MissingElement == 4 ) {
        cout << "You choose not to insert r, the fixed interest rate.\n\n";
        cout << "Please insert PV, the amount of the loan: ";
        PV = RealInputLowerBound(0);
        cout << "Please insert PMT, the fixed installment amount: ";
        PMT = RealInputBounded(0, PV);
        cout << "Please insert n, the number of payments: ";
        n = ChoiceOption(0, 999);

        r = InterestComputation(PV, PMT, n);
        cout << "\nThe r (fixed interest rate for every payment) is: " << r*100 << "%.";
        cout << "\nThe annual fixed interest rate would be: " << r*f*100 << "%." << endl;

    }

    data[0] = PV;
	data[1] = PMT;
    data[2] = n;
    data[3] = r;

	return data;

}


#endif
