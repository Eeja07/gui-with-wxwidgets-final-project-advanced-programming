#include "include/TriangleFrame1Checker.hpp" // Include the header file for TriangleFrame1Checker
#include "include/TriangleFrame2Checker.hpp" // Include the header file for TriangleFrame2Checker

TriangleFrame1Checker::TriangleFrame1Checker(const wxString &title) : wxFrame(NULL, wxID_ANY, title), triangleFrame2Checker(nullptr)
{
    // Add a PNG image handler to support PNG images
    wxImage::AddHandler(new wxPNGHandler);

    // Load the background image from a file
    m_image = wxImage("/Users/Eeja/wxw/wxWidgets/img_ext/TriangleCheckerMainFrameBG.png", wxBITMAP_TYPE_PNG);
    if (!m_image.IsOk())
    {
        return;
    }

    // Create a panel to hold the image and button
    m_imagePanel = new wxPanel(this, wxID_ANY);

    // Create a vertical box sizer to manage the layout of the panel
    wxBoxSizer *szr = new wxBoxSizer(wxVERTICAL);
    m_imagePanel->SetSizer(szr);

    // Bind the paint event of the panel to the OnImagePanelPaint handler function
    m_imagePanel->Bind(wxEVT_PAINT, &TriangleFrame1Checker::OnImagePanelPaint, this);
    // Bind the size event of the main frame to the OnMainFrameResize handler function
    Bind(wxEVT_SIZE, &TriangleFrame1Checker::OnMainFrameResize, this);

    // Create a button with the label "Triangle Checker"
    wxButton *button = new wxButton(m_imagePanel, wxID_ANY, "Triangle Checker", wxPoint(200, 400), wxSize(150, -1));
    // Bind the button's click event to the OnButtonClicked handler function
    button->Bind(wxEVT_BUTTON, &TriangleFrame1Checker::OnButtonClicked, this);
    // Set the background color of the button
    button->SetBackgroundColour(wxColour(64, 64, 64));

    // Create a vertical box sizer for the image panel
    wxBoxSizer *imagePanelSizer = new wxBoxSizer(wxVERTICAL);
    // Add stretch spacers to center the button vertically
    imagePanelSizer->AddStretchSpacer();
    imagePanelSizer->Add(button, wxSizerFlags(0).Center().Border(wxALL));
    imagePanelSizer->AddStretchSpacer();
    // Set the sizer for the image panel
    m_imagePanel->SetSizer(imagePanelSizer);

    // Create the status bar
    CreateStatusBar();
    // Set the initial status text
    SetStatusText(wxT("Welcome to Triangle Checker !"));

    // Perform the initial layout of the main frame
    Layout();
}

void TriangleFrame1Checker::OnButtonClicked(wxCommandEvent &evt)
{
    // Check if the TriangleFrame2Checker frame is not yet created
    if (!triangleFrame2Checker)
    {
        // Create a new instance of TriangleFrame2Checker
        triangleFrame2Checker = new TriangleFrame2Checker(wxT("Triangle Checker"));

        // Define a lambda function to set the client size of a frame to 500x500
        auto SetClientSizeTo500x500 = [](wxFrame *frame)
        {
            wxSize newSize(500, 250);
            frame->SetClientSize(newSize);
        };

        // Set the client size of the TriangleFrame2Checker frame to 500x500 using the lambda function
        SetClientSizeTo500x500(triangleFrame2Checker);
        // Show the TriangleFrame2Checker frame
        triangleFrame2Checker->Show();
    }
    else
    {
        // If the TriangleFrame2Checker frame is already created, bring it to the front
        triangleFrame2Checker->Raise();
    }

    // Destroy the TriangleFrame1Checker frame
    Destroy();

    // Log a status message indicating that the button was clicked
    wxLogStatus("Button Clicked");
}

void TriangleFrame1Checker::OnImagePanelPaint(wxPaintEvent &)
{
    // Create a device context for painting on the image panel
    wxPaintDC dc(m_imagePanel);
    // Draw the scaled background image on the device context at position (0, 0)
    dc.DrawBitmap(m_scaledBg, 0, 0);
}

void TriangleFrame1Checker::OnMainFrameResize(wxSizeEvent &event)
{
    // Get the current client size of the main frame
    wxSize sz = GetClientSize();
    // Set the size of the image panel to match the client size
    m_imagePanel->SetSize(sz);
    // Create a scaled version of the background image to fit the new size of the image panel
    CreateScaledBg();
    // Allow the event to be processed by other handlers
    event.Skip();
}

void TriangleFrame1Checker::CreateScaledBg()
{
    // Get the size of the image panel
    wxSize sz = m_imagePanel->GetSize();
    // Scale the background image to the size of the image panel using normal image quality
    m_scaledBg = wxBitmap(m_image.Scale(sz.GetWidth(), sz.GetHeight(), wxIMAGE_QUALITY_NORMAL));
}
