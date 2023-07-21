// Header guard to prevent multiple inclusions of the same header file
#ifndef SIAKADFRAME3_H
#define SIAKADFRAME3_H

#include <wx/wx.h> // Include the main wxWidgets header file

class SiakadFrame3 : public wxFrame // Defines the SiakadFrame3 class as an instance of wxFrame
{
public:
    SiakadFrame3(const wxString &title); // Constructor for SiakadFrame3

private:
    void OnButtonClicked(wxCommandEvent &evt);    // Event handling function when the button is clicked
    void OnTextCtrlChanged(wxCommandEvent &evt);  // Event handling function when the text control is changed
    void OnCombo8Selected(wxCommandEvent &event); // Event handling function when the combo8 is selected
    void OnCombo3Selected(wxCommandEvent &event); // Event handling function when the combo3 is selected
};

#endif // Closing