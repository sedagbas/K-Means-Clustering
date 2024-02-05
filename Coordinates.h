#ifndef COORDINATES_H
#define COORDINATES_H
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<iomanip>

using namespace std;

class Coordinates
{	
	/// Overload the output stream operator for 'Coordinates' type
	friend ostream &operator<<(ostream &output, const Coordinates &coord);
	
	public:
		/// Constructor
		Coordinates(const double &x_coor=0.0, const double &y_coor=0.0);
		
		/// Set x coordinates 
		void setX(const double &);
		/// Set y coordinates
		void setY(const double &);
		/// Set both x and y coordinates  
		void setCoordinates(const double &, const double &);
		
		/// Get the x coordinates 
		double getX() const;
		/// Get the y coordinates
		double getY() const;
		
		/// Set random coordinates for a Coordinates object
		void setRandomCoordinates(Coordinates &);

		/// Destructor
		~Coordinates();
	private:
		/// x coordinate
		double x;
		/// y coordinate
		double y;
};

#endif
