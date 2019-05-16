//Copyright Michal Stec 2019

#include "main_frame.h"
#include "wizard.h"


MyFrame::MyFrame(const wxString& title): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1000,600))
{
    wxPanel *mainWindowPanel = new wxPanel(this, wxID_ANY);
    wxButton *runWizardButton = new wxButton(mainWindowPanel, Main_Run_Wizard, wxString("run the wizard"), wxPoint(50,50));

    wxStaticText *StaticText1 = new wxStaticText(mainWindowPanel, -1, _("path to workflow file"), wxPoint(30,20), wxSize(300,20), 0, wxT("ID_ANY"));
    TextWorkflowFilePath = new wxTextCtrl(mainWindowPanel, SetWorkflowFilePath, wxT(""), wxPoint(200,20), wxSize(300,20), 0, wxDefaultValidator, wxT("SetWorkflowFilePath"));
    wxButton *ButtonSetWorkflowFilePath = new wxButton(mainWindowPanel, SetWorkflowFilePath, wxString("..."), wxPoint(520,20), wxSize(20,20));
}

void MyFrame::OnSetWorkflowFilePath(wxCommandEvent& event)
{
    wxFileDialog OpenFileDialog(this, wxT("Open workflow file"), "", "", "workflow file (*.wff_oems)|*.wff_oems", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (OpenFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    TextWorkflowFilePath->ChangeValue(OpenFileDialog.GetPath());
}

void MyFrame::OnRunWizard(wxCommandEvent& event)
{
    workflowfile = new wxTextFile(TextWorkflowFilePath->GetValue());
    workflowfile->Open();
    MyWizard wizard(this, workflowfile);
    wizard.RunWizard(wizard.GetFirstPage());
}


wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(Main_Run_Wizard, MyFrame::OnRunWizard)
    EVT_BUTTON(SetWorkflowFilePath, MyFrame::OnSetWorkflowFilePath)
wxEND_EVENT_TABLE()
