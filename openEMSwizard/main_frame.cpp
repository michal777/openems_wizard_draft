//Copyright Michal Stec 2019

#include "main_frame.h"
#include "wizard.h"


MyFrame::MyFrame(const wxString& title): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
{
    wxPanel *mainWindowPanel = new wxPanel(this, wxID_ANY);
    wxButton *runWizardButton = new wxButton(mainWindowPanel, Main_Run_Wizard, wxString("run the wizard"), wxPoint(50,50));
    wxButton *openFileButton = new wxButton(mainWindowPanel, Main_Open_File, wxString("open the file"), wxPoint(50,100));
}

void MyFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog OpenFileDialog(this, wxT("Open workflow file"), "", "", "workflow file (*.wff_oems)|*.wff_oems", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (OpenFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    workflowfile = new wxTextFile(OpenFileDialog.GetPath());
    workflowfile->Open();
}

void MyFrame::OnRunWizard(wxCommandEvent& event)
{
    MyWizard wizard(this, workflowfile);
    wizard.RunWizard(wizard.GetFirstPage());
}


wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(Main_Run_Wizard, MyFrame::OnRunWizard)
    EVT_BUTTON(Main_Open_File, MyFrame::OnOpenFile)
wxEND_EVENT_TABLE()
