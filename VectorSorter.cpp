#include "VectorSorter.h"

VectorSorter::VectorSorter(QObject *parent) :
    QThread(parent)
{
    interval = 250;

}


void VectorSorter::sort(QVector<int> *vector){
    if(vector){
        this->vector = vector;
        this->start();
    }
}

void VectorSorter::setInterval(int interval){
   this->interval=interval;
}


void VectorSorter::run(){
    this->startSortingThread();
    this->vector=NULL;
    emit sortFinished();
}

void VectorSorter::waitInterval(){
    thread()->msleep(interval);
}
