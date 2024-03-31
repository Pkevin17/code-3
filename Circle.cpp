#include <iostream>
using namespace std;

#include "Circle.h"

/**
* \brief To instantiate a new circle object.
* \details <b>Details</b>
*
* This is a default constructor that creates the circle object.
* \param colour  - <b>string</b> - representation of the circle's colour
* \param radius - <b>string</b> - representation of the circle's radius
*
* \return As this is a <i>constructor</i> for the Circle class, nothing is returned.
*
* \see Circle::Circle(const string& colour, float radius) : Shape("Circle", colour)
*/
Circle::Circle(const string& colour, float radius) : Shape("Circle", colour) {
    SetRadius(radius);
}
/**
* \brief To instantiate a new circle object.
* \details <b>Details</b>
*
* This is a default constructor that creates the circle object.
* \param none
*
* \return As this is a <i>constructor</i> for the Circle class, nothing is returned.
*
* \see Circle::Circle() : Shape("Circle", "undefined")
*/
Circle::Circle() : Shape("Circle", "undefined") {
    SetRadius(0);
}
/**
* \brief To get the value of the circle's radius.
* \details <b>Details</b>
*
* This accessor retrieves the radius's value of the circle.
* \param none
*
* \return returns the radius's value of the circle.
*
* \see Circle::GetRadius()
*/
float Circle::GetRadius() const {
    return radius;
}
/**
* \brief To set the value of the radius of the circle.
* \details <b>Details</b>
*
* This mutator retrieves the circle's radius with certains exceptions.
* \param name - <b>float<b> - representation of the circle's radius.
*
* \return nothing is returned
*
* \see Circle::SetRadius(float radius)
*/
void Circle::SetRadius(float radius) {
    if (radius >= 0) {

        this->radius = radius;
    }
    else {
        this->radius = 0;
    }
}
/**
* \brief To find the perimeter of the circle
* \details <b>Details</b>
*
* This function is to calculate the perimeter of the circle
* \param none
*
* \return value of perimeter
*
* \see Circle::Perimeter()
*/
float Circle::Perimeter() const {
    return 2 * 3.1415926 * radius;
}
/**
* \brief To find the area of the circle
* \details <b>Details</b>
*
* This function is to calculate the area of the circle
* \param none
*
* \return value of area
*
* \see Circle::Area()
*/
float Circle::Area() const {
    return 3.1415926 * radius * radius;
}
/**
* \brief To find the overalldimension of the circle
* \details <b>Details</b>
*
* This function is to calculate the overalldimension of the circle
* \param none
*
* \return value of overalldimension
*
* \see Circle::OverallDimension()
*/
float Circle::OverallDimension() const {
    return 2 * radius;
}
/**
* \brief Overloaded addition operator for Circle objects.
* \details <b>Details</b>
*
* This function overloads the '+' operator to perform addition between two Circle objects.
* It creates a new Circle with the color of the calling object and a radius equal to the sum of the
* calling object's radius and the radius of the right-hand side Circle object.
* \param rhs The Circle object on the right-hand side of the '+' operator.
*
* \return A new Circle object with the calculated radius.
*
* \see Circle::operator+()
*/
Circle Circle::operator+(const Circle& rhs) const {
    Circle result(GetColour(), radius + rhs.radius);
    return result;
}
/**
* \brief Overloaded multiplication operator for Circle objects.
* \details <b>Details</b>
*
* This function overloads the '*' operator to perform multiplication between two Circle objects.
* It creates a new Circle with the color of the right-hand side Circle object and a radius equal to
* the product of the calling object's radius and the radius of the right-hand side Circle object.
* \param rhs The Circle object on the right-hand side of the '*' operator.
*
* \return A new Circle object with the calculated radius.
*
* \see Circle::operator*()
*/
Circle Circle::operator*(const Circle& rhs) const {
    Circle result(rhs.GetColour(), radius * rhs.radius);
    return result;
}
/**
* \brief Overloaded equality operator for Circle objects.
* \details <b>Details</b>
*
* This function overloads the '==' operator to compare two Circle objects for equality.
* It checks if the calling object's radius is approximately equal to the radius of the right-hand side Circle
* object within a small epsilon value (epsilon is used to handle floating-point precision issues).
* \param rhs The Circle object on the right-hand side of the '==' operator.
*
* \return True if the radii are approximately equal; otherwise, false.
*
* \see Circle::operator==()
*/
bool Circle::operator==(const Circle& rhs) const {
    const float epsilon = 0.0001;
    return (abs(radius - rhs.radius) < epsilon && GetColour() == rhs.GetColour());
}
/**
* \brief To print the required information of the circle object
* \details <b>Details</b>
*
* This function displays all information pertaining to the circle object.
* \param none
*
* \return none
*
* \see Circle::Show()
*/
void Circle::Show() const {
    cout << "Shape Information" << endl;
    cout << "Name: " << GetName() << endl;
    cout << "Colour: " << GetColour() << endl;
    cout << "Radius: " << GetRadius() << " cm" << endl;
    cout << "Circumference: " << Perimeter() << " cm" << endl;
    cout << "Area: " << Area() << " square cm" << endl;
}
