#include "BubbleSorter.h"

BubbleSorter::BubbleSorter():VectorSorter()
{
	//test
}


void BubbleSorter::startSortingThread(){

    int n = vector->size();
    int temp;
    bool trocou;
    do {
        trocou=false;
        for(int i=1;i<n;i++){
            if(isInterruptionRequested())
                return;

            if(vector->at(i-1) > vector->at(i)){
                temp = vector->at(i);
                (*vector)[i] = vector->at(i-1);
                (*vector)[i-1] = temp;
                emit vectorChanged(i);
                emit vectorChanged(i-1);
                waitInterval();
                trocou=true;
            }
        }
    }while(trocou);
}


