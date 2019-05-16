//Copyright Michal Stec 2019

#ifndef MAIN_FRAME_H_INCLUDED
#define MAIN_FRAME_H_INCLUDED

#include <wx/wx.h>
#include <wx/textfile.h>
#include <wx/filedlg.h>

enum
{
    Main_Run_Wizard = 1,
    SetWorkflowFilePath = 2
};


class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title);

    wxTextFile *workflowfile;

    void OnSetWorkflowFilePath(wxCommandEvent& event);
    void OnRunWizard(wxCommandEvent& event);

    wxTextCtrl *TextWorkflowFilePath;

    wxDECLARE_EVENT_TABLE();
};

#endif // MAIN_FRAME_H_INCLUDED
