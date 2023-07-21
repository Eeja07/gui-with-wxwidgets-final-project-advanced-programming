// Header guard to prevent multiple inclusions of the same header file
#ifndef SIAKADFRAME1_H
#define SIAKADFRAME1_H

#include <wx/wx.h> // Include the main wxWidgets header file
#include "SiakadFrame2.hpp" // Include the header file for SiakadFrame2

class SiakadFrame2; // Forward declaration of class SiakadFrame2

class SiakadFrame1 : public wxFrame // Defines the SiakadFrame1 class as an instance of wxFrame
{
public:
    SiakadFrame1(const wxString &title); // Constructor for SiakadFrame1

private:
    wxTextCtrl *textCtrl1; // Pointer to wxTextCtrl object 1
    wxTextCtrl *textCtrl2; // Pointer to wxTextCtrl object 2
    wxButton *button; // Pointer to wxButton object
    SiakadFrame2 *siakadFrame2; // Pointer to SiakadFrame2 object
    void OnButtonClicked(wxCommandEvent &evt); // Event handling function when the button is clicked
};

#endif // Closing
