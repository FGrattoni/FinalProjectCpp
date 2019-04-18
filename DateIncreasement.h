#ifndef DateIncreasement_H
#define DateIncreasement_H

#include <iostream>
#include <cmath>

using namespace std;

void DateIncreasement (int start[], int f){
    if (f==1){
        start[1]+=1;
    } else if(f==2) {
        start[0] += 6;
        if (start[0] > 12) {
            start[0] -= 12;
            start[1]++;
        }
    }else if(f==3){
        start[0]+=4;
        if (start[0]>12){
            start[0] -= 12;
            start[1]++;
        }
    }else if(f==4){
        start[0]++;
        if (start[0]>12) {
            start[0] -= 12;
            start[1]++;
        }}
}
