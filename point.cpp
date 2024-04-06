/*!*******************************************************************************************************************************************************************************************************************************************************************
\file       point.cpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202
\par        Section:         RSE
\par        Tutorial:        Lab 5
\par        File created on: 10/02/2024
\brief      overloading functions

This file contains 3 constructors, 8 overloaded functions, and 15 non-member, non-friend function definitions to be called by main in q-driver.

    constructors:
    - Point();                                                              // Default constructor, initializes the point to coordinates (0.0, 0.0)
    - Point(double x, double y);                                            // Initialization constructor, initialize x and y coordinate of the point if coordinates
    - Point(double *array);                                                 // Initialization constructor, for initializing coordinates values (x, y)

    overloaded functions:
    - double& operator[](int index);                                        // Accessor to identify coordinate to access in the array (0 for x, 1 for y) and return reference to x or y coordinate.
    - const double& operator[](int index) const;                            // Mutator(read only) to identify coordinate to access in the array (0 for x, 1 for y) and return reference to x or y coordinate.
    - Point& operator+=(const Point& vec);                                  // Translation operator for adding a Point to this point and return reference to this Point after translation.
    - Point& operator+=(double translate);                                  // Translation operator for adding a scalar value to both coordinates and return Reference to this point after translation.
    - Point& operator++();                                                  // Prefix increment operator for incrementing both coordinates, return reference to this point after increment.
    - Point operator++(int);                                                // Postfix increment operator for incrementing both coordinates, return copy of this point before increment.
    - Point& operator--();                                                  // Prefix decrement operator for decrementing both coordinates, return reference to this point after decrement.
    - Point operator--(int);                                                // Postfix decrement operator for decrementing both coordinates, return copy of this point before decrement.

    non-member, non-friend function:
    - Point operator%(const Point& vec, double degrees);                    // Rotation: find the vector after rotation
    - double operator/(const Point& vec1, const Point& vec2);               // Distance: find total distance of the vectors
    - Point operator+(const Point& vec1, const Point& vec2);                // Translation (+ / -): add 2 points
    - Point operator+(const Point& vec, double scalar);                     // Translation (+ / -): add a point then a double
    - Point operator+(double scalar, const Point& vec);                     // Translation (+ / -): add a double then a point 
    - Point operator-(const Point& vec1, const Point& vec2);                // Translation (+ / -): subtract 2 points
    - Point operator-(const Point& vec, double scalar);                     // Translation (+ / -): subtract a point then a double
    - Point operator-(double scalar, const Point& vec);                     // Translation (+ / -): subtract a double then a point 
    - Point operator-(const Point& vec);                                    // Negation(-): flip values
    - Point operator^(const Point& vec1, const Point& vec2);                // Midpoint (^): find mid values
    - double operator*(const Point& vec1, const Point& vec2);               // Dot product (*): vector multiplication
    - Point operator*(const Point& vec, double scalar);                     // Scale (*): multiply the vector by scalar
    - Point operator*(double scalar, const Point& vec);                     // Scale (*): multiply the scalar by vector
    - std::ostream& operator << (std::ostream& os, const Point& point);     // Output (<<): print to the output stream in the format of (x, y)
    - std::istream& operator >> (std::istream& is, Point& point);           // Input (>>): take in user input from input stream	
*********************************************************************************************************************************************************************************************************************************************************************/

#include "point.hpp"  // Point interface
#include <cmath>      // sin, cos, sqrt
# define M_PI 3.14159265358979323846 //pi

// declare private stuff here [if any] in this anonymous namespace ...
namespace {}

