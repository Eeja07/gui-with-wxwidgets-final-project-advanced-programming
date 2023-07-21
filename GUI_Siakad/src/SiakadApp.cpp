#include "include/SiakadApp.hpp" // Include the header file for SiakadApp
#include "include/SiakadFrame1.hpp" // Include the header file for SiakadFrame1

IMPLEMENT_APP(MyApp) // Macro to implement the application entry point

bool MyApp::OnInit() // Definition of the OnInit() function
{
    SiakadFrame1 *frame = new SiakadFrame1(wxT("Siakad")); // Create a new instance of SiakadFrame1
    frame->SetClientSize(300, 350);                        // Set the size of the frame's client area to 500x500 pixels

    frame->Show(true); // Show the frame

    return true; // Return true to indicate successful initialization
}