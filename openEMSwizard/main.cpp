#include "WizardInit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WizardInit *wizard = new WizardInit(NULL);
    wizard->show();

    return a.exec();
}
