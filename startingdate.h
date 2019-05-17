#ifndef start_H
#define start_H

#include<iostream>
#include <ctime>
#include "InputValidation.h"

using namespace std;

int * Start(int i = 0)
{
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    int currMonth = timePtr->tm_mon + 1;
    int currYear = timePtr->tm_year + 1900;

	int* start = new int[2];
	if (i == 0) cout << "When would you like to start your repayment schedule? \n";
    cout<< "Please, enter the starting month [1-12]: ";
    start[0] = ChoiceOption(1, 12);
    cout<< "Please, enter the starting year [current year-2039]: ";
    start[1] = ChoiceOption(currYear, 2039);

    if ( (start[0] < currMonth) && (start[1] == currYear) )
    {
        cout << "Your input is not valid. Please, enter a date in the future.\n";
        Start(i=1);
    }

    return start;
}

#endif
