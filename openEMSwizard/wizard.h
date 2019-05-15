//Copyright Michal Stec 2019

#ifndef WIZARD_H_INCLUDED
#define WIZARD_H_INCLUDED

#include <wx/wx.h>
#include "wx/wizard.h"
#include <wx/textfile.h>


class MyWizard: public wxWizard
{
public:
    MyWizard(wxFrame *frame, wxTextFile *workflowfile);
    wxWizardPageSimple *m_page1;
    wxWizardPageSimple *GetFirstPage() const {return m_page1;}

    wxWizardPageSimple *ReturnWorkflowStep(wxWizard *parent, wxString workflowname);
};


#endif // WIZARD_H_INCLUDED
