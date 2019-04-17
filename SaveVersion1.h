#ifndef SaveVersion1_H
#define SaveVersion1_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;



/*Final project: Loan Payment Schedule
Date 17th April 2019
CSV Output file

! Tried to solve the date issue....

 Create an array int exampleArray[5] = {1, 64, 34, 12, 9}
 Create an multidimensional array [j][i]

 */



void SaveVersion1()
{
    char sep=";";

    ofstream csvFile;
    ofstream outputFile;
    csvFile.open ("loanschedule1.csv");

    // create some variables for demonstration
    int i;
    /*int pvb, p, r, pmt, pve, n; 
	pvb=opening balance beginning, 
	p=principal, 
	r= interest rate, 
	pmt= instalment, 
	pve=closing balance
    Variables are available as arrays from exercise before.... or created in another function
     */

    csvFile << "Due date" << sep << "Opening balance" << sep << "Principal" << sep << "Interest rate" << sep << "Interest" << sep << "Instalment" << sep << "Closing Balance\n";
    csvFile << "n" << sep << "PV" << sep << "P" << sep << "r" << sep << "Int" << sep << "PMT" << sep <<"PV\n";

    //Creating a loop that inserts the data

    for (int  i= 0; i <n; i++) //smaller than n is fine because array starts at 0
    {
        csvFile << start[0] << "/" << start[1] << sep << pvb[i]  << sep << p[i] << sep << r[i] << sep << interest[i] << sep << pmt[i] << sep << pve[i] <<"\n";

        //My idea for creating a variable of the date
        if (f==1){
            start[1]+=1;
        }else if(f==2) {
            start[0] += 6;
            if (start[0] > 12){
                start[0] -= 12;
                start[1]++;
            }
        }else if(f==3){
            start[0]+=4;
            if (start[0]>12){
                start[0] -= 12;
                start[1]++;
            }
        }else if(f==4){
            start[0]++;
            if (start[0]>12){
                start[0] -= 12;
                start[1]++;
            }
        }else{
                cout << "It occurs a problem with the date";
        }
    }
    csvFile.close();
    cout<<"The csv-file was successfully saved\n";
}


void SaveVersion2 (){
    char sep=";";

    ofstream csvFile;
    ofstream outputFile;
    csvFile.open ("loanschedule2.csv"); //Should names differ for the different versions? Is this something that should change regarding the case?

    // create some variables for demonstration
    int i;
    /*int pvb, p, r, pmt, pve, n; pvb=opening balance beginning, p=principal, r= interest rate, pmt= instalment, pve=closing balance
    Variables are available as arrays from exercise before.... or created in another function
     */

    csvFile << "Due date" << sep << "Opening balance" << sep << "Principal" << sep << "Margin" << sep << "Benchmark" << sep << "Interest rate" << sep << "Interest" << sep << "Instalment" << sep <<"Closing Balance\n";
    csvFile << "n" << sep << "PV(i-1)" << sep << "P" << sep << "M" << sep <<  "B" << sep << "r"<< sep << "Int" << sep << "PMT" << sep <<"PV(i)\n";
    for (int  i= 0; i <n; i++) //smaller than n is fine because array starts at 0
    {
        csvFile << start[0] <<"/"<< start[1] << sep << pvb[i] << sep << p[i] << sep << m[i] << sep <<  b[i] << sep << r[i] << sep << interest[i]<< sep << pmt[i] << sep << pv[i] << "\n";

        if (f==1){
            start[1]+=1;
        } else if(f==2) {
            start[0] += 6;
            if (start[0] > 12) {
                start[0] -= 12;
                start[1]++;
            }
        }else if(f==3){
            start[0]+=4;
            if (start[0]>12){
                start[0] -= 12;
                start[1]++;
            }
        }else if(f==4){
            start[0]++;
            if (start[0]>12) {
                start[0] -= 12;
                start[1]++;
            }
        } else {
            cout << "There exists a problem with the variable: date" << ;
        }

    }

    csvFile.close();
    cout<<"The csv-file was successfully saved\n";
}
