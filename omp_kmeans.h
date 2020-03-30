#ifndef OMP_KMEANS
#define OMP_KMEANS

double findEuclideanDistance(float *pointA, float *pointB);

void threadedClustering(int tID, int N, int K, int num_threads, float *data_points, float **cluster_points, float **centroids, int *num_iterations);

void kmeansClusteringOmp(int N, int K, int num_threads, float *data_points, float **cluster_points, float **centroids, int *num_iterations);

#endif