#include "InsertionSorter.h"

InsertionSorter::InsertionSorter()
{
}

void InsertionSorter::startSortingThread(){
    for(int i=1;i<vector->size();i++){
        int el = vector->at(i);
        int j = i-1;
        while(j >= 0 && el < (*vector)[j] ){
            if(isInterruptionRequested())
                return;

            (*vector)[j+1]=(*vector)[j];
            emit vectorChanged(j+1);
            waitInterval();
            j--;
        }
        (*vector)[j+1]=el;
        emit vectorChanged(j+1);
        waitInterval();
    }
}
