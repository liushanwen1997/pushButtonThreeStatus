#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pushbuttonThreeStates button;
    button.setFixedSize(56, 56);
    button.setIcon(QIcon::fromTheme("ukui-icon-eyeprotectionmode"));
    button.show();
    return a.exec();
}
