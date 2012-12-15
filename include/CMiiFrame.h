#ifndef _CMiiFrame_h
#define _CMiiFrame_h

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/statline.h>
#include <wx/string.h>
#include <wx/progdlg.h>

#include "CMWiimote.h"
#include "CMiiFrameWFB.h"

class CMiiFrame : public CMiiFrameWFB, public ICMWiimoteListener {
    public:

	CMiiFrame(const wxString& title);
	void OnClose(wxCloseEvent & event);

	CMWiimote *wm;

	wxProgressDialog *progScreen;

	void initializeList();
	void refreshListItem(int i);
	std::string listTextAt(int i);

	// ICMWiimoteListener implementation
	void fetchProgressChanged(int newProgress);

	void OnFetchAll(wxCommandEvent & event);
	void OnFetchSel(wxCommandEvent & event);

	void OnLoadFromFile(wxCommandEvent & event);
	void OnSaveToFile(wxCommandEvent & event);
};

const int ID_FETCHALL = 100;
const int ID_FETCHSEL = 101;

const int ID_LIST = 102;


#endif /*_CMiiFrame_h*/
