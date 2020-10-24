#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "pushbuttonthreestates.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    pushbuttonThreeStates *m_pPushbutton;
    ~Widget();
};
#endif // WIDGET_H
