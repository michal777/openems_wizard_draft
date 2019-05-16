#ifndef PAGE_START_INCLUDED
#define PAGE_START_INCLUDED

#include <wx/wx.h>
#include <wx/dirdlg.h>
#include "wx/wizard.h"

enum
{
    SetOpenEMSPath = 1,
    SetCSXCADPath = 2,
    SetSimulationPath = 3
};

class PageStart : public wxWizardPageSimple
{
public:
    PageStart(wxWizard *parent, wxWizardPageSimple *prev, wxWizardPageSimple *next);

    void OnSetOpenEMSPath(wxCommandEvent& event);
    void OnSetCSXCADPath(wxCommandEvent& event);
    void OnSetSimulationPath(wxCommandEvent& event);

    wxTextCtrl *TextOpenEMSPath;
    wxTextCtrl *TextCSXCADPath;
    wxTextCtrl *TextSimulationPath;

    wxDECLARE_EVENT_TABLE();
};

#endif // PAGE_START_INCLUDED
