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
	int** result = allocate(row, 3);
	
	//input test case
	printf_s("enter test case:\n");
	scan_mat(mat, row, col);
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
}