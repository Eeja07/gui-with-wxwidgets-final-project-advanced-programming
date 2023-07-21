#include <wx/combobox.h> // Include the header file for the wxComboBox class

#include "include/SiakadFrame2.hpp" // Include the header file for SiakadFrame2 class
#include "include/SiakadFrame3.hpp" // Include the header file for SiakadFrame3 class

SiakadFrame2::SiakadFrame2(const wxString &title) : wxFrame(NULL, wxID_ANY, title), siakadFrame3(nullptr)
{
    SetBackgroundColour(wxColour(192, 192, 192)); // Set the background color of the frame to a light gray

    wxPanel *panel = new wxPanel(this); // Create a new panel as a child of the frame

    wxImage::AddHandler(new wxJPEGHandler); // Add the JPEG image handler to the image handlers list
    wxImage::AddHandler(new wxPNGHandler);  // Add the PNG image handler to the image handlers list

    wxImage originalImage1 = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/HomePortalSiakadBG.png", wxBITMAP_TYPE_PNG); // Load the first original image from a file
    if (!originalImage1.IsOk())
    {
        wxMessageBox("Failed to load image!"); // Display an error message if the image fails to load
        return;
    }
    wxImage originalImage2 = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/HomePortalSiakad.jpg", wxBITMAP_TYPE_JPEG); // Load the second original image from a file
    if (!originalImage2.IsOk())
    {
        wxMessageBox("Failed to load image!"); // Display an error message if the image fails to load
        return;
    }
    wxImage originalImage3 = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/TextMyitsportal.png", wxBITMAP_TYPE_PNG); // Load the third original image from a file
    if (!originalImage3.IsOk())
    {
        wxMessageBox("Failed to load image!"); // Display an error message if the image fails to load
        return;
    }

    // Specify the target width for scaling the first, second, and third image
    int targetWidth1 = 800;
    int targetHeight1 = 35;
    int targetWidth2 = 610;
    int targetHeight2 = 110;
    int targetWidth3 = 100;
    int targetHeight3 = 30;

    // Rescale to the specified target size and get the width & height of the scaled first, second, and third image
    int scaledWidth1, scaledHeight1;
    originalImage1.Rescale(targetWidth1, targetHeight1, wxIMAGE_QUALITY_HIGH);
    scaledWidth1 = originalImage1.GetWidth();
    scaledHeight1 = originalImage1.GetHeight();
    int scaledWidth2, scaledHeight2;
    originalImage2.Rescale(targetWidth2, targetHeight2, wxIMAGE_QUALITY_HIGH);
    scaledWidth2 = originalImage2.GetWidth();
    scaledHeight2 = originalImage2.GetHeight();
    int scaledWidth3, scaledHeight3;
    originalImage3.Rescale(targetWidth3, targetHeight3, wxIMAGE_QUALITY_HIGH);
    scaledWidth3 = originalImage3.GetWidth();
    scaledHeight3 = originalImage3.GetHeight();

    // Create a scaled bitmap from the first, second, and third original image
    wxBitmap scaledBitmap1(originalImage1);
    wxBitmap scaledBitmap2(originalImage2);
    wxBitmap scaledBitmap3(originalImage3);

    // Create a static bitmap control and set position bitmap using the first, second, and third scaled bitmap
    wxStaticBitmap *bitmap1 = new wxStaticBitmap(panel, wxID_ANY, scaledBitmap1);
    bitmap1->SetPosition(wxPoint(0, 0));
    wxStaticBitmap *bitmap2 = new wxStaticBitmap(panel, wxID_ANY, scaledBitmap2);
    bitmap2->SetPosition(wxPoint(170, 40));
    wxStaticBitmap *bitmap3 = new wxStaticBitmap(panel, wxID_ANY, scaledBitmap3);
    bitmap3->SetPosition(wxPoint(35, 5));

    panel->SetSizerAndFit(new wxBoxSizer(wxVERTICAL)); // Set the sizer for the panel to a vertical box sizer

    // Create a button control with the specific label, position, and size
    wxButton *button1 = new wxButton(panel, wxID_ANY, wxT(""), wxPoint(10, 10), wxSize(150, -1));
    wxButton *button2 = new wxButton(panel, wxID_ANY, wxT("Home"), wxPoint(10, 40), wxSize(150, -1));
    wxButton *button3 = new wxButton(panel, wxID_ANY, wxT("Account"), wxPoint(10, 70), wxSize(150, -1));
    wxButton *button4 = new wxButton(panel, wxID_ANY, wxT("Agenda"), wxPoint(10, 100), wxSize(150, -1));
    wxButton *button5 = new wxButton(panel, wxID_ANY, wxT("Announcement"), wxPoint(10, 130), wxSize(150, -1));
    wxButton *button6 = new wxButton(panel, wxID_ANY, wxT("Check PDDIKTI"), wxPoint(170, 220), wxSize(170, -1));
    wxButton *button7 = new wxButton(panel, wxID_ANY, wxT("myITS Classroom"), wxPoint(370, 220), wxSize(170, -1));
    wxButton *button8 = new wxButton(panel, wxID_ANY, wxT("myITS Presence"), wxPoint(570, 220), wxSize(170, -1));
    wxButton *button9 = new wxButton(panel, wxID_ANY, wxT("myITS Thesis"), wxPoint(170, 250), wxSize(170, -1));
    wxButton *button10 = new wxButton(panel, wxID_ANY, wxT("SI Academic"), wxPoint(370, 250), wxSize(170, -1));
    wxButton *button11 = new wxButton(panel, wxID_ANY, wxT("SI Achievement"), wxPoint(570, 250), wxSize(170, -1));
    wxButton *button12 = new wxButton(panel, wxID_ANY, wxT("myITS StudentConnect"), wxPoint(170, 310), wxSize(170, -1));
    wxButton *button13 = new wxButton(panel, wxID_ANY, wxT("myITS Vote"), wxPoint(370, 310), wxSize(170, -1));
    wxButton *button14 = new wxButton(panel, wxID_ANY, wxT("ORMAWA SIM"), wxPoint(570, 310), wxSize(170, -1));
    wxButton *button15 = new wxButton(panel, wxID_ANY, wxT("YES PKM"), wxPoint(170, 340), wxSize(170, -1));
    wxButton *button16 = new wxButton(panel, wxID_ANY, wxT("SCHEME"), wxPoint(370, 340), wxSize(170, -1));
    wxButton *button17 = new wxButton(panel, wxID_ANY, wxT("Log Out"), wxPoint(10, 340), wxSize(150, -1));

    // Create a static text control with the specific label and position
    wxStaticText *staticText1 = new wxStaticText(panel, wxID_ANY, "Apps and Services", wxPoint(170, 160));
    wxStaticText *staticText2 = new wxStaticText(panel, wxID_ANY, "Academic", wxPoint(170, 190));
    wxStaticText *staticText3 = new wxStaticText(panel, wxID_ANY, "Student Affairs", wxPoint(170, 280));

    wxArrayString strings; // Create an array of strings
    
    // Add a string "ID - Indonesian" and "EN - English"to the array
    strings.Add(wxT("ID - Indonesian"));
    strings.Add(wxT("EN - English"));

    // Create a combobox control with a specific position and size, a list of strings, and a dropdown style
    wxComboBox *combo = new wxComboBox(panel, wxID_ANY, wxT("EN - English"), wxPoint(650, 10), wxSize(130, -1), strings, wxCB_DROPDOWN);

    combo->SetForegroundColour(wxColour(0, 0, 0)); // Set color text in combobox

    // Bind event click in "SI Academic" and "Log Out" button with event handler
    button10->Bind(wxEVT_BUTTON, &SiakadFrame2::OnButtonClicked, this);
    button17->Bind(wxEVT_BUTTON, &SiakadFrame2::OnButtonClicked2, this);
}

void SiakadFrame2::OnButtonClicked(wxCommandEvent &evt)
{
    if (!siakadFrame3)
    {
        // Create a new instance of SiakadFrame3 with the title "SI Akademik"
        siakadFrame3 = new SiakadFrame3(wxT("SI Akademik"));
        auto SetClientSizeTo500x500 = [](wxFrame *frame)
        {
            wxSize newSize(800, 375);      // Create a new size object with width 800 and height 375
            frame->SetClientSize(newSize); // Set the client area size of the frame to the new size
        };

        SetClientSizeTo500x500(siakadFrame3); // Set the client area size of siakadFrame3 to 800x375
        siakadFrame3->Show();                 // Show siakadFrame3 on the screen
    }
    else
    {
        siakadFrame3->Raise(); // Bring the siakadFrame3 to the front if it's already created
    }

    wxLogStatus("Button Clicked"); // Log a message indicating that the button was clicked
}

void SiakadFrame2::OnButtonClicked2(wxCommandEvent &evt)
{
    Destroy(); // Destroy the frame, effectively closing the application

    wxLogStatus("Button Clicked"); // Log a message indicating that the button was clicked
}