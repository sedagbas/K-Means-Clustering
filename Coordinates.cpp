#include "Coordinates.h"

/// Overload the output stream operator for 'Coordinates' type
ostream &operator<<(ostream &output, const Coordinates &coord)
{
 output << fixed << setw(15) << coord.getX() << fixed << setw(15) << coord.getY();	
 
 return output;
}

/// Constructor with initialization of x and y coordinates
Coordinates::Coordinates(const double &x_coor, const double &y_coor)
:	x(x_coor),
	y(y_coor)
{
	/// empty constructor
}
	
	/// Set the x coordinate
	void Coordinates::setX(const double &x_value)
	{
		x = x_value;
	}
	
	/// Set the y coordinate
	void Coordinates::setY(const double &y_value)
	{
		y = y_value;	
	}
	
	/// Set both x and y coordinates
	void Coordinates::setCoordinates(const double &x_value, const double &y_value)
	{
		setX(x_value);
		setY(y_value);
	}
		
	/// Get the x coordinate
	double Coordinates::getX() const
	{
		return x;
	}
	
	/// Get the y coordinate
	double Coordinates::getY() const
	{
		return y;
	}
	
	/// Set random coordinates for a Coordinates object
	void Coordinates::setRandomCoordinates(Coordinates &c)
	{
		c.setCoordinates(rand()%100000, rand()%100000);
	}
	
/// Destructor
Coordinates::~Coordinates()
{
}

