//Copyright Michal Stec 2019

#include "main_app.h"
#include "main_frame.h"


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("main window");
    frame->Show(true);
    return true;
}
