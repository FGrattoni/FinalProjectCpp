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
	n = log(PMT/(PMT-r*PV))/log(1+r);
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


double * MissingElementFI(int i = 0) 
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
	
    cout << " 1 = PV (Opening balance) \n 2 = PMT (Fixed installment amount) \n 3 = n (Number of payments) \n 4 = r (Fixed interest rate)\n";
    cout << "Insert your choice by the provided numbers: \n";
    cin >> MissingElement;

    if ( MissingElement == 1 ) 
	{
        cout << "You choose not to insert PV, the opening balance.\n";
        cout << "Please insert PMT. \n";
        cin >> PMT;
        cout << "Please insert n.\n";
        cin >> n;
        cout << "Please insert r.\n";
        cin >> r;
		
		PV = PVComputation(PMT, n, r);
		cout << "\nThe PV (opening balance) is: " << PV;
		
    } else if ( MissingElement == 2 ) 
	{
        cout << "You choose not to insert PMT, the fixed installment amount.\n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert n.\n";
        cin >> n;
        cout << "Please insert r.\n";
        cin >> r;
		
		PMT = PMTComputation(PV, n, r);
		cout << "\nThe PMT (fixed installment amount) is: " << PMT;
		
    } else if ( MissingElement == 3 ) {
        cout << "You choose not to insert n, the number of payments.\n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert PMT.\n";
        cin >> PMT;
        cout << "Please insert r.\n";
        cin >> r;
		
		n = NComputation(PV, PMT, r);
		cout << "\nThe n (number of payments) is: " << n;
		
    } else if ( MissingElement == 4 ) {
        cout << "You choose not to insert r, the fixed interest rate.\n";
        cout << "Please insert PV. \n";
        cin >> PV;
        cout << "Please insert PMT.\n";
        cin >> PMT;
        cout << "Please insert n.\n";
        cin >> n;
        
        r = InterestComputation(PV, PMT, n);
        cout << "\nThe r (fixed interest rate) is: " << r;
        
    } else {
        cout << "Please insert a valid input.\n\n";
        MissingElementFI(i = 1);
    }
    
    data[0] = PV;
	data[1] = PMT;
    data[2] = n;
    data[3] = r;
	
	return data;
    
}


#endif
