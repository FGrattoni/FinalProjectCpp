#include<iostream>
#include<iomanip>
#include<cmath>
#include <cstdlib>
#include <limits>

using namespace std;

float fixedprinint(int option,int period_a,float inputs,float irate_a)
{
    float aux1,pv,pmt;
    aux1 = 1+1/(pow(1+irate_a,period_a)-1);
    switch (option)
    {
    case 1:
            //Present Value (PV) Number of Periods (n) Interest Rate (r)\n";
            pmt=inputs*aux1;
            return pmt;
    case 2:
            //PMT Number of Periods (n) Interest Rate (r)\n"
            pv=inputs/(irate_a*aux1);
            return pv;
    }
}


void fixedintinst()
{
    int periods,input=0;
    float pv,pmt=0;
    float irate=0;

    cout << "Fixed Interest Rate and Instalments Given 3 out 4 Variables\n";
    cout<<"1. Present Value (PV) Number of Periods (n) Interest Rate (r)\n";
    cout<<"2. Periodic Payment (PMT) Interest Rate (r) Number of Periods (n)\n";
    cout<<"3. Periodic Payment (PMT) Present Value (PV) Number of Periods (n)\n";
    cout<<"3. Periodic Payment (PMT) Present Value (PV) Interest Rate (r)\n";
    cout<<"5x . Exit\n";
    cout<<"Selection: ";
    cin>> input;

    switch ( input )
    {

    case 1:
        do
        {
            cout<<"Enter the Present Value (PV) >";
            cin >> pv;

        } while ((pv<1) || (pv>10000));

        do
        {
            cout<<"Enter the Number of Periods (n)>";
            cin >> periods;

        } while ((periods<1) || (periods > 100));

        do
        {
            cout<<"Enter the Interest Rate (r)>";
            cin >> irate;

        } while ((irate<0.1) || (irate > 15));

        pmt = fixedprinint(1,periods,pv,irate);
        cout<<"PMT > "<<pmt;

    break;

    case 2:
        do
        {
            cout<<"Enter the Periodic Payment (PMT) >";
            cin >> pmt;

        } while ((pmt<1) || (pmt>10000));
        do
        {
            cout<<"Enter the Number of Periods (n)>";
            cin >> periods;

        } while ((periods<1) || (periods > 100));

        do
        {
            cout<<"Enter the Interest Rate (r)>";
            cin >> irate;

        } while ((irate<0.1) || (irate > 15));

        pv = fixedprinint(2,periods,pmt,irate);
        cout<<"PV  "<<pv;
    break;

    case 3:
        do
        {
            cout<<"Enter the Periodic Payment (PMT) >";
            cin >> pmt;

        } while ((pmt<1) || (pmt>10000));

        do
        {
            cout<<"Enter the Present Value (PV) >";
            cin >> pv;

        } while ((pv<1) || (pv>10000));

        do
        {
            cout<<"Enter the Number of Periods (n) >";
            cin >> periods;

        } while ((periods <0.1) || (periods > 100));


        cout<<"Enter the Periodic Payment (PMT) >";
        cin >> pmt;
        cout<<"Enter the Present Value (PV) >";
        cin >> pv;
        cout<<"Enter the Number of Periods (n) >";
        cin >> periods;
       // irate = secant(3,pmt,pv,n);
        cout<<"Interest Rate > "<<irate;
    break;

    case 4:
        do
        {
            cout<<"Enter the Periodic Payment (PMT) >";
            cin >> pmt;

        } while ((pmt<1) || (pmt>10000));

        do
        {
            cout<<"Enter the Present Value (PV) >";
            cin >> pv;

        } while ((pv<1) || (pv>10000));

        do
        {
            cout<<"Enter the Interest Rate (r)>";
            cin >> irate;

        } while ((irate <0.1) || (irate > 15));

        //periods = secant(4,pmt,pv,irate);
        cout<<"Number of Periods > "<<periods;
    break;

    case 5:
        cout<<"Thank you for testing this program!\n";
    break;

    default:
        cout<<"Error, bad input\n";
    }
}


void fixedprinfloat()
{
cout<<"fixedprinfloat";
}
void fixedintinst2()
{
cout<<"fixedintinst2";
}
int main()
{
  int input=0;
  while (input!=4)
  {
    cout<<"Which option you want\n";

    cout<<"1. Fixed Principal Payment and Fixed Interest Rate\n";
    cout<<"2. Fixed Principal Payments and Margin Parametrised Normally Distributed Floating Interest Rate\n";
    cout<<"3. Fixed Interest Rate and Instalments Given 3 out 4 Variables\n";
    cout<<"4. Exit\n";
    cout<<"Selection: ";
    cin>> input;
    switch ( input ) {
    case 1:
        fixedintinst();
    break;
    case 2:
        fixedprinfloat();
    break;
    case 3:
        fixedintinst2();
    break;
    case 4:
        cout<<"Thank you for testing this program!\n";
        break;
    default:
        cout<<"Error, bad input\n";
    }
  }
  cin.get();
}

