#ifndef fourth_H
#define fourth_H

#include<iostream>
#include<cmath>

using namespace std;

// CASE 1: PV computation
double PVComputation(int n, double PMT, double r)
{
	double PV;
	double temp;
	temp = pow(1+r,n);
	PV = PMT * ((temp-1)/(r*temp));
	return PV;
}

// CASE 2: PMT computation
double PMTComputation(double PV, int n, double r)
{
	double PMT;
	PMT = r * (1+ 1/(pow(1+r,n)-1)) * PV;
	return PMT;
}

// CASE 3: n computation
double NComputation(double PV, double PMT, double r)
{
	int n;
	n = log(PMT/(PMT-r*PV))/log(1+r);
	return n;
}

// CASE 4: interest rate computation with secant algorithm
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
		r = temp;
	}

	return rNext;

}

#endif
