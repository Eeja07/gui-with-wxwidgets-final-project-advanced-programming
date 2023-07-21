// Header guard to prevent multiple inclusions of the same header file
#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "TrianglePoint2d.hpp" // Include the header file for TrianglePoint2d

class Triangle // Defines the Triangle class
{
private:
    Point2D _t1, _t2, _t3; // Private member variables for storing the coordinates of the triangle's vertices

public:
    Triangle();                                   // Default constructor
    Triangle(Point2D t1, Point2D t2, Point2D t3); // Constructor with parameters to set the coordinates of the triangle's vertices

    // Setter functions to set the coordinates of each vertex
    void SetT1(Point2D t1);
    void SetT2(Point2D t2);
    void SetT3(Point2D t3);

    // Getter functions to retrieve the coordinates of each vertex
    Point2D GetT1() const { return _t1; }
    Point2D GetT2() const { return _t2; }
    Point2D GetT3() const { return _t3; }

    // Function to determine the type of the triangle
    std::string TriangleType();
};

#endif // Closing

