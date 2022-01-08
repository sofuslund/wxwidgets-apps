#include "Application.h"

wxIMPLEMENT_APP(Application);

bool Application::OnInit()
{
	frame = new Frame();
	frame->Show();
	return true;
}