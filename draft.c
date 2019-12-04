#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"optimize.h"
#include"calculation_func.h"

////should test for nxn case

void main(int argc, char* argv[]) {
	printf_s("/*==========HELLO=========*/\n");
	char* map[11] = {
		"* ___ ___ ___ ___ ___ ___ ___ ___ ___ ",
		"9|___|___|___|___|___|___|___|___|___|",
		"8|___|___|___|___|___|___|___|___|___|",
		"7|___|___|___|___|___|___|___|___|___|",
		"6|___|___|___|___|___|___|___|___|___|",
		"5|___|___|___|___|___|___|___|___|___|",
		"4|___|___|___|___|___|___|___|___|___|",
		"3|___|___|___|___|___|___|___|___|___|",
		"2|___|___|___|___|___|___|___|___|___|",
		"1|___|___|___|___|___|___|___|___|___|",
		"00   1   2   3   4   5   6   7   8   9",
	};
	for (int i=0; i < 11; ++i) {
		printf_s("%s\n", map[i]);
	}
	int col, row;
	printf_s("\nenter number of drivers: \n");
	scanf_s("%d", &row);
	printf_s("enter number of customers: \n");
	scanf_s("%d", &col);
    int num_task = row <= col ? row : col;
//creat matrix of data
	int** mat = allocate(row,col);
	int** result = allocate(row, 3);
	int** result_2 = allocate(num_task, 5);
	int** drivers = allocate(row, 2);
	int** cus_initp = allocate(col, 2);
	int** cus_finalp = allocate(col, 2);

	//input test case
	printf_s("enter test case\n\drivers_position:\n");
	scan_mat(drivers, row, 2);
	printf_s("cus_init_position:\n");
	scan_mat(cus_initp, col, 2);
	printf_s("cus_final_position:\n");
	scan_mat(cus_finalp, col, 2);
	mat = calculate_distances(drivers, cus_initp, cus_finalp, col, row);
	//scan_mat(mat, row, col);
	//system("cls");
	print_mat(mat, row, col);
	//process
	result = hungarian_algo(mat, row, col);
	//print result
	printf_s("\n\nresult(output_matrix)):\n\
1st col for number of customer\n\
2nd col for number of drivers\n\
3rd col for respective distance");
	print_mat(result, row, 3);
	//
	result_2 = calculate_time_and_fee(result, drivers, cus_initp, cus_finalp, row, col);
	printf_s("\n\nresult(output_matrix2)):\n\
1st col for number of customer\n\
2nd col for number of drivers\n\
3rd col for estiamted time taken\n\
4th col for estimated time arriving final point\n\
5th col for the total money");
	print_mat(result_2, num_task, 5);
	//end game
	free_al(result_2, num_task, 5);
	free_al(cus_finalp, col, 2); free_al(drivers, row, 2); free_al(cus_initp, col, 2);
	free_al(mat,row,col);
	free_al(result, row,3);
	_getch();
}