#include <iostream>
#include "K_Clusters.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int cluster;
	int iteration;
	
	cout<<"Enter the number of cluster: ";
	cin>>cluster;
	cout<<"Enter the number of iterations: ";
	cin>>iteration;
	
	try
	{
		/// Creating an object of K_Clusters with number of clusters and iterations
		K_Clusters c(cluster, iteration);
		
		/// Run iterations
		c.runIterations();
		
		/// Display the result
		c.printResult();
	}
	catch (const exception &e)
	{
		cout<<"Exception caught: "<<e.what()<<endl;
	}
	
	return 0;
}