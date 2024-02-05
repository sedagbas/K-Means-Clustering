#include "K_Clusters.h"

/// Overload the output stream operator for 'ClusterVector' type
ostream &operator<<(ostream &output, const ClusterVector &cluster)
{
	for_each(cluster.begin(), cluster.end(), [&](const auto &item) {
        output << item.first << "\t" << item.second << endl;
    });
	cout<<"------------------------------------------------------------"<<endl;  	
    return output;
}

/// Constructor for K_Clusters class
K_Clusters::K_Clusters(const int &NOC, const int &NOI, const ClusterVector &vectorOfClusters, const Coordinates &coor)
:	numberOfClusters(NOC),
	numberOfIterations(NOI)
{
	if(NOC > 39 || NOC < 1 || NOI < 1)
		throw invalid_argument("Number of Clusters must be between 1 and 40 and Number of Iterations must be greater than 0!");

		/// Allocate memory for clusters and centerOfClusters
		clusters = new ClusterVector[getNumberOfClusters()];
		centerOfClusters = new Coordinates[getNumberOfClusters()];
	
		/// Initialize center coordinates of clusters with random values
		for_each(centerOfClusters, centerOfClusters + getNumberOfClusters(), [](Coordinates &coord) 
		{
			coord.setRandomCoordinates(coord); 
		});
}
	/// Get number of iterations
	int K_Clusters::getNumberOfIterations() const
	{
		return numberOfIterations;
	}
	
	/// Get number of Clusters
	int K_Clusters::getNumberOfClusters() const
	{
		return numberOfClusters;
	}
	
	/// Get function for clusters
	ClusterVector* K_Clusters::getClusters() const
	{
		if(clusters != nullptr)
			return clusters;	
		else
			throw runtime_error("Clusters array is null!");
	}
		
	/// Get function for center point of clusters
	Coordinates* K_Clusters::getCenterOfClusters() const
	{
		if(centerOfClusters != nullptr)
			return centerOfClusters;	
		else
			throw runtime_error("Center of Clusters array is null!");
	}
	
	/// Function to set center of clusters
	void K_Clusters::setCenterOfClusters(const int &index, const double &newX, const double &newY)
	{
		centerOfClusters[index].setCoordinates(newX, newY);
	}	
	
	/// Performs a series of iterations to update clusters
	void K_Clusters::runIterations()
	{
		for (int i = 0; i < getNumberOfIterations(); i++)
		{
    		// Clear clusters for the current iteration
    		clearClusters();

    		// Determine clusters for the current iteration
    		determineClusters();   
			
			/// Update the center coordinates of clusters
			updateCenterOfClusters(); 		
		}
	}
	
	/// Clear the clusters
	void K_Clusters::clearClusters()
	{
		for_each(getClusters(), getClusters() + getNumberOfClusters(), [](auto &cluster) {
       		cluster.clear();
    	});	
	}
	
	/// Function to determine clusters
	void K_Clusters::determineClusters()
	{
   		const SamplesVector copy_sample = Sample::getSamples();
	
		for(SamplesVector::const_iterator it=copy_sample.begin(); it!=copy_sample.end(); ++it)
	    {
        	auto minCenter = min_element(getCenterOfClusters(), getCenterOfClusters() + getNumberOfClusters(),[&](const auto &center1, const auto &center2) 
			{
				/// Calculate distance between the data point and the cluster's centre point and return 1 if the distance lower
            	return hypot(center1.getX() - it->second.getX(), center1.getY() - it->second.getY()) < hypot(center2.getX() - it->second.getX(), center2.getY() - it->second.getY());
        	});

        	int holdIndex = distance(getCenterOfClusters(), minCenter);

	        setPoints(it, holdIndex);
		}
	}
	
	/// Separate points into clusters
	void K_Clusters::setPoints(const SamplesVector::const_iterator &i, const int &index)
	{
		Coordinates coor(i->second.getX(), i->second.getY());
	
		string indexString = to_string(index + 1);
	
		clusters[index].push_back(make_pair("CLUSTER " + indexString, make_pair(i->first, coor)));
	}
	
	/// Update the center coordinates of clusters	
	void K_Clusters::updateCenterOfClusters()
	{
		for (int i = 0; i < getNumberOfClusters(); ++i)
		{
   			// Use accumulate to calculate the sum of X and Y coordinates for each cluster
    		double sumX = accumulate(getClusters()[i].begin(), getClusters()[i].end(), 0.0, [](double acc, const auto &item) {
       			return acc + item.second.second.getX();
    		});

   			double sumY = accumulate(getClusters()[i].begin(), getClusters()[i].end(), 0.0, [](double acc, const auto &item) {
        		return acc + item.second.second.getY();
    		});

    		// Calculate the new center coordinates
    		double newCenterX = sumX / getClusters()[i].size();
    		double newCenterY = sumY / getClusters()[i].size();

   			// Set the new center coordinates for the centerOfClusters array
    		setCenterOfClusters(i, newCenterX, newCenterY);
		}
	}
	
	/// Print clusters
	void K_Clusters::printResult() const 
	{
    	cout<<Sample::getSamples();
    	cout<<"************************************************************"<<endl;
		
		/// Print center points of the clusters
		for_each(getCenterOfClusters(), getCenterOfClusters() + getNumberOfClusters(), [&](const auto &center) {
    		cout << "Center Point for Cluster " << &center - centerOfClusters + 1 << " : " << center << endl << endl;
		});
		
		cout << "CLUSTER ID" << setw(9) << fixed << "INDEX" << setw(14) << "X" << setw(15) << "Y" <<endl;

		for_each(getClusters(), getClusters() + getNumberOfClusters(), [](const auto &cluster) {
    		cout << cluster;
		});
	}

/// Destructor
K_Clusters::~K_Clusters()
{
	/// Deleting clusters array
	delete [] clusters;
	delete [] centerOfClusters;
}