///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CMiiFrameWFB.h"

///////////////////////////////////////////////////////////////////////////

CMiiFrameWFB::CMiiFrameWFB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	mainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer( wxHORIZONTAL );
	
	list = new wxListCtrl( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_LIST );
	topSizer->Add( list, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* listAndButtons;
	listAndButtons = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* buttonGroups;
	buttonGroups = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* fetchButtonGroup;
	fetchButtonGroup = new wxBoxSizer( wxHORIZONTAL );
	
	b_fetchAll = new wxButton( mainPanel, wxID_ANY, wxT("Fetch All Miis"), wxDefaultPosition, wxDefaultSize, 0 );
	fetchButtonGroup->Add( b_fetchAll, 1, wxALL, 5 );
	
	b_fetchSel = new wxButton( mainPanel, wxID_ANY, wxT("Fetch Selection"), wxDefaultPosition, wxDefaultSize, 0 );
	fetchButtonGroup->Add( b_fetchSel, 1, wxALL, 5 );
	
	buttonGroups->Add( fetchButtonGroup, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	buttonGroups->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	b_saveFile = new wxButton( mainPanel, wxID_ANY, wxT("Save To File"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( b_saveFile, 1, wxALL, 5 );
	
	b_loadFile = new wxButton( mainPanel, wxID_ANY, wxT("Load from File"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( b_loadFile, 1, wxALL, 5 );
	
	buttonGroups->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* canvasSizer;
	canvasSizer = new wxBoxSizer( wxVERTICAL );
	
	canvasPanel = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	canvasSizer->Add( canvasPanel, 1, wxEXPAND | wxALL, 5 );
	
	buttonGroups->Add( canvasSizer, 5, wxEXPAND, 5 );
	
	listAndButtons->Add( buttonGroups, 1, wxEXPAND, 5 );
	
	topSizer->Add( listAndButtons, 2, wxEXPAND, 5 );
	
	mainPanel->SetSizer( topSizer );
	mainPanel->Layout();
	topSizer->Fit( mainPanel );
	mainSizer->Add( mainPanel, 1, wxEXPAND, 5 );
	
	this->SetSizer( mainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CMiiFrameWFB::~CMiiFrameWFB()
{
}