namespace hlp2 {
//################################################################################################################################################################################################################################################################
//================================================================================================================================================================================================================================================================
//|                                                                        3 CONSTRUCTORS SECTION                                                                                                                                                                |
//================================================================================================================================================================================================================================================================
    Point::Point() : x(0.0), y(0.0) {}                                                                                           // default constructor, initializes the point to coordinates (0.0, 0.0)
    Point::Point(double x, double y) : x(x), y(y) {}                                                                             // initialization constructor, for initializing x and y coordinate of the point if cordinates
    Point::Point(double *array): x(array[0]), y(array[1]) {}                                                                     // initialization constructor, for initializing coordinates values (x, y)
//================================================================================================================================================================================================================================================================
//|                                                                    8 OVERLOADED FUNCTIONS SECTION                                                                                                                                                            |
//================================================================================================================================================================================================================================================================
    double& Point::operator[](int index) {                                                                                       // accessor 		  to identify coordinate to access in the array (0 for x, 1 for y) and return reference to x or y coordinate.
        if (index == 0) { return x; }
        else if (index == 1) { return y; }
        else { throw std::out_of_range("Index out of range"); }
    }
    const double& Point::operator[](int index) const {                                                                           //mutator(read only) to identify coordinate to access in the array (0 for x, 1 for y) and return reference to x or y coordinate.
        if (index == 0) { return x; } 
        else if (index == 1) { return y; } 
        else { throw std::out_of_range("Index out of range");  }
    }
//****************************************************************************************************************************************************************************************************************************************************************
    Point& Point::operator+=(const Point& vec) {                                                                                 // translation operator for adding a Point to this point and return reference to this Point after translation.
        x += vec[0]; y += vec[1];
        return *this;
    }
    Point& Point::operator+=(double translate) {                                                                                 // translation operator for adding a scalar value to both coordinates and return Reference to this point after translation.
        x += translate; y += translate;
        return *this;
    }
//****************************************************************************************************************************************************************************************************************************************************************
    Point& Point::operator++() {                                                                                                 // prefix increment operator for incrementing both coordinates, return reference to this point after increment.
        ++x; ++y;
        return *this;
    }
    Point Point::operator++(int) {                                                                                               // postfix increment operator for incrementing both coordinates, return copy of this point before increment.
        Point temp(*this);
        ++(*this);
        return temp;
    }
    Point& Point::operator--() {                                                                                                 // prefix decrement operator for decrementing both coordinates, return reference to this point after decrement.
        --x; --y;
        return *this;
    }
    Point Point::operator--(int) {                                                                                               // postfix decrement operator for decrementing both coordinates, return copy of this point before decrement.	
        Point temp(*this);
        --(*this);
        return temp;
    }
//================================================================================================================================================================================================================================================================
//|                                                                   15 NON-MEMBER, NON-FRIEND FUNCTIONS SECTION                                                                                                                                                |
//================================================================================================================================================================================================================================================================
    Point operator%(const Point& vec, double degrees){						                                                     // rotation            find the vector after rotation
        double radians = degrees * M_PI / 180.0;
        double x_val = vec[0] * std::cos(radians) - vec[1] * std::sin(radians);
        double y_val = vec[0] * std::sin(radians) + vec[1] * std::cos(radians);
        return Point(x_val, y_val);
    }
    double operator/(const Point& vec1, const Point& vec2) {				                                                     // distance            find the total distance of the vectors
        double x_val = pow((vec1[0] - vec2[0]),2);
        double y_val = pow((vec1[1] - vec2[1]),2);
        return std::sqrt(x_val + y_val);
    }
//****************************************************************************************************************************************************************************************************************************************************************
    Point operator+(const Point& vec1, const Point& vec2) {	return Point(vec1) += vec2;	}			                             // translation (+ / -)  add 2 points
    Point operator+(const Point& vec, double scalar) {	return Point(vec[0] + scalar, vec[1] + scalar);	}				         // translation (+ / -)  add a point then a double
	Point operator+(double scalar, const Point& vec) { return vec+scalar; }						                                 // translation (+ / -)  add a double then a point
//****************************************************************************************************************************************************************************************************************************************************************
    Point operator-(const Point& vec1, const Point& vec2) { return Point(vec1[0] - vec2[0], vec1[1] - vec2[1]); }		 		 // translation (+ / -)  subtract 2 points
    Point operator-(const Point& vec, double scalar) { return Point(vec[0] - scalar, vec[1] - scalar); }						 // translation (+ / -)	 subtract a point then a double
	Point operator-(double scalar, const Point& vec) { return Point(scalar - vec[0], scalar - vec[1]); }						 // translation (+ / -)  subtract a double then a point 
//****************************************************************************************************************************************************************************************************************************************************************
    Point operator-(const Point& vec) { return Point(-vec[0], -vec[1]); }										                 // negation(-)			 flip values
    Point operator^(const Point& vec1, const Point& vec2) { return Point((vec1[0] + vec2[0])/2, (vec1[1] + vec2[1])/2); }		 // midpoint (^)		 find mid point of 2 coordinates
    double operator*(const Point& vec1, const Point& vec2) { return vec1[0] * vec2[0] + vec1[1] * vec2[1]; }    			     // dot product (*)      vector multiplication
    Point operator*(const Point& vec, double scalar) { return Point(vec[0] * scalar, vec[1] *scalar); }			    		     // scale (*)			multilply the vector by scalar
	Point operator*(double scalar, const Point& vec) { return vec * scalar; }			    		                             // scale (*)			multilply the scalar by vector
//****************************************************************************************************************************************************************************************************************************************************************      
    std::ostream& operator<<(std::ostream& os, const Point& point) {		                                                     // output (<<)         print to the output stream in the format of(x, y)
        os << "(" << point[0] << ", " << point[1] << ")";
        return os;
    }
    std::istream& operator>>(std::istream& is, Point& point) {				                                                     // input (>>)	        take in user input from input stream
        is >> point[0]>> point[1];
        return is;
    }
//################################################################################################################################################################################################################################################################
} // end hlp2 namespace
namespace {
}
