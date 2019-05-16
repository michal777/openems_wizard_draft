#include "page_1.h"

PageStart::PageStart(wxWizard *parent, wxWizardPageSimple *prev, wxWizardPageSimple *next): wxWizardPageSimple(parent, prev, next)
{
    wxStaticText *StaticText1 = new wxStaticText(this, -1, _("path to ...openEMS/matlab"), wxPoint(30,20), wxSize(300,20), 0, wxT("ID_ANY"));
    TextOpenEMSPath = new wxTextCtrl(this, SetOpenEMSPath, wxT(""), wxPoint(200,20), wxSize(300,20), 0, wxDefaultValidator, wxT("SetOpenEMSPath"));
    wxButton *ButtonSetOpenEMSPath = new wxButton(this, SetOpenEMSPath, wxString("..."), wxPoint(520,20), wxSize(20,20));

    wxStaticText *StaticText2 = new wxStaticText(this, -1, _("path to ...CSXCAD/matlab"), wxPoint(30,50), wxSize(300,20), 0, wxT("ID_ANY"));
    TextCSXCADPath = new wxTextCtrl(this, SetCSXCADPath, wxT(""), wxPoint(200,50), wxSize(300,20), 0, wxDefaultValidator, wxT("SetCSXCADPath"));
    wxButton *ButtonSetCSXCADPath = new wxButton(this, SetCSXCADPath, wxString("..."), wxPoint(520,50), wxSize(20,20));

    wxStaticText *StaticText3 = new wxStaticText(this, -1, _("path to simulation directory"), wxPoint(30,80), wxSize(300,20), 0, wxT("ID_ANY"));
    TextSimulationPath = new wxTextCtrl(this, SetSimulationPath, wxT(""), wxPoint(200,80), wxSize(300,20), 0, wxDefaultValidator, wxT("SetSimulationPath"));
    wxButton *ButtonSetSimulationPath = new wxButton(this, SetSimulationPath, wxString("..."), wxPoint(520,80), wxSize(20,20));


}

void PageStart::OnSetOpenEMSPath(wxCommandEvent& event)
{
    wxDirDialog OpenDirDialog(this);
    if (OpenDirDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    TextOpenEMSPath->ChangeValue(OpenDirDialog.GetPath());
}
void PageStart::OnSetCSXCADPath(wxCommandEvent& event)
{
    wxDirDialog OpenDirDialog(this);
    if (OpenDirDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    TextCSXCADPath->ChangeValue(OpenDirDialog.GetPath());
}
void PageStart::OnSetSimulationPath(wxCommandEvent& event)
{
    wxDirDialog OpenDirDialog(this);
    if (OpenDirDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    TextSimulationPath->ChangeValue(OpenDirDialog.GetPath());
}

wxBEGIN_EVENT_TABLE(PageStart, wxWizardPageSimple)
    EVT_BUTTON(SetOpenEMSPath, PageStart::OnSetOpenEMSPath)
    EVT_BUTTON(SetCSXCADPath, PageStart::OnSetCSXCADPath)
    EVT_BUTTON(SetSimulationPath, PageStart::OnSetSimulationPath)
wxEND_EVENT_TABLE()
