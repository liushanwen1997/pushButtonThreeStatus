#include "pushbuttonthreestates.h"

pushbuttonThreeStates::pushbuttonThreeStates(QWidget *parent) : QPushButton(parent)
{
    status = NORMAL;
}

pushbuttonThreeStates::~pushbuttonThreeStates()
{

}

void pushbuttonThreeStates::leaveEvent(QEvent *event)
{
    status = NORMAL;
    QPushButton::leaveEvent(event);
}

void pushbuttonThreeStates::enterEvent(QEvent *event)
{
    status = HOVER;
    QPushButton::enterEvent(event);
}

void pushbuttonThreeStates::mousePressEvent(QMouseEvent *e)
{
    status = PRESS;
    QPushButton::mousePressEvent(e);
}

void pushbuttonThreeStates::mouseReleaseEvent(QMouseEvent *e)
{
    status = HOVER;
    QPushButton::mousePressEvent(e);
}

void pushbuttonThreeStates::paintEvent(QPaintEvent *e)
{
    QStyleOptionButton opt;
    initStyleOption(&opt);
    QPainter p(this);
    QPainterPath path;
    opt.rect.adjust(0,0,0,0);

    switch (status) {
        case NORMAL:
             p.setBrush(QBrush(Qt::red));
             opt.palette.setColor(QPalette::Highlight, QColor(Qt::red));
             p.setOpacity(1);
            break;
        case HOVER:
             p.setBrush(QBrush(Qt::green));
             opt.palette.setColor(QPalette::Highlight, QColor(Qt::green));
             p.setOpacity(1);
            break;
        case PRESS:
             p.setBrush(QBrush(Qt::black));
             opt.palette.setColor(QPalette::Highlight, QColor(Qt::black));
             p.setOpacity(1);
            break;
        default:
            break;
    }
    p.setPen(Qt::NoPen);
    p.drawRoundedRect(opt.rect, 28, 28);
    p.setRenderHint(QPainter::Antialiasing); //反锯齿
    style()->drawControl(QStyle::CE_PushButton, &opt, &p, this);
    style()->drawControl(QStyle::CE_PushButtonLabel, &opt, &p, this);
}
