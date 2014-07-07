/*
 * =====================================================================================
 *
 *       Filename:  SortViewWidget.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/2014 23:07:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


/*
 *--------------------------------------------------------------------------------------
 *       Class:  SortViewWidget
 *      Method:  SortViewWidget
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
#include <SortViewWidget.h>

SortViewWidget::SortViewWidget (QWidget *parent):QWidget(parent)
{

    QVBoxLayout* vbox = new QVBoxLayout();
    this->setLayout(vbox);

    upperLabel = new QLabel();
    upperLabel->setAlignment(Qt::AlignCenter);
    vbox->addWidget(upperLabel);

    graphic = new QGraphicsView();
    vbox->addWidget(graphic);


    vector=NULL;
    scene = new QGraphicsScene();

    graphic->setScene(scene);
    graphic->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    graphic->setDragMode(QGraphicsView::NoDrag);
    graphic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphic->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphic->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
    graphic->setAlignment(Qt::AlignBaseline);
    scene->setSceneRect(0,0,graphic->width(),graphic->height());

    logoFei = QPixmap(":/logoFei");
    logoFei = logoFei.scaled(graphic->width(),scene->height()/3.0*2.0,Qt::KeepAspectRatio);


    //wgl=new QGLWidget();
    //graphic->setViewport(wgl);
}

void SortViewWidget::setMaximumValue(int i){
    this->min = i;
}

void SortViewWidget::setMinimumValue(int i){
    this->max = i;
}

void SortViewWidget::setVector(QVector<int> *vector){
    this->vector = vector;
    redraw();
}

void SortViewWidget::updateElement(int n){

    if(vector){
        float barWidth = (graphic->sceneRect().width()-1.0) / vector->size();
        QGraphicsItem* i = items[n];
        scene->removeItem(i);
        items[n] = scene->addRect(n*barWidth,graphic->sceneRect().height(),barWidth-1,-vector->at(n),QPen(),QBrush(Qt::red));
    }
    scene->update();
    graphic->update();

}

void SortViewWidget::redraw(){
    scene->clear();
    scene->addPixmap(logoFei);
    items.clear();
    scene->setSceneRect(0,0,graphic->width()-10,graphic->height()-10);
    if(vector){
       float barWidth = (graphic->sceneRect().width()-1.0) / vector->size();
       for(int i=0;i< vector->size();i++){
           QGraphicsItem* item = scene->addRect(i*barWidth,graphic->sceneRect().height(),barWidth-1,-vector->at(i),QPen(),QBrush(Qt::red));
           items.append(item);
        }
    }

    scene->update();
    graphic->update();
    //fitInView(scene->itemsBoundingRect());
}

void SortViewWidget::resizeEvent(QResizeEvent *event){
    logoFei =  logoFei.scaled(graphic->width(),scene->height()/3.*2.,Qt::KeepAspectRatio);
    redraw();
}

void SortViewWidget::setUpperText(QString text){
    this->upperLabel->setText(text);
}

