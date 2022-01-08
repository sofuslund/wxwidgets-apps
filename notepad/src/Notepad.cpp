#include "Notepad.h"

wxBEGIN_EVENT_TABLE(Notepad, wxFrame)
EVT_MENU(wxID_NEW, Notepad::OnNew)
EVT_MENU(wxID_OPEN, Notepad::OnOpen)
EVT_MENU(wxID_SAVE, Notepad::OnSave)
EVT_MENU(wxID_EXIT, Notepad::OnExit)
wxEND_EVENT_TABLE()

Notepad::Notepad() : wxFrame(nullptr, wxID_ANY, "Notepad!", wxDefaultPosition, wxSize(800, 600))
{
    // Setup the menu bar and it contents
    menuBar = new wxMenuBar;
    menuFile = new wxMenu;

    menuFile->Append(wxID_NEW);
    menuFile->Append(wxID_OPEN);
    menuFile->Append(wxID_SAVE);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    menuBar->Append(menuFile, _("&File"));
    SetMenuBar(menuBar);

    // Make the text area
    this->text = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);
}

void Notepad::OnNew(wxCommandEvent& event)
{
    auto response = wxMessageBox("Do you want to save the changes? ", "Notepad", wxYES_NO | wxCANCEL, this);
    if (response == wxID_YES)
    {
        save();
    }
    filePath = "";
    text->SetLabelText("");
}

void Notepad::OnOpen(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, "Open file", "", "", "txt files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    auto response = openFileDialog.ShowModal();
    if (response == wxID_OK)
    {
        response = wxMessageBox("Do you want to save the changes? ", "Notepad", wxYES_NO | wxCANCEL, this);
        if (response == wxID_YES)
        {
            save();
        }
        text->LoadFile(openFileDialog.GetPath());
        filePath = openFileDialog.GetPath();
    }
}

void Notepad::OnSave(wxCommandEvent& event)
{
    save();
}

void Notepad::save()
{
    if (filePath == "")
    {
        wxFileDialog saveFileDialog(this, "Save file", "", "", "Text file (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
        auto response = saveFileDialog.ShowModal();
        if (response == wxID_OK)
        {
            filePath = saveFileDialog.GetPath();
        }
        else if (response == wxID_CANCEL)
        {
            return;
        }
    }
    text->SaveFile(filePath);
}

void Notepad::OnExit(wxCommandEvent& event)
{
    auto response = wxMessageBox("Do you want to save the changes? ", "Notepad", wxYES_NO | wxCANCEL, this);
    if (response == wxID_YES)
    {
        save();
    }
    this->Destroy();
}
