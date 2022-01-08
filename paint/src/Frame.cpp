#include "Frame.h"

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "Paint!", wxDefaultPosition, wxSize(800, 600))
{
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	PaintPanel* paintPanel = new PaintPanel(this);
	sizer->Add(paintPanel, 1, wxEXPAND);
	SetSizer(sizer);
}
