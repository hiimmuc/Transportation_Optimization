#pragma once
#ifndef optimize
#define optimize

int** hungarian_algo(int** input_mat, int num_of_rows, int num_of_cols);
int** allocate(int number_of_row, int number_of_cols);
void free_al(int** arr, int number_of_rows,int number_of_cols);
void print_mat(int** arr, int num_of_rows, int num_of_cols);
int** scan_mat(int** arr, int num_of_rows, int num_of_cols);
int** make_square(int** mat, int row, int col);//for test
#endif // !optimize.h
