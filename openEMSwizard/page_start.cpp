#include "page_start.h"

PageStart::PageStart(QWizard *parent)
{
    QLabel *StaticText1 = new QLabel("path to ...openEMS/matlab", this);
    StaticText1->setGeometry(QRect(QPoint(22, 20), QSize(180, 30)));
    TextOpenEMSPath = new QLineEdit(this);
    TextOpenEMSPath->setGeometry(QRect(QPoint(220, 20), QSize(200, 20)));
    QPushButton *button_set_openems_path = new QPushButton("...", this);
    button_set_openems_path->setGeometry(QRect(QPoint(420, 20), QSize(30, 20)));

    QLabel *StaticText2 = new QLabel("path to ...CSXCAD/matlab", this);
    StaticText2->setGeometry(QRect(QPoint(22, 50), QSize(180, 30)));
    TextCSXCADPath = new QLineEdit(this);
    TextCSXCADPath->setGeometry(QRect(QPoint(220, 50), QSize(200, 20)));
    QPushButton *button_set_csxcad_path = new QPushButton("...", this);
    button_set_csxcad_path->setGeometry(QRect(QPoint(420, 50), QSize(30, 20)));

    QLabel *StaticText3 = new QLabel("path to the simulation directory", this);
    StaticText3->setGeometry(QRect(QPoint(22, 80), QSize(180, 30)));
    TextSimulationPath = new QLineEdit(this);
    TextSimulationPath->setGeometry(QRect(QPoint(220, 80), QSize(200, 20)));
    QPushButton *button_set_simulation_path = new QPushButton("...", this);
    button_set_simulation_path->setGeometry(QRect(QPoint(420, 80), QSize(30, 20)));

    connect(button_set_openems_path, SIGNAL(released()), this, SLOT(OnSetOpenEMSPath()));
    connect(button_set_csxcad_path, SIGNAL(released()), this, SLOT(OnSetCSXCADPath()));
    connect(button_set_simulation_path, SIGNAL(released()), this, SLOT(OnSetSimulationPath()));
}


void PageStart::OnSetOpenEMSPath()
{
    QFileDialog *dir_dialog = new QFileDialog(this);
    TextOpenEMSPath->insert(dir_dialog->getExistingDirectory(this));
}
void PageStart::OnSetCSXCADPath()
{
    QFileDialog *dir_dialog = new QFileDialog(this);
    TextCSXCADPath->insert(dir_dialog->getExistingDirectory(this));
}
void PageStart::OnSetSimulationPath()
{
    QFileDialog *dir_dialog = new QFileDialog(this);
    TextSimulationPath->insert(dir_dialog->getExistingDirectory(this));
}
