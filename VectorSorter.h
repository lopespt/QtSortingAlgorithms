#ifndef VECTORSORTER_H
#define VECTORSORTER_H

#include <QVector>
#include <QThread>
#include <QDebug>
class VectorSorter : public QThread
{
    Q_OBJECT
public:
    explicit VectorSorter(QObject *parent = 0);
    void sort(QVector<int> *vector);
    void run();

signals:
    void vectorChanged(int);
    void sortFinished();


public slots:
    void setInterval(int);

public:

protected:
    virtual void startSortingThread()=0;
    QVector<int> *vector;
    int interval;
    void waitInterval();
};

#endif // VECTORSORTER_H
