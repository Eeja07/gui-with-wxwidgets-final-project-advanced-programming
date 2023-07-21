// Header guard to prevent multiple inclusions of the same header file
#ifndef MYAPP_H
#define MYAPP_H

#include <wx/wx.h> // Include the main wxWidgets header file

class MyApp : public wxApp // Defines the MyApp class as an instance of wxApp
{
public:
    virtual bool OnInit() override; // Override the OnInit() function from wxApp
};

#endif // Closing