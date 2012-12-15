///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CMiiFrameWFB__
#define __CMiiFrameWFB__

#include <wx/listctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class CMiiFrameWFB
///////////////////////////////////////////////////////////////////////////////
class CMiiFrameWFB : public wxFrame 
{
	private:
	
	protected:
		wxPanel* mainPanel;
		wxListCtrl* list;
		wxButton* b_fetchAll;
		wxButton* b_fetchSel;
		wxStaticLine* m_staticline1;
		wxButton* b_saveFile;
		wxButton* b_loadFile;
		wxPanel* canvasPanel;
	
	public:
		
		CMiiFrameWFB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("CMii"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 660,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~CMiiFrameWFB();
	
};

#endif //__CMiiFrameWFB__
