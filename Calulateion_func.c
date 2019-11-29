#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<iostream>

int** initializearray(int rows, int  cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; ++i)
		arr[i] = new int[cols];
	return arr;
};

void fillexample(int** arr, int rows, int  cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = i;
};

void printarray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			std::cout << arr[i][j] << " ";
		std::cout << "\n";
	}
};

void freearray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
};

int** calculate(int** distances, int** drivers, int** customers, int rows, int  cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
				distances[i][j] = distances[i][j] + abs(drivers[i][k] - customers[j][k]);
		};
	return distances;
};

int main(int argc, char** argv)
{
	int rows = 3;
	int cols = 2;
	if (argc < 3)
	{
		std::cout << "Using default rows = 3 cols = 2" << "\n";

	}
	else
	{
		rows = strtol(argv[1], NULL, 10);
		cols = strtol(argv[2], NULL, 10);
		std::cout << "Using modified rows = "<< rows <<" cols = "<< cols << "\n";
	}

	int** drivers = initializearray(rows, cols);
	int** customers = initializearray(rows, cols);
	int** distances = initializearray(rows, rows);
	fillexample(drivers, rows, cols);
	fillexample(customers, rows, cols);
	printarray(drivers, rows, cols);
	printarray(customers, rows, cols);
	distances = calculate(distances, drivers, customers, rows, cols);
	printarray(distances, rows, rows);
	freearray(drivers, rows, cols);
	freearray(customers, rows, cols);
	freearray(distances, rows, cols);
	return 0;
};