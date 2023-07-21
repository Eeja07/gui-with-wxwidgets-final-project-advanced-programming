#include "include/TriangleAppChecker.hpp"    // Include the header file for TriangleAppChecker
#include "include/TriangleFrame1Checker.hpp" // Include the header file for TriangleFrame1Checker

IMPLEMENT_APP(MyApp) // Macro to implement the application entry point

bool MyApp::OnInit() // Definition of the OnInit() function
{
    TriangleFrame1Checker *frame = new TriangleFrame1Checker(wxT("Triangle Checker")); // Create a new instance of TriangleFrame1Checker
    frame->SetClientSize(500, 500);                                                    // Set the size of the frame's client area to 500x500 pixels

    frame->Show(true); // Show the frame

    return true; // Return true to indicate successful initialization
}
