#include "Clock.h"

Clock::Clock(QWidget *parent)
    : QLCDNumber(parent)
{
   // ui.setupUi(this);
    showT();
}

void Clock::showT() {
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::blue);
    setPalette(p);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
    resize(150, 60);
    showColon = true;
}

void Clock::showTime() {
    QTime time = QTime::currentTime();
    QString text = time.toString("m:s");
    text[2] = ':';
    display(text);
    qDebug() << text;
}

void Clock::mousePressEvent(QMouseEvent* event) {
    if (event->button()==Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    if (event->button() == Qt::RightButton) {
        close();
    }
}

void Clock::mouseMoveEvent(QMouseEvent* event) {
    if (event->button() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}