// Exercise 4.2b.1 - Static Variable for Default Array Size
//
// by Scott Sidoli
//
// 5-22-19
//
// Circle.hpp
//
// Circle Class.

#ifndef Circle_hpp
#define Circle_hpp

#include "Point.hpp"


namespace ssidoli
{
	namespace CAD
	{
		class Circle;

		// Global function outside of class for Ostream << operator
		ostream& operator << (ostream& os, const Circle& c);
	}
}

class ssidoli::CAD::Circle : public Shape
{
private:						// center and radius
	Point c;
	double r;

public:
	Circle();							// Constructors
	Circle(const Circle& circ);
	Circle(const Point& center, const double& radius);

	virtual ~Circle();							// Destructor

	Point center() const;				// getter functions
	double radius() const;

	void center(const Point& C);		// setter functions
	void radius(const double& r);

	std::string toString() const;		// toString function

	double diameter() const;			// Circle attribute functions
	double area() const;
	double circumference() const;

	Circle& operator = (const Circle& circ);	// Assignment Operator

	void Draw() const;					// Pure virtual member function
};

#endif


