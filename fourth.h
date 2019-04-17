#ifndef fourth.h
#define fourth.h

#include<iostream>
#include<cmath>

using namespace std;

double Function(double PV, double PMT, int n, double r)
{
	double temp;
	temp = r * (PV/PMT) * ( 1 + (1) / (pow(1+r,n) - 1) ) -1 ;
	return temp;	
}

double InterestComputation(double PV, double PMT, int n) 
{

	double r = 0.001, rNext = 1, temp;
	
	while(abs(Function(PV, PMT, n, rNext)) > 0.000001)
	{
		temp = rNext;
		rNext = rNext - (Function(PV, PMT, n, rNext)*(rNext-r))/(Function(PV,PMT,n,rNext)-Function(PV, PMT, n , r));
		cout << "r: " << r << " , temp: " << temp << " , rNext: " << rNext << " , Function is: " << Function(PV, PMT, n , rNext) << endl;
		r = temp;
	}

	cout << "Interest is: " << rNext;
	return rNext;

}

#endif
