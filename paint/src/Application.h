#pragma once
#include <wx/wx.h>
#include "Frame.h"

class Application : public wxApp
{
public:
	virtual bool OnInit();
private:
	Frame* frame;
};
