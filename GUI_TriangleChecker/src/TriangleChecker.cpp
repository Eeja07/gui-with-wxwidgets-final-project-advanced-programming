#include <iostream> // Include the input/output stream library
#include <cmath>    // Include the math library

#include "include/TriangleChecker.hpp" // Include the header file for TriangleChecker

Triangle::Triangle() {} // Default constructor for Triangle class

Triangle::Triangle(Point2D t1, Point2D t2, Point2D t3) : _t1(t1), _t2(t2), _t3(t3) {} // Constructor with parameters to set the coordinates of the triangle's vertices

// Setter function to set the coordinates of vertex T1, T2, and T3
void Triangle::SetT1(Point2D t1) { _t1 = t1; }
void Triangle::SetT2(Point2D t2) { _t2 = t2; }
void Triangle::SetT3(Point2D t3) { _t3 = t3; }

// Function to calculate the Euclidean distance between two points in 3D space
float distance(int x1, int y1, int z1, int x2, int y2, int z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

// Function to determine the type of the triangle based on its side lengths
std::string Triangle::TriangleType()
{
    float side1 = distance(_t1.GetX(), _t1.GetY(), _t1.GetZ(), _t2.GetX(), _t2.GetY(), _t2.GetZ());
    float side2 = distance(_t2.GetX(), _t2.GetY(), _t2.GetZ(), _t3.GetX(), _t3.GetY(), _t3.GetZ());
    float side3 = distance(_t3.GetX(), _t3.GetY(), _t3.GetZ(), _t1.GetX(), _t1.GetY(), _t1.GetZ());

    float tolerance = 1e-6; // Tolerance for floating-point comparison

    // Check the conditions to determine the type of the triangle
    if (fabs(side1 - side2) < tolerance && fabs(side2 - side3) < tolerance)
    {
        return "Segitiga Sama Sisi"; // Return Equilateral triangle
    }
    else if (fabs(side1 * side1 + side2 * side2 - side3 * side3) < tolerance ||
             fabs(side2 * side2 + side3 * side3 - side1 * side1) < tolerance ||
             fabs(side3 * side3 + side1 * side1 - side2 * side2) < tolerance)
    {
        return "Segitiga Siku-Siku"; // Return Right-angled triangle
    }
    else if (fabs(side1 - side2) < tolerance || fabs(side2 - side3) < tolerance || fabs(side1 - side3) < tolerance)
    {
        return "Segitiga Sama Kaki"; // Return Isosceles triangle
    }
    else
    {
        return "Segitiga Sembarang"; // Return Scalene triangle
    }
}
