#include "Application.h"

wxIMPLEMENT_APP(Application);

bool Application::OnInit()
{
	notepad = new Notepad();
	notepad->Show(true);
	return true;
}