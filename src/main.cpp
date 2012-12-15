#include "main.h"
#include "CMiiFrame.h"

IMPLEMENT_APP(CMiiApp);

bool CMiiApp::OnInit() {

    CMiiFrame *frame = new CMiiFrame(wxT("Button"));
    frame->Show(true);

//    MyFrame* MainFrame = new MyFrame;
//	MainFrame->Show();

	return true;
}
