/*
 * =====================================================================================
 *
 *       Filename:  mainWindow.h
 *
 *    Description:  janela principal
 *
 *        Version:  1.0
 *        Created:  11/04/2014 14:12:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __mainwindow_h
#define __mainwindow_h

#include <QMainWindow>
#include <QObject>
#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QTextEdit>
#include <SortViewWidget.h>
#include <QPushButton>
#include <QVector>
#include "BubbleSorter.h"
#include <QSlider>
#include <MergeSorter.h>
#include <vectoreditor.h>
#include <QHBoxLayout>
#include <VectorSorter.h>
#include <QDateTime>
#include <stdio.h>
#include <QCoreApplication>
#include <QApplication>
#include <InsertionSorter.h>
#include <QuickSorter.h>
#include <TimerWidget.h>
#include <QPluginLoader>
#include <QScrollArea>
#include <QTimer>

#define N_SORTERS 4

class JanelaPrincipal:public QMainWindow
{
	Q_OBJECT
	public:


        JanelaPrincipal (QWidget* parent=NULL);
        ~JanelaPrincipal();
	protected:


	private:
        QVector<int> *vectors[N_SORTERS];
        VectorSorter* sorters[N_SORTERS];
        SortViewWidget* sortViews[N_SORTERS];
        QLabel *lblTimes[N_SORTERS];
        QSlider* slider;
        QSlider* sliderItems;
        QVector<int> generateRandomVector();
        QTimer updateTimer;
        TimerWidget* timers[N_SORTERS];
        QPushButton* pb;
        QPushButton* pb2;
        int n;


    private slots:
        void startSorting();
        void stopSorting();
        void setupVectors();
        void setN(int);

};

#endif
