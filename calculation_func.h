#pragma once

#ifndef calculation_func
#define calculation_func
#ifdef __cplusplus
extern "C" {
#endif
int** calculate_distances(int** init_distance, int** drivers, int** customers_initp, int** customers_finalp, int num_of_customers, int  num_of_drivers, int time);
int** calculate_time_and_fee(int** input_mat, int** drivers, int** customers_initp, int** customers_finalp, int num_of_customers, int  num_of_drivers,int present_time);

#ifdef __cplusplus
}
#endif 

#endif // !calculation
