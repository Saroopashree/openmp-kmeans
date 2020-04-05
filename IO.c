#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

#include "IO.h"

void readDataset(const char *filename, int *N, float **data_points)
{
	FILE *fptr = fopen(filename, "r");

	fscanf(fptr, "%d", N);

	printf("No. of data points in the dataset: %d\n", *N);

	// Each data point is of 3 dimension
	*data_points = (float *)malloc(((*N) * 3) * sizeof(float));

	for (int i = 0; i < (*N) * 3; i++)
	{
		int temp;
		fscanf(fptr, "%d", &temp);
		*(*data_points + i) = temp;
	}

	fclose(fptr);
}

void writeClusters(const char *filename, int N, float *cluster_points)
{
	FILE *fptr = fopen(filename, "w");

	for (int i = 0; i < N; i++)
	{
		fprintf(fptr, "%f %f %f %f\n", *(cluster_points + (i * 4)), *(cluster_points + (i * 4) + 1), *(cluster_points + (i * 4) + 2), *(cluster_points + (i * 4) + 3));
	}

	fclose(fptr);
}

void writeCentroids(const char *filename, int K, int num_iterations, float *centroids)
{
	FILE *fptr = fopen(filename, "w");

	for (int i = 0; i < num_iterations; i++)
	{
		for (int j = 0; j < K; j++)
		{
			fprintf(fptr, "%f %f %f, ", *(centroids + (i * K) + (j * 3)), *(centroids + (i * K) + (j * 3) + 1), *(centroids + (i * K) + (j * 3) + 2));
		}
		fprintf(fptr, "\n");
	}

	fclose(fptr);
}