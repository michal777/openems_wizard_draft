#include "mainwindow.h"
#include "wizard.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setGeometry(QRect(QPoint(50, 50), QSize(800, 500)));
    QPushButton *button_run_wizard = new QPushButton("Run the wizard", this);
    button_run_wizard->setGeometry(QRect(QPoint(50, 150), QSize(100, 30)));

    QLabel *StaticText1 = new QLabel("path to workflow file", this);
    StaticText1->setGeometry(QRect(QPoint(50, 70), QSize(150, 20)));
    TextWorkflowFilePath = new QLineEdit(this);
    TextWorkflowFilePath->setGeometry(QRect(QPoint(200, 70), QSize(200, 20)));
    QPushButton *button_set_workflowfile_path = new QPushButton("...", this);
    button_set_workflowfile_path->setGeometry(QRect(QPoint(400, 70), QSize(30, 20)));

    connect(button_run_wizard, SIGNAL(released()), this, SLOT(OnRunWizard()));
    connect(button_set_workflowfile_path, SIGNAL(released()), this, SLOT(OnSetWorkflowFilePath()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::OnSetWorkflowFilePath()
{
    QFileDialog *file_dialog = new QFileDialog(this);
    TextWorkflowFilePath->insert(file_dialog->getOpenFileName(this, ("Open File"), ".", ("workflow file (*.wff_oems)")));
}

void MainWindow::OnRunWizard()
{
    workflowfile = new QFile(TextWorkflowFilePath->text(), this);
    workflowfile->open(QIODevice::ReadOnly);
    MyWizard *wizard = new MyWizard(this, workflowfile);
    wizard->show();
}
