#pragma once
#include <wx/wx.h>

#ifdef __WXMSW__
	#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif

class PaintPanel : public wxPanel
{
public:
	PaintPanel(wxFrame* parent);

	bool mouseDown;
	int prevMouseX;
	int prevMouseY;
	int mouseX;
	int mouseY;

	void mouseHandler(wxMouseEvent& event);
	void paintEvent(wxPaintEvent& event);
	void idleEvent(wxIdleEvent& event);
	void render(wxDC& dc);

	wxDECLARE_EVENT_TABLE();
};