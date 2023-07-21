// Header guard to prevent multiple inclusions of the same header file
#ifndef TRIANGLEFRAME2CHECKER_H
#define TRIANGLEFRAME2CHECKER_H

#include <wx/wx.h> // Include the main wxWidgets header file

class TriangleFrame2Checker : public wxFrame // Defines the TriangleFrame2Checker class as an instance of wxFrame
{
public:
    TriangleFrame2Checker(const wxString &title); // Constructor for TriangleFrame2Checker

private:
    TriangleFrame2Checker *triangleFrame2Checker; // Pointer to TriangleFrame2Checker object
    void OnButtonClicked(wxCommandEvent &evt);    // Event handling function when the button is clicked
    void OnTextCtrlChanged(wxCommandEvent &evt);  // Event handling function when the text control is changed
};

#endif // Closing