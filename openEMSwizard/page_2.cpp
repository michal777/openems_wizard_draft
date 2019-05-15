#include "page_2.h"


PageSelectSomething2::PageSelectSomething2(wxWizard *parent, wxWizardPageSimple *prev, wxWizardPageSimple *next): wxWizardPageSimple(parent, prev, next)
{
    m_checkbox = new wxCheckBox(this, wxID_ANY, wxString("example2"));
}
