//Copyright Michal Stec 2019

#include "wizard.h"
#include "page_1.h"
#include "page_2.h"
#include "page_3.h"


MyWizard::MyWizard(wxFrame *frame, wxTextFile *workflowfile)
{
    int i_page = 0;
    int page_count=0;

    page_count = workflowfile->GetLineCount();

    wxString workflow_array[page_count];

    for(i_page = 0; i_page < page_count; ++i_page)
        workflow_array[i_page] = workflowfile->GetLine(i_page);

    Create(frame,wxID_ANY,wxString("the wizard"));

    wxWizardPageSimple *PageArray[page_count];  //all the pages objects (derived from wxWizardPageSimple) will be kept in the array

    for(i_page = 0; i_page < page_count; ++i_page)
        PageArray[i_page] = ReturnWorkflowStep(this, workflow_array[i_page]);   //create objects of all the pages according to order defined in workflow_array
    for(i_page = 1; i_page < page_count; ++i_page)
        PageArray[i_page-1]->Chain(PageArray[i_page]);  //connect all pages
    m_page1 = PageArray[0]; //pointer to the first page will be needed for RunWizard function
}

wxWizardPageSimple *MyWizard::ReturnWorkflowStep(wxWizard *parent, wxString workflowname)
{
    if(!workflowname.Cmp(wxT("step1")))
        return new PageSelectSomething1(parent, NULL, NULL);
    if(!workflowname.Cmp(wxT("step2")))
        return new PageSelectSomething2(parent, NULL, NULL);
    if(!workflowname.Cmp(wxT("step3")))
        return new PageSelectSomething3(parent, NULL, NULL);
}
