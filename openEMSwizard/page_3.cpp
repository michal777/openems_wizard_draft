#include "page_3.h"


PageSelectSomething3::PageSelectSomething3(wxWizard *parent, wxWizardPageSimple *prev, wxWizardPageSimple *next): wxWizardPageSimple(parent, prev, next)
{
    m_checkbox = new wxCheckBox(this, wxID_ANY, wxString("example3"));
}
