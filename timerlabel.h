#ifndef TIMERLABEL_H
#define TIMERLABEL_H

#include <QLabel>
#include <QDateTime>
#include <QMouseEvent>
#include <QTimer>
#include <QApplication>

class TimerLabel : public QLabel
{
    Q_OBJECT
public:
    TimerLabel(QWidget *parent = 0);
signals:
    void clicked_and_hold();
    void double_clicked();
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *ev);
private slots:
    void start();
    void stop();
    void update_time();
private:
    ulong click_time;
    QDateTime start_time;
    QTimer* timer;
};

#endif // TIMERLABEL_H
