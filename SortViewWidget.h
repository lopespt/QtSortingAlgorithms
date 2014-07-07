/*
 * =====================================================================================
 *
 *       Filename:  SortViewWidget.h
 *
 *    Description:  View Sort Sticks
 *
 *        Version:  1.0
 *        Created:  13/04/2014 23:05:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*
 * =====================================================================================
 *        Class:  SortViewWidget
 *  Description:  s
 * =====================================================================================
 */
#ifndef SORTVIEWWIDGET_H
#define SORTVIEWWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QObject>
#include <QAbstractScrollArea>
//#include <QtOpenGL>
#include <QVBoxLayout>
#include <QResource>

class SortViewWidget : public QWidget
{
    Q_OBJECT
    public:

        SortViewWidget (QWidget *parent=NULL);
        void setMaximumValue(int);
        void setMinimumValue(int);
        void setVector(QVector<int> *);


    public slots:
        void redraw();
        void updateElement(int n);
        void setUpperText(QString text);


    private:
        QGraphicsView* graphic;
        QGraphicsScene *scene;
        //QGLWidget* wgl;
        QVector<int> *vector;
        QVector<QGraphicsItem*> items;
        QLabel* upperLabel;
        QLabel* lowerLabel;
        QPixmap logoFei;

        int min,max;

protected:
        void resizeEvent(QResizeEvent* event);
};

#endif
