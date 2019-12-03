#include<stdio.h>
#include<math.h>;
#include"optimize.h"
#include"calculation_func.h"
#define vel 30
#define price 10000
int** calculate_distances(int** drivers, int** customers_initp, int** customers_finalp, int num_of_customers, int  num_of_drivers) {
	int** distances = allocate(num_of_drivers, num_of_customers);
	int distance = 0, distance_final = 0, distance_start = 0;
	for (int i = 0; i < num_of_drivers; i++)
		for (int j = 0; j < num_of_customers; j++)
		{
			//for (int k = 0; k < cols; k++)
			//	distances[i][j] = distances[i][j] + abs(drivers[i][k] - customers[j][k]);
			for (int k = 0; k < 2; ++k)
			{
				distance_start = distance_start + abs(drivers[i][k] - customers_initp[j][k]);
				distance_final = distance_final + abs(customers_initp[j][k] - customers_finalp[j][k]);//i fix some error here
				distance = distance_final + distance_start;
			}
			distances[i][j] = distance;
			distance = distance_final = distance_start = 0;
		};
	return distances;
}

int** calculate_time_and_fee(int** input_mat, int** drivers, int** customers_initp, int** customers_finalp,int number_of_drivers,int num_of_cus)
{
	int number_of_tasks = number_of_drivers <= num_of_cus ? num_of_cus : number_of_drivers;
	int distance_start = 0;
	int distance_final = 0;
	int** ans = allocate(number_of_tasks, 5);
	copy_mat(ans, input_mat, number_of_tasks, 2);
	//the 1st and 2nd for position for position
	for (int i = 0; i < number_of_tasks; ++i) {
		for (int a = 0; a < number_of_drivers; ++a) {
			for (int b = 0; b < num_of_cus; ++b) {
				if (ans[i][0] == a && ans[i][1] == b) {
					for (int c = 0; c < 2; ++c) {
						distance_start = distance_start + abs(drivers[a][c] - customers_initp[b][c]);
						distance_final = distance_final + abs(customers_initp[b][c] - customers_finalp[b][c]);
					}
					ans[i][2] = (int)((distance_start * 60) / vel);
					ans[i][3] = (int)((distance_final * 60) / vel);
					ans[i][4] = (int)(input_mat[i][2] * price);
					distance_final = 0;
					distance_start = 0;
				}
			}
		}
	}
	return ans;
}
