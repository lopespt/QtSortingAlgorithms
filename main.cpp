/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Teste de uma janela simple
 *
 *        Version:  1.0
 *        Created:  11/04/2014 13:55:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <QApplication>
#include "mainWindow.h"
#include <QObject>
#include <QVector>



int
main ( int argc, char *argv[] )
{
    QApplication a(argc,argv);
    JanelaPrincipal  *P = new JanelaPrincipal();

    P->setWindowTitle("Sorting Algorithms - CC5661 - FEI - Prof. Guilherme Wachs");

    return a.exec();
}
