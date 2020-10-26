#ifndef PUSHBUTTONTHREESTATES_H
#define PUSHBUTTONTHREESTATES_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QPalette>
#include <QStyleOption>
#include <QStyleOptionButton>
#include <QPainter>
#include <QStyle>
#include <QCommonStyle>

class pushbuttonThreeStates : public QPushButton
{
    Q_OBJECT
public:
    pushbuttonThreeStates(QWidget *parent = nullptr);
    ~pushbuttonThreeStates();
    enum TaskWidgetStatus{NORMAL, HOVER, PRESS};
    TaskWidgetStatus status;

protected:
    void leaveEvent(QEvent *event) override;
    void enterEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void paintEvent(QPaintEvent *e) override;
};

#endif // PUSHBUTTONTHREESTATES_H
