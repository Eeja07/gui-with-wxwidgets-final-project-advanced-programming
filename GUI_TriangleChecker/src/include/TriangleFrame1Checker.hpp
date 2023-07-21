// Header guard to prevent multiple inclusions of the same header file
#ifndef TRIANGLEFRAME1CHECKER_H
#define TRIANGLEFRAME1CHECKER_H

#include <wx/wx.h>                   // Include the main wxWidgets header file
#include "TriangleFrame2Checker.hpp" // Include the header file for TriangleFrame2Checker

class TriangleFrame2Checker; // Forward declaration of class TriangleFrame2Checker

class TriangleFrame1Checker : public wxFrame // Defines the TriangleFrame1Checker class as an instance of wxFrame
{
public:
    TriangleFrame1Checker(const wxString &title); // Constructor for TriangleFrame1Checker
    void OnImagePanelPaint(wxPaintEvent &);       // Event handling function when the image panel is repainted
    void CreateScaledBg();                        // Function to create a scaled background
    void OnMainFrameResize(wxSizeEvent &event);   // Event handling function when the main frame is resized

private:
    wxBitmap m_backgroundImage;                   // wxBitmap object to store the background image
    wxImage m_image;                              // wxImage object to store the image
    wxBitmap m_scaledBg;                          // wxBitmap object to store the scaled background
    wxButton *button;                             // Pointer to wxButton object
    wxPanel *m_imagePanel;                        // Pointer to wxPanel object
    TriangleFrame2Checker *triangleFrame2Checker; // Pointer to TriangleFrame2Checker object
    void OnButtonClicked(wxCommandEvent &evt);    // Event handling function when the button is clicked
    void OnEraseBackground(wxEraseEvent &event);  // Event handling function when the background is erased
};

#endif // Closing