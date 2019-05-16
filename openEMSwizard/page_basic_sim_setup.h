#ifndef PAGE_BASIC_SIM_SETUP_INCLUDED
#define PAGE_BASIC_SIM_SETUP_INCLUDED

#include <wx/wx.h>
#include "wx/wizard.h"

enum
{
};

class PageBasicSimSetup : public wxWizardPageSimple
{
public:
    PageBasicSimSetup(wxWizard *parent, wxWizardPageSimple *prev, wxWizardPageSimple *next);



    wxDECLARE_EVENT_TABLE();
};

#endif // PAGE_BASIC_SIM_SETUP_INCLUDED
