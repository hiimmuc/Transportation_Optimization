//#include<stdio.h>
//#include<conio.h>
//#include"optimize.h"
//void main() {
//	int** mat, ** result;
//	int row, col, num_task;
//	printf_s("/*==========TEST==========*/\n enter num of row and col:\n"), scanf_s("%d%d", &row, &col);
//	mat = allocate(row, col);
//	result = allocate(row, col);
//	num_task = row <= col ? row : col;
//	scan_mat(mat, row, col);
//	result = hungarian_algo(mat, row, col);
//	printf_s("\nanswer:\n");
//	print_mat(result, row, 3);
//	free_al(mat, row, col);
//	free_al(result, row, col);
//	_getch();
//}