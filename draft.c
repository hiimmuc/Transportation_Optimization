#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include "optimize.h"
#include "InOutFiles.h"
#include "calculation_func.h"

////should test for nxn case

typedef struct time {
	int hours;
	int minus;
} time;
void main(int argc, char* argv[]) {
	printf_s("/*==========HELLO=========*/\n");
//total part

	int num_of_cus = count("customer.txt");//count customers
	int num_of_drv = count("driver.txt");//count drivers

	customer* c = (customer*)calloc(num_of_cus, sizeof(customer));
	// allocate memory for number of customers counted above
	driver* d = (driver*)calloc(num_of_drv, sizeof(driver));
	//same as above
	constructC(num_of_cus, c);
	constructD(num_of_drv, d);
	int** cusCipMat = allocate(num_of_cus, 2);//allocate memory for cip mattrix
	getCusCip(cusCipMat, c, num_of_cus);//get values for cip mattrix

	int** CusCfpMat = allocate(num_of_cus, 2);//same
	getCusCfp(CusCfpMat, c, num_of_cus);//same

	int** DrvDpMat = allocate(num_of_drv, 2);//same
	getDrvDp(DrvDpMat, d, num_of_drv);//same
	
	int col, row;
	row = num_of_drv;
	col = num_of_cus;
    int num_task = row <= col ? row : col;
//creat matrix of data
	int** mat = allocate(row,col);
	int** result = allocate(row, 3);
	int** result_2 = allocate(num_task, 5);
	int** drivers = allocate(row, 2);
	int** cus_initp = allocate(col, 2);
	int** cus_finalp = allocate(col, 2);
	int** present_distance = allocate(row, 1);
	char ans;
	time t;
	t.hours = 7;
	t.minus = 0;
	//printf_s("driver poistion:\n"); scan_mat(drivers, row, 2);
	copy_mat(drivers, DrvDpMat, num_of_drv, 2);
	copy_mat(cus_initp, cusCipMat, num_of_cus, 2);
	copy_mat(cus_finalp, CusCfpMat, num_of_cus, 2);
	do {
		//system("cls");
		//printf map
		//printf_s("\n/*======================MAP======================*/\n\n");
		//print_map(drivers, cus_initp, row, col);
		////pr0cess
		mat = calculate_distances(present_distance, drivers, cus_initp, cus_finalp, col, row, t.minus);
		//print_mat(mat, row, col);
		//process
		result = hungarian_algo(mat, row, col);
		copy_mat(present_distance, result, row, 2);//copy the distance of each drivers
		//print_mat(result, row, 3);
		result_2 = calculate_time_and_fee(present_distance, drivers, cus_initp, cus_finalp, row, col,t.minus);
		/*printf_s("\n\nresult(output_matrix2)):\n\
1st col for number of customer\n\
2nd col for number of drivers\n\
3rd col for estiamted time taken\n\
4th col for estimated time arriving final point\n\
5th col for the total money");
		print_mat(result_2, num_task, 5);*/ //may  be remove to make it more clearly

		//billForCus* Bills = (billForCus*)malloc(col* sizeof(billForCus));
		//constructBill(col, Bills, result_2, c, d);
		//printBill(col, Bills);

		printf_s("Done!!!\n");
	//test realtime part

		printf_s("\nTIME: %d h %d m\n", t.hours, t.minus);
		for (int i = 0; i < num_task; ++i) {
			printf_s("\n>Customer no.[%d] will be taken by driver no.[%d] in %d minutes\n>Arrive the choosen point in: %d minutes\n>please prepare %d,000 VND\n/=======>", result_2[i][0] + 1, result_2[i][1] + 1, result_2[i][2], result_2[i][3], result_2[i][4]);
		}
		printf_s("\n\nco' co\\n kha'ch (y/n)? :  ");
		scanf_s("%c",&ans);
		if (ans == 'y') {
			copy_mat(drivers, cus_finalp, row, 2);
			printf_s("\ncustomer infor: ");
			printf_s("\nenter initial positon of customer: \n"); scan_mat(cus_initp, col, 2);
			printf_s("\nenter final positon of customer: \n"); scan_mat(cus_finalp, col, 2);
		}
		t.minus += 2;
		if (t.minus == 60) {
			t.hours += 1;
			t.minus = 0;
		}
	} while (ans == 'y');
	//end game
	free_al(result_2, num_task, 5);
	free_al(cus_finalp, col, 2); free_al(drivers, row, 2); free_al(cus_initp, col, 2);
	free_al(mat,row,col);
	free_al(result, row,3);
	_getch();
}
