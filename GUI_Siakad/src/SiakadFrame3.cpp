#include <iostream>      // Include the header file for iostream library
#include <string>        // Include the header file for string library
#include <vector>        // Include the header file for vector library
#include <math.h>        // Include the header file for math library
#include <wx/combobox.h> // Include the header file for the wxComboBox class

#include "include/SiakadFrame3.hpp" // Include the header file for SiakadFrame3

SiakadFrame3::SiakadFrame3(const wxString &title) : wxFrame(NULL, wxID_ANY, title)
{
    SetBackgroundColour(wxColour(255, 255, 255)); // Set background color to white

    wxPanel *panel = new wxPanel(this); // Create a panel to hold UI elements

    wxImage::AddHandler(new wxPNGHandler); // Add PNG image handler

    // Load images 1, 2, and 3
    wxImage originalImage1 = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/HeaderSIAkademikBG3.png", wxBITMAP_TYPE_PNG);
    if (!originalImage1.IsOk())
    {
        wxMessageBox("Failed to load image!"); // Display error message if image loading fails
        return;
    }
    wxImage originalImage2 = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/SIAkademikBG2.png", wxBITMAP_TYPE_PNG);
    if (!originalImage2.IsOk())
    {
        wxMessageBox("Failed to load image!"); // Display error message if image loading fails
        return;
    }
    wxImage originalImage3 = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/SIAkademikBG1.png", wxBITMAP_TYPE_PNG);
    if (!originalImage3.IsOk())
    {
        wxMessageBox("Failed to load image!"); // Display error message if image loading fails
        return;
    }

    // Define target dimensions for image scaling
    int targetWidth1 = 80;
    int targetHeight1 = 30;
    int targetWidth2 = 800;
    int targetHeight2 = 30;
    int targetWidth3 = 380;
    int targetHeight3 = 290;

    // Scale image 1, 2, and 3 to target dimensions
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

    // Create scaled bitmaps from the images 1, 2, and 3
    wxBitmap scaledBitmap1(originalImage1);
    wxBitmap scaledBitmap2(originalImage2);
    wxBitmap scaledBitmap3(originalImage3);

    // Create static bitmaps for the scaled images
    wxStaticBitmap *bitmap1 = new wxStaticBitmap(panel, wxID_ANY, scaledBitmap1);
    bitmap1->SetPosition(wxPoint(5, 5));
    wxStaticBitmap *bitmap2 = new wxStaticBitmap(panel, wxID_ANY, scaledBitmap2);
    bitmap2->SetPosition(wxPoint(0, 35));
    wxStaticBitmap *bitmap3 = new wxStaticBitmap(panel, wxID_ANY, scaledBitmap3);
    bitmap3->SetPosition(wxPoint(210, 90));

    panel->SetSizerAndFit(new wxBoxSizer(wxVERTICAL)); // Set panel's sizer to fit its contents
    
    // Create arrays for combo box options
    wxArrayString stringsCombo1;
    wxArrayString stringsCombo2;
    wxArrayString stringsCombo3;
    wxArrayString stringsCombo4;
    wxArrayString stringsCombo5;
    wxArrayString stringsCombo6;
    wxArrayString stringsCombo7;
    wxArrayString stringsCombo8;

    // Create bold font 1 and 2
    wxFont boldFont1 = wxFont(wxFontInfo(20).Bold());
    wxFont boldFont2 = wxFont(wxFontInfo().Bold());

    // Create static texts with spesific labels position, and size
    wxStaticText *staticText1 = new wxStaticText(panel, wxID_ANY, "ITS ACADEMIC INFORMATION SYSTEM", wxPoint(208, 10));
    wxStaticText *staticText2 = new wxStaticText(panel, wxID_ANY, "ANNOUNCEMENT OF ENTRY VALUE", wxPoint(280, 100));
    wxStaticText *staticText3 = new wxStaticText(panel, wxID_ANY, "Starting from the 2018 even semester, a new range of values\nwill be applied according to the 2018 Academic Regulations, \nnamely:", wxPoint(220, 120));
    wxStaticText *staticText4 = new wxStaticText(panel, wxID_ANY, "Numeral grade (86-100): Grade A / Exceptional\nNumeral grades (76-85): AB / Very Good grades\nGrade points (66-75): Grade B / Good\nNumerical value (61-65): BC / Fairly Good Value\nNumeral grades (56-60): Grade C / Enough\nNumeral grades (41-55) : Score D / Less\nNumerical value (0-40): Value E / Less than once", wxPoint(250, 180));
    wxStaticText *staticText5 = new wxStaticText(panel, wxID_ANY, "IPD EVEN SEMESTER 2022/2023", wxPoint(300, 300));
    wxStaticText *staticText6 = new wxStaticText(panel, wxID_ANY, "Announced to S3, S2, S1, Diploma Four, and Diploma Three\nstudents are required to fill in the Even semester 2022/2023\nLecturer Teaching Index Questionnaire (IPD) online\nvia the Academic SIM for all courses followed except\nPractical Work/TA/Thesis/Dissertation", wxPoint(220, 320));

    // Create buttons with spesific labels position, and size
    wxButton *button1 = new wxButton(panel, wxID_ANY, wxT("Home"), wxPoint(10, 40), wxSize(70, -1));
    wxButton *button2 = new wxButton(panel, wxID_ANY, wxT("Judiciary"), wxPoint(400, 40), wxSize(70, -1));

    // Add options to combo box strings
    stringsCombo1.Add(wxT("Biodata Verification"));
    stringsCombo1.Add(wxT("Graduation Data Update"));
    stringsCombo1.Add(wxT("Equivalence"));
    stringsCombo2.Add(wxT("Lecturer And MK Question"));
    stringsCombo2.Add(wxT("Semester Curriculum"));
    stringsCombo2.Add(wxT("Study Plan Form"));
    stringsCombo3.Add(wxT("Transcript"));
    stringsCombo3.Add(wxT("Provisional Transcript"));
    stringsCombo3.Add(wxT("Student Academic"));
    stringsCombo3.Add(wxT("Virtual KTM"));
    stringsCombo3.Add(wxT("Student Biodata"));
    stringsCombo3.Add(wxT("Student Lectures"));
    stringsCombo3.Add(wxT("List Of Students & Courses"));
    stringsCombo3.Add(wxT("Status Per Forces"));
    stringsCombo3.Add(wxT("Course Prerequisites"));
    stringsCombo3.Add(wxT("Class Schedule Ms"));
    stringsCombo3.Add(wxT("Value Per Student"));
    stringsCombo3.Add(wxT("Value Per Semester"));
    stringsCombo4.Add(wxT("Student Satisfaction Survey"));
    stringsCombo5.Add(wxT("SKPI Draft"));
    stringsCombo5.Add(wxT("General Guide (pdf)"));
    stringsCombo5.Add(wxT("As a Student (pdf)"));
    stringsCombo6.Add(wxT("SPP Payment History"));
    stringsCombo6.Add(wxT("Tuition Fee Bills"));
    stringsCombo6.Add(wxT("Graduation Payment"));
    stringsCombo7.Add(wxT("Student Mail Service"));
    stringsCombo7.Add(wxT("Service Guide (PDF)"));
    stringsCombo8.Add(wxT("Return to Menus"));
    stringsCombo8.Add(wxT("Logout"));

    // Create combo boxes with spesific labels, position, and size
    wxComboBox *combo1 = new wxComboBox(panel, wxID_ANY, wxT("Data"), wxPoint(88, 40), wxSize(70, -1), stringsCombo1, wxCB_DROPDOWN);
    wxComboBox *combo2 = new wxComboBox(panel, wxID_ANY, wxT("Process"), wxPoint(166, 40), wxSize(70, -1), stringsCombo2, wxCB_DROPDOWN);
    wxComboBox *combo3 = new wxComboBox(panel, wxID_ANY, wxT("Report"), wxPoint(244, 40), wxSize(70, -1), stringsCombo3, wxCB_DROPDOWN);
    wxComboBox *combo4 = new wxComboBox(panel, wxID_ANY, wxT("Etc"), wxPoint(322, 40), wxSize(70, -1), stringsCombo4, wxCB_DROPDOWN);
    wxComboBox *combo5 = new wxComboBox(panel, wxID_ANY, wxT("SKPI"), wxPoint(478, 40), wxSize(70, -1), stringsCombo5, wxCB_DROPDOWN);
    wxComboBox *combo6 = new wxComboBox(panel, wxID_ANY, wxT("Cost Of Education"), wxPoint(556, 40), wxSize(70, -1), stringsCombo6, wxCB_DROPDOWN);
    wxComboBox *combo7 = new wxComboBox(panel, wxID_ANY, wxT("Student Letter"), wxPoint(634, 40), wxSize(70, -1), stringsCombo7, wxCB_DROPDOWN);
    wxComboBox *combo8 = new wxComboBox(panel, wxID_ANY, wxT("Go Out"), wxPoint(712, 40), wxSize(78, -1), stringsCombo8, wxCB_DROPDOWN);

    // Bind event handlers for combo boxes
    combo3->Bind(wxEVT_COMBOBOX, &SiakadFrame3::OnCombo3Selected, this);
    combo8->Bind(wxEVT_COMBOBOX, &SiakadFrame3::OnCombo8Selected, this);

    // Set text color and font for static texts
    staticText1->SetForegroundColour(wxColour(0, 0, 0));
    staticText1->SetFont(boldFont1);
    staticText2->SetForegroundColour(wxColour(0, 0, 0));
    staticText2->SetFont(boldFont2);
    staticText3->SetForegroundColour(wxColour(0, 0, 0));
    staticText4->SetForegroundColour(wxColour(0, 0, 0));
    staticText5->SetForegroundColour(wxColour(0, 0, 0));
    staticText5->SetFont(boldFont2);
    staticText6->SetForegroundColour(wxColour(0, 0, 0));
}

// Event handler for combo box "Go Out" selection
void SiakadFrame3::OnCombo8Selected(wxCommandEvent &event)
{
    wxString selectedOption = event.GetString();

    if (selectedOption == "Logout")
    {
        Close(); // Close SiakadFrame3
    }
}

// Event handler for combo box "Report" selection
void SiakadFrame3::OnCombo3Selected(wxCommandEvent &event)
{
    wxString selectedOption = event.GetString();

    if (selectedOption == "Student Academic")
    {
    }
}