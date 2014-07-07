#ifndef MERGESORTER_H
#define MERGESORTER_H
#include <VectorSorter.h>
class MergeSorter: public VectorSorter
{
public:
    MergeSorter();
protected:
    void startSortingThread();
private:
    void mergeSort(QVector<int> *vector, int first, int last);
    void merge(QVector<int>* vector, int first, int last, int middle);
};

#endif // MERGESORTER_H
