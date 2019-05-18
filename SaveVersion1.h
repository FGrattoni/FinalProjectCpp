#ifndef SaveVersion1_H
#define SaveVersion1_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "DateIncreasement.h"

using namespace std;

void SaveVersion1(int start[], int n, double pvb[], double p[], double r, double interest[], double pmt[], double pve[], int f)
{
    char sep=';';
    int i;


	// Normalize the data to two decimal numbers:
	for(int i = 0; i<n ; i++)
	{
		pvb[i] = roundf(pvb[i] * 100) / 100;
		p[i] = roundf(p[i] * 100) / 100;
		r = roundf(r * 100) / 100;
		interest[i] = roundf(interest[i] * 100) / 100;
		pmt[i] = roundf(pmt[i] * 100) / 100;
		pve[i] = roundf(pve[i] * 100) / 100;
	}


    ofstream csvFile;
    ofstream outputFile;
    csvFile.open ("LoanRepaymentSchedule.csv");

    //Headlines
    csvFile << "Due date" << sep << "Opening balance" << sep << "Principal" << sep << "Interest rate" << sep << "Interest" << sep << "Instalment" << sep << "Closing Balance\n";
    csvFile << "n" << sep << "PV" << sep << "P" << sep << "r" << sep << "Int" << sep << "PMT" << sep <<"PV\n";

    //Inserting data

    for (int i= 0; i <n; i++)
    {
        csvFile << start[0] << "/" << start[1] << sep << pvb[i]  << sep << p[i] << sep << r << sep << interest[i] << sep << pmt[i] << sep << pve[i] <<"\n";
        start = DateIncreasement(start, f);

    }
    csvFile.close();
    cout<<"\n--- The csv-file was successfully saved.\n";
}

#endif
