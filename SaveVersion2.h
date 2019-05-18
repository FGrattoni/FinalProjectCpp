#ifndef SaveVersion2_H
#define SaveVersion2_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "DateIncreasement.h"

using namespace std;

void SaveVersion2 (int start[],int n, double pvb[], double p, double m, double b[], double interest[], double pmt[], double pve[], int f){
    char sep = ';';
    int i;

    ofstream csvFile;
    ofstream outputFile;
    csvFile.open("LoanRepaymentSchedule.csv");

    //Headlines
    csvFile << "Due date" << sep << "Opening balance" << sep << "Principal" << sep << "Margin" << sep << "Benchmark"
            << sep << "Interest rate" << sep << "Interest" << sep << "Instalment" << sep << "Closing Balance\n";
    csvFile << "n" << sep << "PV(i-1)" << sep << "P" << sep << "M" << sep << "B" << sep << "r" << sep << "Int" << sep
            << "PMT" << sep << "PV(i)\n";

    //Inserting data
    for (int i = 0; i < n; i++)
    {
        csvFile << start[0] << "/" << start[1] << sep << pvb[i] << sep << p << sep << m << sep << b[i] << sep
                << m+b[i] << sep << interest[i] << sep << pmt[i] << sep << pve[i] << "\n";
        DateIncreasement(start, f);
    }

    csvFile.close();
    cout<<"\n--- The csv-file was successfully saved.\n";
}

#endif
