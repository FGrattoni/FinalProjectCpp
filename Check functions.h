#include <iostream>
#include <string>

using namespace std;
int main()
{
 int PV, PMT, Pe, n;

 double CheckPV;
 cout << "Insert PV." <<endl;
 cin>>PV;
 
  if (!(PV>=0))
  cout << "Error. You insert a negative PV. Please insert PV again." << endl;
    

 double CheckPe;
  cout << "Insert Pe." <<endl;
  cin>>Pe;
   
   if (!(Pe>=0))
  cout << "Error. You insert a negative Pe. Please insert Pe again." << endl;
   
 double Checkn;
  cout << "Insert n." <<endl;
  cin>>n;
   
   if(!(n>0))
  cout << "Error. You insert a negative n. Please insert n again." << endl;
 
 double CheckPMT;
 cout << "Insert PMT."<<endl ;
  cin>>PMT;
   
   if (!(PMT>=0 & PMT<=PV))
  cout << "Error. Please insert PMT again." << endl;
    
  }
