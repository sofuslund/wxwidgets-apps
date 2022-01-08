#include "PaintPanel.h"

wxBEGIN_EVENT_TABLE(PaintPanel, wxPanel)
	EVT_MOUSE_EVENTS(PaintPanel::mouseHandler)
	EVT_PAINT(PaintPanel::paintEvent)
	EVT_IDLE(PaintPanel::idleEvent)
wxEND_EVENT_TABLE()

PaintPanel::PaintPanel(wxFrame* parent) : wxPanel(parent)
{
	mouseDown = false;
	prevMouseX = 0;
	prevMouseY = 0;
	mouseX = 0;
	mouseY = 0;
}

void PaintPanel::mouseHandler(wxMouseEvent& event)
{
	if (event.LeftDown())
	{
		mouseDown = true;
	}
	else if (event.LeftUp())
	{
		mouseDown = false;
	}
	prevMouseX = mouseX;
	prevMouseY = mouseY;
	mouseX = event.GetPosition().x;
	mouseY = event.GetPosition().y;
}

void PaintPanel::paintEvent(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	render(dc);
}

void PaintPanel::idleEvent(wxIdleEvent& event)
{
	wxClientDC dc(this);
	render(dc);
	event.RequestMore();
}

void PaintPanel::render(wxDC& dc)
{
	if (mouseDown)
	{
		dc.SetPen(wxPen(wxColour(255, 0, 0)));
		dc.DrawLine(wxPoint(prevMouseX, prevMouseY), wxPoint(mouseX, mouseY));
	}
}