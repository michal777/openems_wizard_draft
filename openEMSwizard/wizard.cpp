#include "wizard.h"
#include "page_start.h"
#include "page_basic_sim_setup.h"
#include "page_general_geometry_settings.h"
#include "page_geometry.h"
#include "page_ports.h"
#include "page_results.h"


MyWizard::MyWizard(QMainWindow *parent, QFile *workflowfile): QWizard(parent)
{
    for(workflowfile->seek(0); !workflowfile->atEnd();)
        this->addPage(ReturnWorkflowStep(workflowfile->readLine()));
}

QWizardPage *MyWizard::ReturnWorkflowStep(QString workflowname)
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
        return new PageResults(this);

}
