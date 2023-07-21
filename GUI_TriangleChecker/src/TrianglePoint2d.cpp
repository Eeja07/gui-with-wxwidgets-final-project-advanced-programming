#include <iostream> // Include the input/output stream library
#include <math.h>   // Include the math library

#include "include/TrianglePoint2d.hpp" // Include the header file for TrianglePoint2D

Point2D::Point2D() : _x(0), _y(0), _z(0) {} // Default constructor for Point2D with initial values (_x, _y, _z) = (0, 0, 0)

Point2D::Point2D(float x, float y, float z) : _x(x), _y(y), _z(z) {} // Constructor for Point2D with given values (x, y, z)

Point2D Point2D::operator+(const Point2D inp) // Addition operator for Point2D
{
    // Set the x, y,and z value of the 'out' object by adding the x, y, and z values of two Point2D objects
    Point2D out;
    out.SetX(this->_x + inp.GetX());
    out.SetY(this->_y + inp.GetY());
    out.SetZ(this->_z + inp.GetZ());
    return out; // Return the 'out' object as the result of addition
}

Point2D Point2D::operator-(const Point2D inp) // Subtraction operator for Point2D
{
    // Set the x, y,and z value of the 'out' object by subtracting the x, y, and z values of two Point2D objects
    Point2D out;
    out.SetX(this->_x - inp.GetX());
    out.SetY(this->_y - inp.GetY());
    out.SetZ(this->_z - inp.GetZ());
    return out; // Return the 'out' object as the result of subtraction
}

Point2D Point2D::operator*(const Point2D inp) // Multiplication operator for Point2D
{
    // Set the x, y,and z value of the 'out' object by multiplying the x, y, and z values of two Point2D objects
    Point2D out;
    out.SetX(this->_x * inp.GetX());
    out.SetY(this->_y * inp.GetY());
    out.SetZ(this->_z * inp.GetZ());
    return out; // Return the 'out' object as the result of multiplication
}
