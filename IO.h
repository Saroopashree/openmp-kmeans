#ifndef IO_H
#define IO_H

// Read data from the dataset (.txt file)
void readDataset(const char *filename, int *N, int **data_points);

// Write the data points along with their cluster ID to a new file (.txt file)
void writeClusters(const char *filename, int N, int *cluster_points);

// Write the coordinates of the K clusters in a new file (.txt file)
void writeCentroids(const char *filename, int K, int num_iterations, float *centroids);

#endif