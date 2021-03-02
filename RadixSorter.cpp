#include "RadixSorter.h"
#include <math.h>

RadixSorter::RadixSorter()
{
}

void RadixSorter::countingSort(QVector<int> &v, int digit){
    QVector<int> counting(10, 0);
    QVector<int> copy = v;

    for (int i : v) {
        int idx = (int)(i/pow(10,digit))%10;
        counting[ idx  ]++;
    }
    for (int i = 1; i < counting.size() ; i++) {
        counting[i] = counting[i] + counting[i-1];
    }
    for (int i=copy.size()-1; i>=0 ; i--) {
        waitInterval();
        int idx = (int)(copy[i]/pow(10,digit))%10;
        v[counting[idx]-1] = copy[i];
        emit vectorChanged(counting[idx]-1) ;
        counting[idx]--;
        if(isInterruptionRequested())
            return;
    }
}

void RadixSorter::startSortingThread(){

    int n = vector->size();
    
    //Ordering digits
    for(int d=0; d<3; d++){
        countingSort(*vector, d);
    }
    
}


