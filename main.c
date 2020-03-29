#include <stdio.h>
#include <stdlib.h>

#include "IO.h"

int main(int argc, char const *argv[])
{
  // dataset_filename, number of clusters, number of threads, data points output filename, centroid coordinates output filename

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

  // First argument is the name of the executable file
  const char *dataset_filename = argv[1];
  const int K = atoi(argv[2]);
  const int num_threads = atoi(argv[3]);
  const char *data_points_output_filename = argv[4];
  const char *centroids_output_filename = argv[5];

  int N;               // Total no. of data_points in the file
  int *data_points;    // 2D array of 3 dimensional data points
  int *cluster_points; // 2D array of data points along with the ID of the cluster they belong to
  float *centroids;    // 2D array of the coordinates of the centroids of clusters

  readDataset(dataset_filename, &N, &data_points);

  for (int i = 0; i < N; i++)
  {
    printf("%d %d %d\n", *(data_points + (i * 3)), *(data_points + (i * 3) + 1), *(data_points + (i * 3) + 2));
  }

  // printf("Hello from main!\n");
  return 0;
}
