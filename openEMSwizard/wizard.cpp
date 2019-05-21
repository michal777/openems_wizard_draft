#include "wizard.h"
#include "page_start.h"
#include "page_basic_sim_setup.h"
#include "general_geometry_settings.h"


MyWizard::MyWizard(QMainWindow *parent, QFile *workflowfile): QWizard(parent)
{
    for(workflowfile->seek(0); !workflowfile->atEnd();)
        this->addPage(ReturnWorkflowStep(this, workflowfile->readLine()));
}

QWizardPage *MyWizard::ReturnWorkflowStep(QWizard *parent, QString workflowname)
{
    if(!workflowname.compare("Start page\n"))
        return new PageStart(parent);
    else if(!workflowname.compare("Basic simulation setup\n"))
        return new PageBasicSimSetup(parent);
    else if(!workflowname.compare("General geometry settings\n"))
        return new GeneralGeometrySettings(parent);

}
