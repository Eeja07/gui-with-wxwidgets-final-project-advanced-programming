#include "include/SiakadFrame1.hpp" // Include the header file for SiakadFrame1
#include "include/SiakadFrame2.hpp" // Include the header file for SiakadFrame2

SiakadFrame1::SiakadFrame1(const wxString &title) : wxFrame(NULL, wxID_ANY, title), siakadFrame2(nullptr)
{
    SetBackgroundColour(wxColour(1, 56, 128)); // Set the background color of the frame

    wxPanel *panel = new wxPanel(this); // Create a panel to hold the UI elements

    wxImage::AddHandler(new wxPNGHandler); // Add a PNG image handler

    // Load the first and second image
    wxImage originalImage1 = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/LogoITSLoginSiakad1.png", wxBITMAP_TYPE_PNG);
    if (!originalImage1.IsOk())
    {
        wxMessageBox("Failed to load image!"); // Display an error message if the image failed to load
        return;
    }
    wxImage originalImage2 = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/LogoITSLoginSiakad2.png", wxBITMAP_TYPE_PNG);
    if (!originalImage2.IsOk())
    {
        wxMessageBox("Failed to load image!"); // Display an error message if the image failed to load
        return;
    }

    // Set the target dimensions for the first and second image
    int targetWidth1 = 75;
    int targetHeight1 = 50;
    int targetWidth2 = 75;
    int targetHeight2 = 30;

    // Rescale the first and second image
    int scaledWidth1, scaledHeight1;
    originalImage1.Rescale(targetWidth1, targetHeight1, wxIMAGE_QUALITY_HIGH);
    scaledWidth1 = originalImage1.GetWidth();
    scaledHeight1 = originalImage1.GetHeight();
    int scaledWidth2, scaledHeight2;
    originalImage2.Rescale(targetWidth2, targetHeight2, wxIMAGE_QUALITY_HIGH);
    scaledWidth2 = originalImage2.GetWidth();
    scaledHeight2 = originalImage2.GetHeight();

    // Create a bitmap from the first and second image
    wxBitmap scaledBitmap1(originalImage1);
    wxBitmap scaledBitmap2(originalImage2);

    // Create a static bitmap and set position bitmap for the first and second image
    wxStaticBitmap *bitmap1 = new wxStaticBitmap(panel, wxID_ANY, scaledBitmap1);
    bitmap1->SetPosition(wxPoint(50, 30));
    wxStaticBitmap *bitmap2 = new wxStaticBitmap(panel, wxID_ANY, scaledBitmap2);
    bitmap2->SetPosition(wxPoint(175, 40));

    panel->SetSizerAndFit(new wxBoxSizer(wxVERTICAL)); // Set the panel's sizer and fit its contents

    // Create a static text label for "myITS ID" and "Password"
    wxStaticText *staticText1 = new wxStaticText(panel, wxID_ANY, "myITS ID", wxPoint(50, 100));
    wxStaticText *staticText2 = new wxStaticText(panel, wxID_ANY, "Password", wxPoint(50, 180));

    wxButton *button1 = new wxButton(panel, wxID_ANY, wxT("Sign In"), wxPoint(50, 260), wxSize(200, -1)); // Create a button labeled "Sign In"

    // Create a text control for "myITS ID" and "Password"
    textCtrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 140), wxSize(200, -1));
    textCtrl2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 220), wxSize(200, -1));

    button1->Bind(wxEVT_BUTTON, &SiakadFrame1::OnButtonClicked, this); // Bind the button click event to the OnButtonClicked event handler

    CreateStatusBar();                                                          // Create a status bar for the frame
    SetStatusText(wxT("                         © Eeja | 2023 | ITS. v0.0.1")); // Set the status bar text
}

void SiakadFrame1::OnButtonClicked(wxCommandEvent &evt)
{
    // Get the value of the "myITS ID" and "Password" text control
    wxString myITSID = textCtrl1->GetValue();
    wxString password = textCtrl2->GetValue();

    if (myITSID.IsEmpty() || myITSID.length() < 10)
    {
        wxMessageBox("Please enter a valid myITS ID (minimum 10 characters)"); // Display an error message if the myITS ID is invalid
        return;
    }

    if (password.IsEmpty())
    {
        wxMessageBox("Please enter the password"); // Display an error message if the password is empty
        return;
    }

    if (!siakadFrame2)
    {
        // Create an instance of SiakadFrame2 if it doesn't exist
        siakadFrame2 = new SiakadFrame2(wxT("Portal Siakad"));
        auto SetClientSizeTo500x500 = [](wxFrame *frame)
        {
            wxSize newSize(800, 375);
            frame->SetClientSize(newSize);
        };

        SetClientSizeTo500x500(siakadFrame2); // Set the client size of siakadFrame2
        siakadFrame2->Show();                 // Show siakadFrame2
    }
    else
    {
        siakadFrame2->Raise(); // Bring siakadFrame2 to the front if it already exists
    }

    Destroy(); // Destroy the current frame

    wxLogStatus("Button Clicked"); // Log a status message
}
