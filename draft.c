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
	int** result = allocate(2, col);
	
	//input test case
	printf_s("enter test case:\n");
	scan_mat(mat, row, col);
	system("cls");
	print_mat(mat, row, col);
	//process
	result=hungarian_algo(mat, row, col);
	//print result
	printf_s("\n\nresult(output_matrix)):\n1st row for number of customer\n2nd row for number of drivers");
	print_mat(result, 2, col);
	free_al(mat,row,col);
	free_al(result, 2, col);
	_getch();
}

////test make square
//void main() {
//	//col>row
//	int count = 0;
//	int r = 2;
//	int c = 3;
//	int t = r <= c ? c : r;
//	int** test = allocate(r, c);
//	print_mat(test, r, c);
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			test[i][j] = count++;
//		}
//	}
//	print_mat(test, r, c);
//	//realloc part
//	make_square(test, r, c);
//	print_mat(test, t, t);
//	
//	//row>col
//	//int count = 0;
//	//int r = 3;
//	//int c = 2;
//	//int t = r <= c ? c : r;
//	//int** test = allocate(r, c);
//	//print_mat(test, r, c);
//	//for (int i = 0; i < r; ++i) {
//	//	for (int j = 0; j < c; ++j) {
//	//		test[i][j] = count++;
//	//	}
//	//}
//	//print_mat(test, r, c);
//	////realloc part
//	//make_square(test, r, c);
//	//print_mat(test, t, t);
//
//	_getch();
//}