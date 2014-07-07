#ifndef INSERTIONSORTER_H
#define INSERTIONSORTER_H
#include <VectorSorter.h>

class InsertionSorter: public VectorSorter
{
public:
    InsertionSorter();
protected:
    void startSortingThread();
};

#endif // INSERTIONSORTER_H
