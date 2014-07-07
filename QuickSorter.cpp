#include "QuickSorter.h"


QuickSorter::QuickSorter()
{
}


void QuickSorter::startSortingThread(){
    quickSort(vector,0,vector->size()-1);
}


void QuickSorter::quickSort(QVector<int> *v, int i, int f){
    if(isInterruptionRequested())
        return;
    if(f>i){
        int k = partition(v,i,f);
        quickSort(v,i,k-1);
        quickSort(v,k+1,f);
    }
}

int QuickSorter::partition(QVector<int> *v, int i, int f) {
    int pivot = (*v)[f];
    int k=i-1;
    for(int j=i;j<f;j++){
        if( (*v)[j] <= pivot   ){
            if(isInterruptionRequested())
                return 0;
            k++;
            int temp = (*v)[k];
            (*v)[k] = (*v)[j];
            (*v)[j] = temp;
            emit vectorChanged(k);
            emit vectorChanged(j);
            waitInterval();
        }
    }

   int temp = (*v)[k+1];
   (*v)[k+1] = (*v)[f];
   (*v)[f]=temp;
   emit vectorChanged(k+1);
   emit vectorChanged(f);
   waitInterval();
   return k+1;
}
