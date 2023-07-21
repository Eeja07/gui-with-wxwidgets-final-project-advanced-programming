// Header guard to prevent multiple inclusions of the same header file
#ifndef __POINT2D_HPP__
#define __POINT2D_HPP__

class Point2D // Defines the Point2d class
{
private:
    float _x, _y, _z; // Private member variables to store the coordinates of the point in 2D space

public:
    Point2D();                          // Default constructor
    Point2D(float x, float y, float z); // Constructor with parameters to set the coordinates of the point

    // Getter function to retrieve the x, y, and z-coordinate of the point
    float GetX() const { return _x; };
    float GetY() const { return _y; };
    float GetZ() const { return _z; };

    // Inline setter function to set the x, y, and z-coordinate of the point
    inline void SetX(float x) { _x = x; }
    inline void SetY(float y) { _y = y; }
    inline void SetZ(float z) { _z = z; }

    // Overloaded '+', '-', and '*' operator to perform addition, subtraction, and multiplication of two Point2D objects
    Point2D operator+(const Point2D inp);
    Point2D operator-(const Point2D inp);
    Point2D operator*(const Point2D inp);
};

#endif // Closing
