#include<stdio.h>
#include<math.h>;
#include"optimize.h"
#include"calculation_func.h"

int** calculate_distances(int** drivers, int** customers_initp, int** customers_finalp, int num_of_customers, int  num_of_drivers) {
	int** distances = allocate(num_of_drivers, num_of_customers);
	int distance = 0, distance_final = 0, distance_start = 0;
	for (int i = 0; i < num_of_drivers; i++)
		for (int j = 0; j < num_of_drivers; j++)
		{
			//for (int k = 0; k < cols; k++)
			//	distances[i][j] = distances[i][j] + abs(drivers[i][k] - customers[j][k]);
			for (int k = 0; k < num_of_customers; k++)
			{
				distance_start = distance_start + abs(drivers[i][k] - customers_initp[j][k]);
				distance_final = distance_final + abs(customers_initp[i][k] - customers_finalp[j][k]);
				distance = distance_final + distance_start;
			}
			distances[i][j] = distance;
			distance = distance_final = distance_start = 0;
		};
	return distances;
}

int** calculate_time_and_fee(int** input_mat, int number_of_tasks)
{
	int** ans=allocate(number_of_tasks,4);

	return ans;
}
