#ifndef SaveVersion2_H
#define SaveVersion2_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

/*Final project: Loan Payment Schedule
Date 17th April 2019
CSV Output file 2*/

void SaveVersion2 (int start[],int n,int pvb[], int p[], int m [], int b[], int r[], int interest[], int pmt[], int pve[], int f){
    char sep = ';';
    int i;

    ofstream csvFile;
    ofstream outputFile;
    csvFile.open("loanschedule2.csv");

    //Headlines
    csvFile << "Due date" << sep << "Opening balance" << sep << "Principal" << sep << "Margin" << sep << "Benchmark"
            << sep << "Interest rate" << sep << "Interest" << sep << "Instalment" << sep << "Closing Balance\n";
    csvFile << "n" << sep << "PV(i-1)" << sep << "P" << sep << "M" << sep << "B" << sep << "r" << sep << "Int" << sep
            << "PMT" << sep << "PV(i)\n";

    //Filling the schedule with data
    for (int i = 0; i < n; i++)
    {
        csvFile << start[0] << "/" << start[1] << sep << pvb[i] << sep << p[i] << sep << m[i] << sep << b[i] << sep
                << r[i] << sep << interest[i] << sep << pmt[i] << sep << pve[i] << "\n";
        DateIncreasement(start, f);
    }
    
    csvFile.close();
    cout<<"The csv-file Version 2 was successfully saved\n";
}
