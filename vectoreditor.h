#ifndef VECTOREDITOR_H
#define VECTOREDITOR_H

#include <QWidget>
#include <QVector>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidgetItem>
#include <QSize>

class VectorEditor : public QWidget
{
    Q_OBJECT
public:
    explicit VectorEditor(QVector<int>* vector, QWidget *parent = 0);


signals:
void vectorChanged(int pos);

public slots:

private slots:
    void cellChanged(int,int);


private:
    QVector<int> *vector;
    QTableWidget* table;

};

#endif // VECTOREDITOR_H
