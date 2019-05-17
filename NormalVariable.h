#ifndef NormalVariable_H
#define NormalVariable_H

#include<iostream>
#include<ctime>
#include<cmath>
#include<stdlib.h>

using namespace std;

double * NormalVar(double mean = 0, double std = 1, int n = 1)
{
	double s, u, v, z1;

    double* b = new double[n];

	srand((unsigned) time(0));

	for (int i=0; i<n ; i++)
    {
        do 	{
            u = 2 * ( double(rand()) / RAND_MAX ) - 1;
            v = 2 * ( double(rand()) / RAND_MAX ) - 1;
            s = pow(u,2) + pow(v,2);
        } while (s > 1);

        z1 = (u * sqrt( ( -2*log(s) ) / s )) * std + mean ;
        b[i] = z1;
    }
	return b;
}

#endif
