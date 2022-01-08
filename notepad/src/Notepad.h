#pragma once
#include <wx/wx.h>

#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif

class Notepad : public wxFrame
{
public:
	Notepad();
private:
	wxMenuBar* menuBar;
	wxMenu* menuFile;
	wxTextCtrl* text;
	void OnNew(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void save();
	void OnExit(wxCommandEvent& event);

	wxString filePath = "";

	wxDECLARE_EVENT_TABLE();
};