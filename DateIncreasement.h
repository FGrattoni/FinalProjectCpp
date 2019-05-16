#ifndef DateIncreasement_H
#define DateIncreasement_H

using namespace std;

int* DateIncreasement(int start[], int f){

    start[0] += (12/f);
    if (start[0] > 12) {
        start[0] -= 12;
        start[1]++;
    }

    return start;
}

#endif
