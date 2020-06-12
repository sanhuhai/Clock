#pragma once

#include <QtWidgets/QDialog>
#include <QLCDNumber>
#include <QPalette>
#include <QTimer>
#include <Qtime>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
//#include "ui_Clock.h"
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif // WIN32

class Clock : public QLCDNumber
{
    Q_OBJECT

public:
    Clock(QWidget *parent = Q_NULLPTR);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void showT();
private slots:
    void showTime();
private:
    //Ui::ClockClass ui;
    bool showColon;
    QPoint dragPosition;
};
