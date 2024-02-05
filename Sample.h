#ifndef SAMPLE_H
#define SAMPLE_H
#include<iostream>
#include<vector>
#include<stdexcept>
#include "Coordinates.h"

using namespace std;

/// Define a type 'Data' as a pairs, where the first element is an int and the second is a 'Coordinates' object
typedef pair<int, Coordinates> Data;

/// Define a type 'SamplesVector' as a vector of 'Data'
typedef vector<Data> SamplesVector;

/// Overload the output stream operator for 'Data' type
ostream &operator<<(ostream &, const Data &);

/// Overload the output stream operator fot 'SamplesVector' type
ostream &operator<<(ostream &, const SamplesVector &);

class Sample
{	
	public:
		/// Default Constructor
		Sample();
		
		/// Get the samples vector
		static SamplesVector getSamples();
		
		/// Destructor
		~Sample();
		
	private:
		/// Vector to store the samples with indices and coordinates
		static SamplesVector samples;	
		
		///	Set the samples vector
		static void setSamples();
};

#endif