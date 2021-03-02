#ifndef RADIXSORTER_H
#define RADIXSORTER_H
#include "VectorSorter.h"
#include <QVector>
#include <QThread>
#include <QDebug>

class RadixSorter : public VectorSorter
{
private:
    void countingSort(QVector<int> &v, int digit);
public:
    RadixSorter();
    ~RadixSorter(){}
signals:

public slots:

protected:
    void startSortingThread();

};

#endif // RADIXSORTER_H
