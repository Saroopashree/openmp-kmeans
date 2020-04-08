#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "IO.h"
#include "omp_kmeans.h"

int main(int argc, char const *argv[])
{
	/* Correct structure of command line arguments
			- ./a.out
	 		- dataset filename, 
			- number of clusters,
			- number of threads,
			- filename to write the clustered data points,
			- filename to write the coordinated of the centroid
	 */

	if (argc < 6)
	{
		printf("Less no. of command line arguments\n\n");
		return 0;
	}
	else if (argc > 6)
	{
		printf("Too many command line arguments\n\n");
		return 0;
	}

	// Correct no. of command line arguments

	const char *dataset_filename = argv[1];
	const int K = atoi(argv[2]);
	const int num_threads = atoi(argv[3]);
	const char *data_points_output_filename = argv[4];
	const char *centroids_output_filename = argv[5];

	int N;								 // Total no. of data_points in the file
	float *data_points;		 // 2D array of 3 dimensional data points
	float *cluster_points; // 2D array of data points along with the ID of the cluster they belong to
	float *centroids;			 // 2D array of the coordinates of the centroids of clusters
	int num_iterations = 0;

	readDataset(dataset_filename, &N, &data_points);

	double start_time = omp_get_wtime();
	printf("start time: %lf\n", start_time);
	kmeansClusteringOmp(N, K, num_threads, data_points, &cluster_points, &centroids, &num_iterations);
	double end_time = omp_get_wtime();

	printf("Time Taken: %lfs\n", end_time - start_time);

	writeClusters(data_points_output_filename, N, cluster_points);
	writeCentroids(centroids_output_filename, K, num_iterations, centroids);

	return 0;
}
