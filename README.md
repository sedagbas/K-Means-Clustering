# K-Means-Clustering
In this project, a class hierarchy to implement the K-Means clustering method was designed.

1. The "Coordinates" class is the foundational element, encapsulating the x and y coordinates of points in a two-dimensional space. This class was conceived to represent individual data points, allowing for easy manipulation and retrieval of coordinates.
  
2. The "Sample" class was introduced to manage the input data from an external file. By employing a static vector to hold the sample points, this class ensures that the data is efficiently stored and accessible throughout the program. The design decision to encapsulate file reading and sample vector initialization within the constructor enhances the class's usability and reduces the burden on the end-user.

3. The "K_Clusters" class, derived from "Sample," which encapsulates the K-Means clustering logic. This design choice enables the seamless integration of clustering functionalities while maintaining a clear separation of concerns among different classes.

**OUTPUT**

![cikti1](https://github.com/sedagbas/K-Means-Clustering/assets/159046448/c1c57eb7-bcbd-431d-b44a-5aa9de9a18ab)
![cikti2](https://github.com/sedagbas/K-Means-Clustering/assets/159046448/fecdf3f2-572e-46ff-83b1-779377bf6998)



