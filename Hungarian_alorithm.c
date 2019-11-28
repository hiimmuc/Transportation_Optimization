#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"optimize.h"
#define NoD 3
//allocate func
int** allocate(int number_of_row, int number_of_cols) {
	int** arr = (int**)malloc(number_of_row* sizeof(int*));
	for (int i = 0; i < number_of_row; ++i) {
		arr[i] = (int*)calloc(number_of_cols, sizeof(int));
	}
	if (arr == NULL)
	{
		printf_s("can not allocate memory...");
		exit(0);
	}
	return arr;
}
//free func
void free_al(int** arr,int number_of_rows,int number_of_cols) {
	for (int i = 1; i < number_of_rows; i++) {
		free(arr[i]);
	}
	free(arr);
}
//print
void print_mat(int** arr, int num_of_rows, int num_of_cols)
{
	printf_s("\n");
	for (int i = 0; i < num_of_rows; i++) {
		for (int j = 0; j < num_of_cols; j++) {
			printf("%-4d", arr[i][j]);
		}
		printf("\n");
	}
}
//scan
int** scan_mat(int** arr, int num_of_rows, int num_of_cols)
{
	for (int i = 0; i < num_of_rows; i++) {
		for (int j = 0; j < num_of_cols; j++) {
			printf_s("a[%d][%d]=", i + 1, j + 1);
			scanf_s("%d%*c", &arr[i][j]);
		}
		printf_s("\n");
	}
	return arr;
}
//copy mat
void copy_mat(int** arr1, int** arr2,int numofrows,int numofcols) {
	for (int i = 0; i < numofrows; ++i) {
		for (int j = 0; j < numofcols; ++j) {
			arr1[i][j] = arr2[i][j];
		}
	}
}
//find minimum element which is different from zero
int find_min(int *arr, int size) {
	int min=arr[0];
	for (int i = 0; i < size; ++i) {
		min = min < arr[i] ? min : arr[i];
	}

	return min;
}
//subtract func
int** subtract_mat_1(int** mat, int num_of_rows, int num_of_cols) {
	int min;
	int i, j, k = 0;
	int** col_arr = allocate(num_of_cols, num_of_rows);
	//subtract rows
	for (i = 0; i < num_of_rows; ++i) {
		min = find_min(mat[i], num_of_cols);
		for (j = 0; j < num_of_cols; ++j) {
			mat[i][j] =mat[i][j]-min;
		}
	}
	//subtract cols
	for (i = 0; i < num_of_rows; ++i) {
		for (j = 0; j < num_of_cols; ++j) {
			col_arr[j][i] = mat[i][j];
		}
	}
	for (i = 0; i < num_of_rows; ++i) {
		min = find_min(col_arr[i], num_of_cols);
		for (j = 0; j < num_of_cols; ++j) {
			if (mat[j][i]!=0) {
				mat[j][i] = mat[j][i] - min; 
			}
		}
	}
	
	free_al(col_arr,num_of_cols,num_of_rows);
	return mat;
} 
 //doin step1,2
/*=======================================================================================*/
 //do in step 4
