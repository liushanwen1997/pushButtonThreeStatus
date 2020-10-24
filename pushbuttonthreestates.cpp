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
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    QPainterPath path;
    opt.rect.adjust(0,0,0,0);

    switch (status) {
        case NORMAL:
             p.setBrush(QBrush(Qt::red));
             p.setOpacity(0);
            break;
        case HOVER:
             p.setBrush(QBrush(Qt::white));
             p.setOpacity(1);
            break;
        case PRESS:
             p.setBrush(QBrush(Qt::black));
             p.setOpacity(1);
            break;
        default:
            break;
    }
    p.setPen(Qt::NoPen);
    p.drawRoundedRect(opt.rect, 6, 6);
    p.setRenderHint(QPainter::Antialiasing); //反锯齿
    setProperty("blurRegion", QRegion(path.toFillPolygon().toPolygon()));
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
