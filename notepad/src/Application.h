#define WXUSINGDLL
#include <wx/wx.h>
#include "Notepad.h"

#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif

class Application : public wxApp
{
public:
    Notepad* notepad = nullptr;
    virtual bool OnInit();
};