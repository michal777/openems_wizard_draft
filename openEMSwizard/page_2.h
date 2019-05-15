#ifndef PAGE_2_INCLUDED
#define PAGE_2_INCLUDED

#include <wx/wx.h>
#include "wx/wizard.h"


class PageSelectSomething2 : public wxWizardPageSimple
{
public:
    PageSelectSomething2(wxWizard *parent, wxWizardPageSimple *prev, wxWizardPageSimple *next);
    wxCheckBox *m_checkbox;
};

#endif // PAGE_2_INCLUDED

