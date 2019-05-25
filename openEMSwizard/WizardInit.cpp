#include "WizardInit.h"
#include "PageStart.h"
#include "PageBasicSimSetup.h"
#include "PageGeneralGeometrySettings.h"
#include "PageGeometry.h"
#include "PagePorts.h"
#include "PageResultsSparam.h"


WizardInit::WizardInit(QMainWindow *parent): QWizard(parent)
{
    file_main_settings = "app_settings.ini";
    main_settings = new QSettings(file_main_settings, QSettings::NativeFormat, this);
    StartWizardWindow();    //dialog with workflow file selection will appear, when selected the listed pages are added to this wizard
    for(workflowfile->seek(0); !workflowfile->atEnd();)
        this->addPage(ReturnWorkflowStep(workflowfile->readLine()));
}

QWizardPage *WizardInit::ReturnWorkflowStep(QString workflowname)
{
    if(!workflowname.compare("Start page\n"))
        return new PageStart(this);
    else if(!workflowname.compare("Basic simulation setup\n"))
        return new PageBasicSimSetup(this);
    else if(!workflowname.compare("General geometry settings\n"))
        return new PageGeneralGeometrySettings(this);
    else if(!workflowname.compare("Geometry\n"))
        return new PageGeometry(this);
    else if(!workflowname.compare("Ports\n"))
        return new PagePorts(this);
    else if(!workflowname.compare("Results\n"))
        return new PageResultsSparam(this);

}

void WizardInit::StartWizardWindow()
{
    dialog_load_workflow = new QDialog(this);

    //workflow file path edit
    QLabel *statictext_wffile = new QLabel("path to workflow file", dialog_load_workflow);
    statictext_wffile->setGeometry(QRect(QPoint(50, 70), QSize(150, 20)));
    text_wffile_path = new QLineEdit(dialog_load_workflow);
    text_wffile_path->setGeometry(QRect(QPoint(200, 70), QSize(200, 20)));
    LoadSettings();
    QPushButton *button_set_workflowfile_path = new QPushButton("...", dialog_load_workflow);
    button_set_workflowfile_path->setGeometry(QRect(QPoint(400, 70), QSize(30, 20)));

    //button starting the wizard
    dialog_load_workflow->setGeometry(QRect(QPoint(50, 50), QSize(500, 400)));
    QPushButton *button_run_wizard = new QPushButton("Run the wizard", dialog_load_workflow);
    button_run_wizard->setGeometry(QRect(QPoint(50, 150), QSize(100, 30)));

    connect(button_run_wizard, SIGNAL(released()), this, SLOT(OnRunWizard()));
    connect(button_set_workflowfile_path, SIGNAL(released()), this, SLOT(OnSetWorkflowFilePath()));

    //after closing the dialog the wizard will add pages according to loaded file
    dialog_load_workflow->exec();
}

void WizardInit::LoadSettings()
{
    text_wffile_path->setText(main_settings->value("last_selected_workflow", "").toString());
}

void WizardInit::SaveSettings()
{
    main_settings->setValue("last_selected_workflow", text_wffile_path->text());
}

void WizardInit::OnSetWorkflowFilePath()
{
    QFileDialog *file_dialog = new QFileDialog(dialog_load_workflow);
    text_wffile_path->setText(file_dialog->getOpenFileName(dialog_load_workflow, ("Open File"), ".", ("workflow file (*.wff_oems)")));
}

void WizardInit::OnRunWizard()
{
    SaveSettings();
    workflowfile = new QFile(text_wffile_path->text(), this);
    workflowfile->open(QIODevice::ReadOnly);
    dialog_load_workflow->close();
}
