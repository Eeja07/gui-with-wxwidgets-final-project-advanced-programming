// Header guard to prevent multiple inclusions of the same header file
#ifndef MYAPP_H
#define MYAPP_H

#include <wx/wx.h>                   // Include the main wxWidgets header file
#include "TriangleFrame1Checker.hpp" // Include the header file for TriangleFrame1Checker
#include "TriangleFrame2Checker.hpp" // Include the header file for TriangleFrame2Checker

class MyApp : public wxApp // Defines the MyApp class as an instance of wxApp
{
public:
    virtual bool OnInit() override; // Override the OnInit() function from wxApp
};

#endif // Closing
