#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include <VectorSorter.h>

class QuickSorter:public VectorSorter
{
public:
    QuickSorter();

protected:
    void startSortingThread();
    void quickSort(QVector<int>* v, int i, int f);
    int partition(QVector<int>* v, int i, int f);
};

#endif // QUICKSORTER_H
