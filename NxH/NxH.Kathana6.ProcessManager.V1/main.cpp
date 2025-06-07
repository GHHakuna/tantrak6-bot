#include "NxHK6PM.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    NxHK6PM window;
    window.show();
    return app.exec();
}
