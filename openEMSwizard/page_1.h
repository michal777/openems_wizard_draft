#ifndef PAGE_1_INCLUDED
#define PAGE_1_INCLUDED

#include <wx/wx.h>
#include "wx/wizard.h"


class PageSelectSomething1 : public wxWizardPageSimple
{
public:
    PageSelectSomething1(wxWizard *parent, wxWizardPageSimple *prev, wxWizardPageSimple *next);
};

#endif // PAGE_1_INCLUDED
