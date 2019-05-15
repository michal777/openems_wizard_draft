//Copyright Michal Stec 2019

#ifndef MAIN_FRAME_H_INCLUDED
#define MAIN_FRAME_H_INCLUDED

#include <wx/wx.h>
#include <wx/textfile.h>


enum
{
    Main_Run_Wizard = 1,
    Main_Open_File = 2
};


class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title);

    wxTextFile *workflowfile;

    void OnOpenFile(wxCommandEvent& event);
    void OnRunWizard(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif // MAIN_FRAME_H_INCLUDED
