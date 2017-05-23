#include "timerlabel.h"

TimerLabel::TimerLabel(QWidget *parent)
    : QLabel(parent)
{
    timer = new QTimer(this);
    start_time = QDateTime::currentDateTime();
    click_time = 0;
    setText("00:00");
    setStyleSheet("QLabel {"
                  "color: white;"
                  "background-color: green;"
                  "border: 2px solid darkgreen;"
                  "border-radius: 5px;"
                  "qproperty-alignment: AlignCenter;"
                  "}"
                  "QLabel:hover {"
                  "border: 2px solid red;"
                  "}");

    connect(this, SIGNAL(clicked_and_hold()), this, SLOT(start()));
    connect(this, SIGNAL(double_clicked()), this, SLOT(stop()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update_time()));
}


void TimerLabel::mouseDoubleClickEvent(QMouseEvent*){
    emit double_clicked();
}

void TimerLabel::mousePressEvent(QMouseEvent *event){
    if(QApplication::keyboardModifiers() == Qt::ControlModifier){
        deleteLater();
    }
    click_time = event->timestamp();
}

void TimerLabel::mouseReleaseEvent(QMouseEvent *ev){
    if(!click_time) return;

    ulong diff = ev->timestamp() - click_time;
    click_time = 0;

    if(diff >= 300){
        emit clicked_and_hold();
    }
}

void TimerLabel::start(){
    if(timer->isActive()) return;

    start_time = QDateTime::currentDateTime();
    timer->start();
}

void TimerLabel::stop(){
    timer->stop();
    setText("00:00");
}

void TimerLabel::update_time(){
    if(timer->isActive()){
        qint64 ms = start_time.msecsTo(QDateTime::currentDateTime());
        int s = ms / 1000;
        ms %= 1000;
        ms /= 10;
        setText( QString("%1:%2").arg(s, 2,10 ,QChar('0')).arg(ms, 2,10 ,QChar('0')));
    }
}


