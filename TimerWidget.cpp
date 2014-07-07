#include "TimerWidget.h"

TimerWidget::TimerWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout();
    label = new QLabel();
    hbox->addWidget(label);
    hbox->addWidget(new QLabel("ms"));
    updateTimer.setInterval(100);
    QObject::connect(&updateTimer,SIGNAL(timeout()),this,SLOT(updateLabel()));
    updateTimer.stop();
    active = false;
    setLayout(hbox);
    timer = QTime::currentTime();
    label->setText("0");
}


void TimerWidget::startTimer(){
        timer = QTime::currentTime();
        active = true;
        updateTimer.start();
}

void TimerWidget::stopTimer(){
        active = false;
        updateTimer.stop();
}


void TimerWidget::updateLabel(){
    label->setText( QString::number(timer.msecsTo(QTime::currentTime()) ));
}
