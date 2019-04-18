#ifndef SaveVersion1_H
#define SaveVersion1_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

/*Final project: Loan Payment Schedule
Date 17th April 2019
CSV Output file*/

void SaveVersion1(int start[],int n,int pvb[], int p[], int r[], int interest[], int pmt[], int pve[], int f)
{
    char sep=';';
    int i;

    ofstream csvFile;
    ofstream outputFile;
    csvFile.open ("loanschedule1.csv");

    //Headlines
    csvFile << "Due date" << sep << "Opening balance" << sep << "Principal" << sep << "Interest rate" << sep << "Interest" << sep << "Instalment" << sep << "Closing Balance\n";
    csvFile << "n" << sep << "PV" << sep << "P" << sep << "r" << sep << "Int" << sep << "PMT" << sep <<"PV\n";

    //Creating a loop that inserts the data

    for (int  i= 0; i <n; i++) //smaller than n is fine because array starts at 0
    {
        csvFile << start[0] << "/" << start[1] << sep << pvb[i]  << sep << p[i] << sep << r[i] << sep << interest[i] << sep << pmt[i] << sep << pve[i] <<"\n";
        DateIncreasement(start, f);

    }
    csvFile.close();
    cout<<"The csv-file was successfully saved\n";
}


    
    
    
