#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"optimize.h"
#include"calculation_func.h"


//should test for nxn case

void main(int argc, char* argv[]) {
	char* map[8] = {
		"0___1___2___3___4___5___6___7",
		"1___|___|___|___|___|___|___|",
		"2___|___|___|___|___|___|___|",
		"3___|___|___|___|___|___|___|",
		"4___|___|___|___|___|___|___|",
		"5___|___|___|___|___|___|___|",
		"6___|___|___|___|___|___|___|",
		"7___|___|___|___|___|___|___|",
	};
	for (int i=0; i < 8; ++i) {
		printf_s("%s\n", map[i]);
	}
	int col, row;
	printf_s("enter number of drivers: \n");
	scanf_s("%d", &row);
	printf_s("enter number of customers: \n");
	scanf_s("%d", &col);

//creat matrix of data
	int** mat = allocate(row,col);
	int** result = allocate(row, 3);
	int** drivers = allocate(row, 2);
	int** cus_initp = allocate(col, 2);
	int** cus_finalp = allocate(col, 2);

	//input test case
	printf_s("enter test case\n\drivers_position:\n");
	scan_mat(drivers, 3, 2);
	printf_s("cus_init_position:\n");
	scan_mat(cus_initp, 3, 2);
	printf_s("cus_final_position:\n");
	scan_mat(cus_finalp, 3, 2);
	mat = calculate_distances(drivers, cus_initp, cus_finalp, col, row);
	system("cls");
	print_mat(mat, row, col);
	//process
	result=hungarian_algo(mat, row, col);
	//print result
	printf_s("\n\nresult(output_matrix)):\n\
1st col for number of customer\n\
2nd col for number of drivers\n\
3rd col for respective distance");
	print_mat(result, row, 3);
	free_al(mat,row,col);
	free_al(result, row,3);
	_getch();


	

	_getch();
}