#include "vectoreditor.h"

VectorEditor::VectorEditor(QVector<int> *vector, QWidget *parent) :
    QWidget(parent)
{
    this->vector = vector;

    QVBoxLayout *vbox = new QVBoxLayout();
    table = new QTableWidget(vector->count(),1);
    for(int i=0;i<vector->count();i++){
        table->setItem(i,0,new QTableWidgetItem(QString::number(vector->at(i))));
    }

    vbox->addWidget(table);
    this->setLayout(vbox);

    QObject::connect(table,SIGNAL(cellChanged(int,int)), this, SLOT(cellChanged(int,int)));


}

void VectorEditor::cellChanged(int row, int column){
    bool ok;
    int n = table->item(row,0)->text().toInt(&ok);
    if(ok){
        (*vector)[row] = n;
        emit vectorChanged(row);
    }
}
