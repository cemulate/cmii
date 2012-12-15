#include "CMiiFrame.h"
#include <boost/format.hpp>

#define ASSERT_WIIMOTE_READY(remote) if (remote->wiimoteConnected != 1) { wxMessageBox(_T("No wiimote connected!")); return; }

CMiiFrame::CMiiFrame(const wxString& title)
    : CMiiFrameWFB(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(660, 300)) {

    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(CMiiFrame::OnClose), NULL, this);

    b_fetchAll->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CMiiFrame::OnFetchAll), NULL, this);
    b_fetchSel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CMiiFrame::OnFetchSel), NULL, this);
    b_saveFile->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CMiiFrame::OnSaveToFile), NULL, this);
    b_loadFile->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CMiiFrame::OnLoadFromFile), NULL, this);

    wm = new CMWiimote();
    wm->callbackObject = this;
    wm->connect();
    wm->startMonitoring();

    this->initializeList();

}

void CMiiFrame::OnClose(wxCloseEvent& event) {
    wm->endMonitoring();
    delete wm;
    this->Destroy();
}

void CMiiFrame::initializeList() {
    list->DeleteAllItems();

    int i = 0;
    wxString str;
    for (i = 0; i < 10; i ++) {
		list->InsertItem(i, wxString(this->listTextAt(i).c_str(), wxConvUTF8));
    }
}
void CMiiFrame::refreshListItem(int i) {
    list->DeleteItem(i);
    list->InsertItem(i, wxString(this->listTextAt(i).c_str(), wxConvUTF8));
}

std::string CMiiFrame::listTextAt(int i) {
    if (wm->getMii(i) == NULL) {
		return std::string("<NOT FETCHED>");
    } else {
		if (wm->isMiiUnsaved(i)) {
			return wm->getMii(i)->name + "*";
		} else {
			return wm->getMii(i)->name;
		}
    }
}

void CMiiFrame::fetchProgressChanged(int newProgress) {
    progScreen->Update(newProgress);
}

void CMiiFrame::OnFetchAll(wxCommandEvent & WXUNUSED(event)) {
    ASSERT_WIIMOTE_READY(wm)
    progScreen = new wxProgressDialog(_T("Fetching all miis"), _T("Reading all 10 miis from wii remote"), 100, this);
    wm->populateMiis();
    progScreen->Destroy();
    this->initializeList();
}

void CMiiFrame::OnFetchSel(wxCommandEvent & WXUNUSED(event)) {
    ASSERT_WIIMOTE_READY(wm)
    int index = list->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    if (index < 0) {
		wxMessageBox(_T("No selection. Please select a spot in the list to fetch"));
		return;
    }
    wm->fetchMii(index);
    wxMessageBox(_T("Done!"));
    this->initializeList();
}

void CMiiFrame::OnLoadFromFile(wxCommandEvent & WXUNUSED(event)) {
    ASSERT_WIIMOTE_READY(wm)
}

void CMiiFrame::OnSaveToFile(wxCommandEvent & WXUNUSED(event)) {
    ASSERT_WIIMOTE_READY(wm)
    int index = list->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    if (index < 0) {
		wxMessageBox(_T("No selection. Please select a mii in the list to save"));
		return;
    }

    if (wm->getMii(index) == NULL) {
		wxMessageBox(_T("The mii you selected has not been fetched yet. Please fetch selection before attempting to save"));
		return;
    }

    wxFileDialog saveDialog(this, _T("Save Mii Data"), _T(""), _T(""), _T("mii files (*.mii)|*.mii"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveDialog.ShowModal() == wxID_CANCEL) {
		return;
    }

    wm->getMii(index)->writeToFile(std::string(saveDialog.GetPath().mb_str()));
}
