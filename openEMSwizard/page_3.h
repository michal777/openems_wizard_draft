#ifndef PAGE_3_INCLUDED
#define PAGE_3_INCLUDED

#include <wx/wx.h>
#include "wx/wizard.h"


class PageSelectSomething3 : public wxWizardPageSimple
{
public:
    PageSelectSomething3(wxWizard *parent, wxWizardPageSimple *prev, wxWizardPageSimple *next);
    wxCheckBox *m_checkbox;
};

#endif // PAGE_3_INCLUDED

