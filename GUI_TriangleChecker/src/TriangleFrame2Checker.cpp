#include <iostream>     // Include the input/output stream library
#include <string>       // Include the string library
#include <vector>       // Include the vector library
#include <math.h>       // Include the math library
#include <wx/tokenzr.h> // Include the wxStringTokenizer library

#include "include/TriangleChecker.hpp"       // Include the header file for TriangleChecker
#include "include/TrianglePoint2d.hpp"       // Include the header file for TrianglePoint2D
#include "include/TriangleFrame2Checker.hpp" // Include the header file for TriangleFrame2Checker

TriangleFrame2Checker::TriangleFrame2Checker(const wxString &title) : wxFrame(NULL, wxID_ANY, title)
{
    // Set the background color of the frame to light grey
    SetBackgroundColour(wxColour(192, 192, 192));

    // Create a panel to hold the UI elements
    wxPanel *panel = new wxPanel(this);

    // Create static text for input label, result label, and displaying result
    wxStaticText *staticText1 = new wxStaticText(panel, wxID_ANY, "Input Coordinate", wxPoint(200, 15));
    wxStaticText *staticText2 = new wxStaticText(panel, wxID_ANY, "Result :", wxPoint(230, 120));
    wxStaticText *staticText3 = new wxStaticText(panel, wxID_ANY, "", wxPoint(200, 150));

    // Create a text control for input
    wxTextCtrl *textCtrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(200, 50));

    // Create a button for generating the result and exit program
    wxButton *button1 = new wxButton(panel, wxID_ANY, wxT("Generated"), wxPoint(210, 90));
    wxButton *button2 = new wxButton(panel, wxID_ANY, wxT("Exit Program"), wxPoint(398, 225));

    // Bind the click event of the "Generated" button
    button1->Bind(wxEVT_BUTTON, [textCtrl1, staticText3](wxCommandEvent &event)
                  {
    // Get the input value from the text control
    wxString input = textCtrl1->GetValue();

    // Tokenize the input using space as the delimiter
    wxStringTokenizer tokenizer(input, " ");

    // Create a vector to store the coordinates
    std::vector<double> coordinates;

    // Process each token
    while (tokenizer.HasMoreTokens())
    {
        double coordinate;
        wxString token = tokenizer.GetNextToken();
        token.ToDouble(&coordinate);
        coordinates.push_back(coordinate);
    }

    // Check if the number of coordinates is valid
    if (coordinates.size() == 9)
    {
        // Extract the coordinates for each point
        double x1 = coordinates[0];
        double y1 = coordinates[1];
        double z1 = coordinates[2];
        double x2 = coordinates[3];
        double y2 = coordinates[4];
        double z2 = coordinates[5];
        double x3 = coordinates[6];
        double y3 = coordinates[7];
        double z3 = coordinates[8];

        // Create Point2D objects for each vertex
        Point2D t1(x1, y1, z1);
        Point2D t2(x2, y2, z2);
        Point2D t3(x3, y3, z3);

        // Create a Triangle object
        Triangle triangle(t1, t2, t3);

        // Get the type of the triangle
        std::string triangleType = triangle.TriangleType();

        // Update the static text with the triangle type
        staticText3->SetLabelText(wxString(triangleType));
    }
    else
    {
        // Handle invalid input length
    } });

    // Bind the click event of the "Exit Program" button
    button2->Bind(wxEVT_BUTTON, [&](wxCommandEvent &event)
                  {
    // Close the frame
    Close(); });
}