#ifndef K_CLUSTERS_H
#define K_CLUSTERS_H
#include "Sample.h"
#include<iterator>
#include<string>
#include<numeric>
#include<cmath>

/// Define a type 'ClusterVector' as a vector of pairs, where the first element is a string and the second is a pair of int and 'Coordinates'
typedef vector<pair<string, Data > > ClusterVector;

/// Overload the output stream operator for 'ClusterVector' type
ostream &operator<<(ostream &, const ClusterVector &);

/// Class definition for 'K_Clusters' derived from 'Sample'
class K_Clusters : private Sample
{
	public:
		/// Default Constructor
		K_Clusters(const int &NOC=1, const int &NOI=100, const ClusterVector &vectorOfClusters = ClusterVector(), const Coordinates &coor = {0.0,0.0});
		
		/// Get function for clusters
		ClusterVector* getClusters() const;
		
		/// Get function for center point of clusters
		Coordinates* getCenterOfClusters() const;
		
		/// Get function for number of clusters
		int getNumberOfClusters() const;
		
		/// Get function for number of iterations
		int getNumberOfIterations() const;
		
		/// Function to update the center coordinates of clusters
		void updateCenterOfClusters();
				
		/// Function to perform iterations
		void runIterations();
		
		/// Function to print the clusters
		void printResult() const;
		
		/// Destructor
		~K_Clusters();
		
	private:
		/// Dynamic array to hold clusters
		ClusterVector *clusters;
		
		/// Dynamic array to hold center coordinates of clusters
		Coordinates *centerOfClusters;
		
		/// Hold the number of Clusters
		const int numberOfClusters;
		
		/// Hold the number of iterations
		const int numberOfIterations;
		
		/// Function to set center of clusters
		void setCenterOfClusters(const int &, const double &, const double &);
		
		/// Function to separate points into clusters
		void setPoints(const SamplesVector::const_iterator &, const int &);
		
		/// Function to determine clusters
		void determineClusters();
		
		/// Function to clear the clusters
		void clearClusters();
};

#endif