#include <iostream>
#include <cmath>

using std::setw;

#include "InputValidation.h"
#include "MissingElementFI.h"
#include "frequency.h"
#include "SaveVersion1.h"
#include "SaveVersion2.h"
#include "startingdate.h"
#include "DateIncreasement.h"
#include "NormalVariable.h"

/*
Final project: Loan Payment Schedule
Date 16th April 2019
Names Giada, Fabio, Lillian
*/


using namespace std;

int main()
{
    cout << "Welcome in the program to compute loan's repayment schedule." << endl;
    int* start = Start(0);
    cout << "The selected starting date is: " << start[0] << "/" << start[1] << "\n\n";

    int f = Frequency();

    //Choosing between the fixed installment and fixed principal case
    int firstfix=0;
    cout << "Which case would you like to consider?\n";
    cout << "[1] fixed installments;\n";
    cout << "[2] fixed principal.\n";
    cout << "Select by entering the number corresponding to your choice: " << endl;
    firstfix = ChoiceOption(1, 2);

    if (firstfix == 1)
    {   // FIXED INSTALLMENTs CASE
	double* data = MissingElementFI(0, f);

	int n = data[2];
	double r = data[3];
	double pmt[n];
	pmt[0] = data[1];
	double pvb[n];
	pvb[0] = data[0];

	double p[n];
	double interest[n];
	double pve[n];
	for(int i=0 ; i<n-1 ; i++)
	{
		if (i!=0)
		pvb[i] = pve[i-1];
		interest[i] = roundf(pvb[i] * r * 100) / 100;
		p[i] = pmt[0] - interest[i];
		pve[i] = pvb[i] - p[i];
		pmt[i] = pmt[0];
	}
	// taking care of the LAST LINE
	pvb[n-1] = pve[n-2];
	interest[n-1] = roundf(pvb[n-1] * r * 100) / 100;
	p[n-1] = pvb[n-1];
	pve[n-1] = pvb[n-1] - p[n-1];
	pmt[n-1] = pvb[n-1] + interest[n-1];

	SaveVersion1(start, n, pvb, p, r, interest, pmt, pve, f);
    }

    else {    //FIXED PRINCIPAL CASE

    bool fixedinterest;
    cout << "You would prefer a fixed interest rate or a floating one?" << endl;
    cout << "[0] floating interest rate;" << endl;
    cout << "[1] fixed interest rate." << endl;
    cout << "Select by entering the number corresponding to your choice: ";
    fixedinterest = ChoiceOption(0, 1);

    cout << "\nPlease, insert the amount of the loan: ";
    double PV = RealInputLowerBound(0);
    cout << "Please, enter the number of payments: ";
    int n = ChoiceOption(1, 999);
    double P = PV/n;
    cout << "The fixed installment is of " << P << " euros." << endl;

    double pvb[n];
    pvb[0] = PV;
    double interest[n];
    double pmt[n];
    double pve[n];

    if(fixedinterest){
        cout<<"What should be the fixed interest rate? \nPlease enter number as percentage: ";
        double r = RealInputBounded(0,100);
        r /= 100;

        double p[n];

        for(int i=0 ; i<n ; i++){
            if (i!=0)
                pvb[i] = pve[i-1];
            p[i] = P; // needed for the output of the file
            interest[i] = roundf(pvb[i] * r * 100) / 100;
            pmt[i] = P + interest[i];
            pve[i] = pvb[i] - P;
        }

        SaveVersion1(start, n, pvb, p, r, interest, pmt, pve, f);

    }
    else {  //FLOATING RATE CASE
        cout << "Please, enter the fixed margin in percentage (suggested is 3 = 3%): ";
        double m = RealInputBounded(0, 100);

        double b[n];

        for(int i=0 ; i<n ; i++)
            {
                if (i!=0)
                    pvb[i] = pve[i-1];
                b[i] = NormalVar(3, 0.5);
                interest[i] = roundf( (b[i]+m) * pvb[i] )  / 100;
                pmt[i] = P + interest[i];
                pve[i] = pvb[i] - P;
            }

        SaveVersion2(start, n, pvb, P, m, b, interest, pmt, pve, f);
    }


    }

        return 0;
}
