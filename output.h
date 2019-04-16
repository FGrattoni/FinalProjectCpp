#ifndef output_H
#define output_H

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include<limits>
#include<string>

using namespace std;




void OutputFixedR()
{
}

void OutputFloatingR()
{
}

void SaveToFile() {

    ofstream textFile;
    textFile.open ("output.txt");
    textFile << "The force is strong with you.\n";
    textFile << "A powerful Sith you will become.\n";
    textFile << "Henceforth, you shall be known as Darth...Vader.\n";
    textFile.close();

    char listSeparator=';';

    ofstream csvFile;
    csvFile.open ("output.csv");
    csvFile << "col1"<< listSeparator <<"col2"<< listSeparator <<"col3\n";
    csvFile << "11"<< listSeparator <<"12"<< listSeparator <<"13\n";
    csvFile << "21"<< listSeparator <<"22"<< listSeparator <<"23.\n";
    csvFile.close();

    cout << "Files saved!" << endl;

}

#endif
