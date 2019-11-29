#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"optimize.h"

//should test for nxn case
void main(int argc, char* argv[]) {
	int col, row;
	printf_s("enter size (row,col): \n");
	scanf_s("%d%d", &row, &col);
	
	//creat matrix of data
	int** mat = allocate(row,col);
	int** result= allocate(row ,col);
	
	//input test case
	printf_s("enter test case:\n");
	scan_mat(mat, row, col);
	system("cls");
	print_mat(mat, row, col);
	//process
	result=hungarian_algo(mat, row, col);
	//print result
	printf("\nresult(output_matrix)):\n1st row for number of customer\nsecond row for number of drivers");
	print_mat(result, 2, col);
	free_al(mat,row,col);
	free_al(result,2,col);
	//free(mat);
	_getch();

}