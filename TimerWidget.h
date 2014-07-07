#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include <QTime>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>

class TimerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimerWidget(QWidget *parent = 0);

signals:

public slots:
    void startTimer();
    void stopTimer();
    void updateLabel();

private:
    QLabel* label;
    QTime timer;
    QTimer updateTimer;
    bool active;
};

#endif // TIMERWIDGET_H
