#ifndef ScheduleValues_H
#define ScheduleValues_H

#include <iostream>
#include <cmath>


using namespace std;

void ScheduleValues(int R,int PMT,int repayments){
    int pvb[repayments]; int p[repayments]; int r[repayments]; int interest[repayments]; int pmt[repayments]; int pve[repayments]; int a=1;
    
    for (int i=0; i<repayments; i++){
        pmt[i]=PMT;
        r[i]=R;
        interest[i]=pvb[i]*r[i];
        p[i]=pmt[i]-interest[i];
        pve[i]=pvb[i]-p[i];
        pvb[a]=pve[i];
        a++;
        }
    /*for (int i=0; i<repayments; i++){
        cout << "pmt[i]" << pmt[i]<<endl;
        cout << "r[i]"<<r[i]<<endl;
        cout << "interest[i]"<<interest[i]<<endl;
        cout << "p[i]"<<p[i]<<endl;
        cout << "pve[i]"<<pve[i]<<endl;
        cout << "pvb[i]"<<pvb[i]<<endl;
        }to check arrays 
        */
    }
    


