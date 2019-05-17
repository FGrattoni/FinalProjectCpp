#include <iostream>
#include <cmath>

#include "InputValidation.h"
#include "MissingElementFI.h"
#include "frequency.h"
#include "SaveVersion1.h"
#include "SaveVersion2.h"
#include "startingdate.h"
#include "DateIncreasement.h"
#include "NormalVariable.h"

using namespace std;


int main()
{
    bool exitprogram = false;
    int n;
    double* data;

    system("CLS");
    cout << "Welcome in the program to compute loan's repayment schedule." << endl;
    int* start = Start(0);
    cout << "The selected starting date is: " << start[0] << "/" << start[1] << "\n\n";

    int f = Frequency();

    //Choosing between the fixed installment and fixed principal case
    int firstfix=0;
    cout << "Which case would you like to consider?\n";
    cout << "[1] fixed installments;\n";
    cout << "[2] fixed principal.\n";
    cout << "[3] exit the program.\n";
    cout << "Select by entering the number corresponding to your choice: ";
    firstfix = ChoiceOption(1, 3);

    switch (firstfix)
    {
        case 1:
        {
            // FIXED INSTALLMENTs CASE
            data = MissingElementFI(0, f);
            n = data[2];
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
            pvb[n-1] = pve[n-2];
            interest[n-1] = roundf(pvb[n-1] * r * 100) / 100;
            p[n-1] = pvb[n-1];
            pve[n-1] = pvb[n-1] - p[n-1];
            pmt[n-1] = pvb[n-1] + interest[n-1];

            SaveVersion1(start, n, pvb, p, r, interest, pmt, pve, f);
            break;
        }
        case 2:
            //FIXED PRINCIPAL CASE
        {
            int fixedinterest;
            cout << "You would prefer a fixed interest rate or a floating one?" << endl;
            cout << "[1] floating interest rate;" << endl;
            cout << "[2] fixed interest rate." << endl;
            cout << "[3] exit the program." << endl;
            cout << "    " << endl;
            cout << "Select by entering the number corresponding to your choice: ";
            fixedinterest = ChoiceOption(1, 3);

            switch(fixedinterest)
            {
                case 1:
                {
                    //FLOATING RATE CASE
                    cout << "\nPlease, insert the amount of the loan: ";
                    double PV = RealInputLowerBound(0);
                    cout << "\nPlease, enter the number of payments: ";
                    int n = ChoiceOption(1, 999);
                    double P = PV/n;
                    cout << "\nThe fixed installment is of " << P << " euros." << endl;

                    double pvb[n];
                    pvb[0] = PV;
                    double interest[n];
                    double pmt[n];
                    double pve[n];

                    cout << "\nPlease, enter the fixed margin in percentage (suggested is 3 = 3%): ";
                    double m = RealInputBounded(0, 100);

                    double b[n];

                    for(int i=0 ; i<n ; i++)
                    {
                        if (i!=0)
                            pvb[i] = pve[i-1];
                        b[i] = NormalVar(3, 0.5);
                        interest[i] = roundf( (b[i]+m)/f * pvb[i] )  / 100;
                        pmt[i] = P + interest[i];
                        pve[i] = pvb[i] - P;
                    }

                    SaveVersion2(start, n, pvb, P, m, b, interest, pmt, pve, f);
                }

                case 2:
                {
                    cout << "\nPlease, insert the amount of the loan: ";
                    double PV = RealInputLowerBound(0);
                    cout << "\nPlease, enter the number of payments: ";
                    int n = ChoiceOption(1, 999);
                    double P = PV/n;
                    cout << "\nThe fixed installment is of " << P << " euros." << endl;

                    double pvb[n];
                    pvb[0] = PV;
                    double interest[n];
                    double pmt[n];
                    double pve[n];

                    cout<<"\nWhat should be the yearly fixed interest rate? \nPlease enter number as percentage: ";
                    double r = RealInputBounded(0,100);
                    r = (r/100)/f;
                    double p[n];
                    for(int i=0 ; i<n ; i++)
                    {
                        if (i!=0)
                            pvb[i] = pve[i-1];
                        p[i] = P; // needed for the output of the file
                        interest[i] = roundf(pvb[i] * r * 100) / 100;
                        pmt[i] = P + interest[i];
                        pve[i] = pvb[i] - P;
                    }

                    SaveVersion1(start, n, pvb, p, r, interest, pmt, pve, f);
                }
                case 3:
                {
                    break;
                }
            }
        }

        case 3:
        {
            break;
        }
    }

    cout << '\n' << "Thank you for using this program";
    return 0;
}