int** subtract_mat_2(int** mat,int** masked_mat, int num_of_rows, int num_of_cols) {
	//1 find non_crossed element
	//2 sort in array
	//3 find min and  subtract array to min
	//4 add min to intesection of crossed line
	//5 copy to mat
	int** ans = allocate(num_of_rows, num_of_cols);
	int* temp = (int*)calloc(num_of_rows*num_of_cols, sizeof(int));
	int i, j, k=0;
	int min = 0, temp1 = 0;
//==============================================
	for (i = 0; i < num_of_rows;++i) {
		for (j = 0; j < num_of_cols; ++j) {
			//1,2
			if (masked_mat[i][j] == 0) {
				temp1=mat[i][j];
				temp[k] = temp1;
				++k;//number of non-zero element
			}
		}
	}
	printf_s("sorted arr: \n");
	for (i = 0; i < k; ++i) {
		printf_s("%d ", temp[i]);
	}
	min = find_min(temp, k);
	printf_s("\nmin value in array: %d \n", min);
	//3 subtract
	for (i = 0; i < num_of_rows; ++i) {
		for (j = 0; j < num_of_cols; ++j) {
			if (masked_mat[i][j] == 0) {
				mat[i][j] -= min;
			}
			if (masked_mat[i][j] == 2) {
				mat[i][j] += min;
			}
		}
	}
	//5
	copy_mat(ans, mat,num_of_rows,num_of_cols);
	return ans;
}
//step3
/*==================================================================*/
int count_crossed_line(int** mat, int num_of_rows, int num_of_cols) {
	int num=0;
	int i, j, k = 0;
	int* col_zero, * row_zero, * crossed_row, *crossed_col;
	col_zero = (int*)calloc(num_of_cols, sizeof(int));
	row_zero = (int*)calloc(num_of_rows, sizeof(int));
	crossed_row = (int*)calloc(num_of_rows, sizeof(int));
	crossed_col = (int*)calloc(num_of_cols, sizeof(int));
	int** crossed_mat = allocate(num_of_rows, num_of_cols);
	int**process_mat= allocate(num_of_rows, num_of_cols);
	copy_mat(process_mat, mat, num_of_rows, num_of_cols);
//count zero in row
	for (i = 0; i < num_of_rows; ++i) {
		for (j = 0; j < num_of_cols; ++j) {
			if (process_mat[i][j] == 0) {
				row_zero[i] += 1;
			}
		}
	}
	//draw line in row by assign -1 for all elements
	int temp1, temp2;
	temp1 = num_of_rows;
	temp2 = row_zero[0];
	for (i = 1; i < num_of_rows; ++i) {
		temp2 = temp2 < row_zero[i] ? temp2 : row_zero[i];
	}//find min number of row_zero
	while (temp1 > temp2) {
		for (i = 0; i < num_of_rows; ++i) {
			if (row_zero[i] == temp1) {
				for (j = 0; j < num_of_cols; ++j) {
					process_mat[i][j] = (-1);
					crossed_mat[i][j] += 1;
				}
			}
		}
		--temp1;
	}
//count zero in col
	for (i = 0; i < num_of_cols; ++i) {
		for (j = 0; j < num_of_rows; ++j) {
			if (process_mat[j][i] == 0) {
				col_zero[i] = col_zero[i] + 1;
			}
		}
	}
//draw line in col by assign -1 for all elements
	for (i = 0; i < num_of_cols; ++i) {
		if (col_zero[i]>0) {
			for (j = 0; j < num_of_rows; ++j) {
				process_mat[j][i] = -1;
				crossed_mat[j][i] = crossed_mat[j][i] + 1;
			}
		}
	}
//calculate number of line
	//for row
	for (i = 0; i < num_of_rows; ++i) {
		for (j = 0; j < num_of_cols; ++j) {
			if (process_mat[i][j] == -1) {
				crossed_row[i] += 1;
			}
		}
	}
	//for col
	for (i = 0; i < num_of_cols; ++i) {
		for (j = 0; j < num_of_rows; ++j) {
			if (process_mat[j][i] == -1) {
				crossed_col[i] += 1;
			}
		}
	}
	//sum up 2 type
	for (i = 0; i < num_of_rows; ++i) {
		if (crossed_row[i] == num_of_cols) {
			num += 1;
		}
	}
	if (num != num_of_cols) {
		for (i=0;i<num_of_cols;++i)
		{
			if (crossed_col[i] == num_of_rows) {
				num += 1;
			}
		}
	}
	printf_s("\ncrossed mat: \n");
	print_mat(process_mat, num_of_cols, num_of_rows);
	copy_mat(mat, crossed_mat,num_of_rows,num_of_cols);//copy crossed mat to temp
	return num;
}
/*==================================================================*/
int** assign_mat(int** assignable_mat, int num_of_rows, int num_of_cols) {
	/*make the assign point become -8(for team8) :D*/
	int** ans = allocate(num_of_rows, num_of_cols);
	int i, j, k;
	int count = 0, min_num = 0;
	int num_of_task = num_of_cols;
	int* count_row;
	count_row = (int*)calloc(num_of_rows, sizeof(int));
	copy_mat(ans, assignable_mat, num_of_rows, num_of_cols);
	//count zero in each row
	for (i = 0; i < num_of_rows; ++i) {
		for (j = 0; j < num_of_cols; ++j) {
			if (ans[i][j] == 0) {
				count_row[i] += 1;
			}
		}
	}
	min_num = find_min(count_row, num_of_cols);
	while (count != num_of_task) {
		for (i = 0; i < num_of_rows; ++i) {
			if (count_row[i] == min_num) {
				for (j = 0; j < num_of_cols; ++j) {
					if (ans[i][j] == 0) {
						
						++count;
						//draw -1 line through all num of elements in 2 line intersect in ans[i][j]
						for (k = 0; k < num_of_task; ++k) {
							ans[i][k] = -1;
							ans[k][j] = -1; 
						}
						ans[i][j] = -8;//assign the choosen zero by -8
						//reset the count_row array to zero to count again(after assign)
						for (int a = 0; a < num_of_rows; ++a) {
							count_row[a] = 0;
						}
						//count again
						for (int a = 0; a < num_of_rows; ++a) {
							for (int b = 0; b < num_of_cols; ++b) {
								if (ans[a][b] == 0) {
									count_row[a] += 1;
								}
							}
						}
					}
				}
				//set the covered row'value equal numofrow+1 in oder to make the other row can be the minimum
				for (int a = 0; a < num_of_rows; ++a) {
					if (count_row[a] == 0) { 
						count_row[i] = num_of_rows + 1; 
					}
				}
				//find min again
				min_num = find_min(count_row, num_of_rows);
			}
		}
	}
	return ans;
}
/*==================================================================*/
int** make_square(int**mat,int row,int col) {
	return NULL;//to make the mat become square
}
//nothing in make square
/*==================================================================*/
int** hungarian_algo(int** input_mat, int num_of_rows, int num_of_cols)
{
	int i, j, k = 0;
	int number_of_crossed_lines=0;
	int num_task = num_of_cols;
	int** temp= allocate(num_of_cols, num_of_cols);
	int** pre_ans = allocate(num_of_cols, num_of_cols);
	int** final_result= allocate(2 , num_of_cols);
	int** process_mat = allocate(num_of_rows, num_of_cols);
	/*input_mat = make_square(input_mat, num_of_rows, num_of_cols);*/
	//copy to process mat
	copy_mat(process_mat, input_mat, num_of_rows, num_of_cols);
	pre_ans = subtract_mat_1(process_mat, num_of_rows,num_of_cols);
	printf_s("\nreduced mat:\n");
	print_mat(pre_ans, num_of_rows, num_of_cols);
	 do {
		copy_mat(temp, process_mat, num_of_rows, num_of_cols);
		number_of_crossed_lines = count_crossed_line(temp, num_of_rows, num_of_cols);
		printf("masked mat:\n");
		print_mat(temp, num_of_rows, num_of_cols);
		printf_s("\nnumber of crossed line: %d\n", number_of_crossed_lines);
		if (number_of_crossed_lines != num_task) {
			process_mat = subtract_mat_2(process_mat, temp, num_of_rows, num_of_cols);
			print_mat(process_mat, num_of_rows, num_of_cols);
		}
	} while (number_of_crossed_lines != (num_task));
		copy_mat(pre_ans, process_mat, num_of_rows, num_of_cols);
	if (number_of_crossed_lines == (num_task)) {//plus 1 for nondiagonal case
		printf_s("we are done\n");
		//we can assign
		pre_ans = assign_mat(process_mat, num_of_rows, num_of_cols);
		printf_s("assigned mat:");
		print_mat(pre_ans, num_of_rows, num_of_cols);
		//convert to output mat(2xn)
		for (i = 0; i < num_of_rows; ++i) {
			for (j = 0; j < num_of_cols; ++j) {
				if (pre_ans[i][j] == -8) {
					printf_s("\ncustomer %d will be taken by driver %d", i + 1, j + 1);
					final_result[0][k] = i+1;
					final_result[1][k] = j+1;
					++k;
				}
			}
		}
	}
	return final_result;
}
