#include <iostream>
//#include <fstring>
#include <cmath>


//TEMPORARY: used to display the arrays. (the function setw() )
#include <iomanip>
using std::setw;


#include "MissingElementFI.h"
#include "frequency.h"
#include "output.h"
#include "SaveVersion1.h"
#include "SaveVersion2.h"
#include "startingdate.h"
#include "DateIncreasement.h"

/*
Final project: Loan Payment Schedule
Date 16th April 2019
Names Giada, Fabio, Lillian 
*/


using namespace std;

int main()
{
    int f = Frequency();
    
    cout << "You would prefer a fixed installment or a fixed principal?" << endl;
    cout << "Select by entering the number corresponding to your choice:" << endl;
    cout << "[1] fixed installments;" << endl;
    cout << "[2] fixed principal." << endl;
    
    cout << "\n.. temporary .. " << endl;
	cout << "   There is no choice for the moment. The function is missing. \n\n";
	
	
	// need for ask wether Fixed installments
    // if fixed installments
    
	// FIXED INSTALLMENTs CASE
	double* data = MissingElementFI(0, f);

	int n = data[2];
	double r = data[3];
	double pmt = data[1];
	
	double pvb[n];
	pvb[0] = data[0];
	double p[n];
	double interest[n];
	double pve[n];
	for(int i=0 ; i<n ; i++)
	{
		if (i!=0)
		pvb[i] = pve[i-1];
		interest[i] = roundf(pvb[i] * r * 100) / 100;
		p[i] = pmt - interest[i];
		pve[i] = pvb[i] - p[i];
	}
	


	// THIS PART OF THE CODE IS JUST TO SEE THE TEMPORARY OUTPUT.
	cout << "\npvb" << setw(13) << "p" << setw(13) << "Interest" << setw(13) << "pmt" << setw(13) << "pve"<<  endl;                     
	for ( int i = 0; i<n; i++ )
		cout << setw(7)<< pvb[i] << setw(13) << p[i] << setw(13) << interest[i] << setw(13) << pmt << setw(13) << pve[i] << endl;

    return 0;
}
