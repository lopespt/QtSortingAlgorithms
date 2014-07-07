#include "MergeSorter.h"

MergeSorter::MergeSorter()
{
}

void MergeSorter::startSortingThread(){
    mergeSort(vector,0,vector->size()-1);
}

void MergeSorter::mergeSort(QVector<int> *vector, int first, int last){

    if(isInterruptionRequested())
        return;

    if(last>first){
        int middle = (first+last)/2;
        mergeSort(vector, first, middle);
        mergeSort(vector, middle+1, last);
        merge(vector, first,last, middle);
    }

}

void MergeSorter::merge(QVector<int> *vector, int first, int last, int middle){

    QVector<int> v1(middle-first+1);
    QVector<int> v2(last-middle);

    for(int i=0;i<middle-first+1;i++){
        v1[i] = vector->at(i+first);
    }

    for(int i=0;i< last-middle;i++){
        v2[i] = vector->at(i+middle+1);
    }

    int i=0;
    int j=0;
    int p=first;
    while( i<v1.size() || j<v2.size() ){
        if(isInterruptionRequested())
            return;

        if( j==v2.size() ||  (i<v1.size()  &&  v1.at(i) < v2.at(j) )   ){
            (*vector)[p] = v1[i];
            i++;
        }else{
            (*vector)[p] = v2[j];
            j++;
        }
        emit vectorChanged(p);
        waitInterval();
        p++;
    }

}
