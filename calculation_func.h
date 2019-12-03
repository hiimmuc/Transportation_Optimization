#pragma once
/*nhom nguyen tuan trung*/

#ifndef calculation_func
#define calculation_func

int** calculate_distances(int** drivers, int** customers_initp, int** customers_finalp, int num_of_customers, int  num_of_drivers);
int** calculate_time_and_fee(int** input_mat, int** drivers, int** customers_initp, int** customers_finalp, int num_of_customers, int  num_of_drivers);

#endif // !calculation
