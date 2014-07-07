#ifndef LINEARSORTER_H
#define LINEARSORTER_H
#include "VectorSorter.h"
#include <QVector>
#include <QThread>
#include <QDebug>

class BubbleSorter : public VectorSorter
{
    Q_OBJECT
public:
    explicit BubbleSorter();
signals:

public slots:

protected:
    void startSortingThread();

};

#endif // LINEARSORTER_H
