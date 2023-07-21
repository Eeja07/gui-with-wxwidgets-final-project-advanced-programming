// Header guard to prevent multiple inclusions of the same header file
#ifndef SIAKADFRAME2_H
#define SIAKADFRAME2_H

#include <wx/wx.h> // Include the main wxWidgets header file
#include "SiakadFrame3.hpp" // Include the header file for SiakadFrame3

class SiakadFrame3; // Forward declaration of class SiakadFrame3
class SiakadFrame2 : public wxFrame // Defines the SiakadFrame2 class as an instance of wxFrame
{
public:
    SiakadFrame2(const wxString &title); // Constructor for SiakadFrame2

private:
    SiakadFrame3 *siakadFrame3;                 // Pointer to SiakadFrame3 object
    void OnButtonClicked(wxCommandEvent &evt);  // Event handling function when the button is clicked
    void OnButtonClicked2(wxCommandEvent &evt); // Event handling function when the button2 is clicked
};

#endif // Closing