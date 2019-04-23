#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include<limits>
#include<string>

#include "MissingElementFI.h"
//#include "SaveVersion1.h"
#include "frequency.h"




using namespace std;



int main()
{
	int n;
//	n = Frequency();
	double PV, PMT, r;
	double temp;
		
	PV = 10000;
	PMT = 2309.75;
	n = 5;
	r = 0.05;

	temp = PVComputation(PMT, n, r);
	cout << "Computed PV is: " << temp << ", expected was: " << PV << endl;
	
	temp = PMTComputation(PV, n, r);
	cout << "Computed PMT is: " << temp << ", expected was: " << PMT << endl;
	
	temp = NComputation(PV, PMT, r);
	cout << "Computed n is: " << temp << ", expected was: " << n << endl;
	
	temp = InterestComputation(PV, PMT, n);
	cout << "Computed interest is: " << temp << ", expected was: " << r << endl;
	
	
	double* data = MissingElementFI();
	cout << "TEST\n" << "PV: " << data[0] << "\nPMT: " << data[1] << "\nn: " << data[2] << "\nr: " << data[3];

}
