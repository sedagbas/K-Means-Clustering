#include "Sample.h"
#include<fstream>
#include <algorithm>

SamplesVector Sample::samples = SamplesVector();

void Sample::setSamples(){
	
    // Initialize samples from file
    ifstream rPtr("40.txt");

    if (!rPtr.is_open())
    {
        throw runtime_error("Error opening file!");
    }

    string line;
    int index = 0;

    while (getline(rPtr, line))
    {
		istringstream lineStream(line);
        double x, y;

    	if (lineStream >> x >> y)
        {
            Coordinates coor(x, y);
            samples.push_back(make_pair(index++, coor));
        }
        else
        {
        	cerr << "Invalid line format: " << line << endl;
        }
    }
}
		
/// Overload the output stream operator for 'Data' type
ostream &operator<<(ostream &output, const SamplesVector &cluster)
{
    output << "INDEX"<< setw(13) << "X" << setw(15) << "Y"<<endl;

    for_each(cluster.begin(), cluster.end(), [&](const auto &item) {
        output << item << endl;
    });

    return output;
}

ostream &operator<<(ostream &output, const Data &pair)
{
	output << pair.first << "\t" << pair.second;
	
	return output;
}

/// Constructor to read coordinates from a file and initialize the samples vector
Sample::Sample()
{
	setSamples();
}
	/// Get the sample vector
	SamplesVector Sample::getSamples()
	{
		return samples;
	}
	
/// Destrcutor
Sample::~Sample()
{
}