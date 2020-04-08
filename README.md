# OpenMP-KMeans

An implemetation of the **K Means Clustering** ML Algorithm involving **multi threading**.

The algorithm is implemented in **C language** and uses the library **OpenMP** (omp.h).

### To compile the program

`gcc-6 IO.c omp_kmeans.c main.c -fopenmp -o kmeans`

### To execute the output file

`./kmeans <dataset_filename> <No. of clusters> <No. of threads> <output_filename for clustered data points> <output_filename for coordinates of the centroids>`

Example:

`./kmeans datasets/dataset_50000_4.txt 4 8 clust_dp.txt centroids.txt`
