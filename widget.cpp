#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_pPushbutton = new pushbuttonThreeStates();
    m_pPushbutton->setParent(this);
    m_pPushbutton->setFixedSize(56, 56);
    m_pPushbutton->setIcon(QIcon::fromTheme("ukui-icon-eyeprotectionmode"));
}

Widget::~Widget()
{
}

