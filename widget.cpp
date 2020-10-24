#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_pPushbutton = new pushbuttonThreeStates();
    m_pPushbutton->setParent(this);
}

Widget::~Widget()
{
}

