/*!*******************************************************************************************************************************************************************************************************************************************************************
\file       point.hpp
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

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream> // istream, ostream

namespace hlp2 {
//####################################################################################################################################################################################################################################################################
class Point {
private:
	double x; 																			// x-coordinate of a point
	double y; 																			// y-coordinate of a point
//********************************************************************************************************************************************************************************************************************************************************************
public:
	//================================================================================================================================================================================================================================================================
	//|                                                                        3 CONSTRUCTORS SECTION                                                                                                                                                                |
	//================================================================================================================================================================================================================================================================
	Point(); 																			// default constructor, initializes the point to coordinates (0.0, 0.0)
	Point(double x, double y); 															// initialization constructor, initialize x and y coordinate of the point if cordinates
	Point(double *array);																// initialization constructor, for initializing coordinates values (x, y)
	//================================================================================================================================================================================================================================================================
	//|                                                                    8 OVERLOADED FUNCTIONS SECTION                                                                                                                                                            |
	//================================================================================================================================================================================================================================================================
    double& operator[](int index);														// accessor 		  to identify coordinate to access in the array (0 for x, 1 for y) and return reference to x or y coordinate.
	const double& operator[](int index) const;											// mutator(read only) to identify coordinate to access in the array (0 for x, 1 for y) and return reference to x or y coordinate.
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Point& operator+=(const Point& vec);												// translation operator for adding a Point to this point and return reference to this Point after translation.
    Point& operator+=(double translate);				    							// translation operator for adding a scalar value to both coordinates and return Reference to this point after translation.
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Point& operator++(); 																// prefix increment operator for incrementing both coordinates, return reference to this point after increment.
    Point operator++(int);																// postfix increment operator for incrementing both coordinates, return copy of this point before increment.
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Point& operator--();																// prefix decrement operator for decrementing both coordinates, return reference to this point after decrement.
	Point operator--(int);																// postfix decrement operator for decrementing both coordinates, return copy of this point before decrement.	
};
	//================================================================================================================================================================================================================================================================
	//|                                                                   15 NON-MEMBER, NON-FRIEND FUNCTIONS SECTION                                                                                                                                                |
	//================================================================================================================================================================================================================================================================
	Point operator%(const Point& vec, double degrees);									// rotation            find the vector after rotation
    double operator/(const Point& vec1, const Point& vec2) ;							// distance            find  total distance of the vectors
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Point operator+(const Point& vec1, const Point& vec2) ;								// translation (+ / -)  add 2 points
    Point operator+(const Point& vec, double scalar);									// translation (+ / -)  add a point then a double
	Point operator+(double scalar, const Point& vec);									// translation (+ / -)  add a double then a point 
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Point operator-(const Point& vec1, const Point& vec2);								// translation (+ / -)  subtract 2 points
    Point operator-(const Point& vec, double scalar) ;									// translation (+ / -)	subtract a point then a double
	Point operator-(double scalar, const Point& vec) ;									// translation (+ / -)  subtract a double then a point 
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Point operator-(const Point& vec) ;													// negation(-)			flip values
    Point operator^(const Point& vec1, const Point& vec2) ;								// midpoint (^)			find mid values
    double operator*(const Point& vec1, const Point& vec2);    							// dot product (*)      vector multiplication
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Point operator*(const Point& vec, double scalar);			    					// scale (*)			multilply the vector by scalar
	Point operator*(double scalar, const Point& vec);			    					// scale (*)			multilply the scalar by vector
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	std::ostream& operator << (std::ostream& os, const Point& point);					// output (<<)         print to the output stream in the format of(x, y)
	std::istream& operator >> (std::istream& is, Point& point);							// input (>>)	        take in user input from input stream	
//#####################################################################################################################################################################################################################################################################
} // end namespace hlp2

#endif // end POINT_HPP

