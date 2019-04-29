#ifndef NormalVariable_H
#define NormalVariable_H

#include<iostream>
#include<ctime>
#include<cmath>
#include<stdlib.h>

using namespace std;

double NormalVar(double mean = 0, double std = 1)
{
	double s, u, v, z1;
	
	srand((unsigned) time(0));
	
	do 	{
		u = 2 * ( double(rand()) / RAND_MAX ) - 1;
		v = 2 * ( double(rand()) / RAND_MAX ) - 1;
		s = pow(u,2) + pow(v,2);
	} while (s > 1);
	
	z1 = (u * sqrt( ( -2*log(s) ) / s )) * std + mean ;
	
	return z1;	
}

#endif
