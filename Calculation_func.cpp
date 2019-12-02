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

void calculate(int** distances, int** drivers, int** customers, int** customers_final, int rows, int  cols)
{
	int distance = 0, distance_final = 0, distance_start = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < rows; j++)
		{
			//for (int k = 0; k < cols; k++)
			//	distances[i][j] = distances[i][j] + abs(drivers[i][k] - customers[j][k]);
			for (int k = 0; k < cols; k++)
			{
				distance_start = distance_start + abs(drivers[i][k] - customers[j][k]);
				distance_final = distance_final + abs(customers[i][k] - customers_final[j][k]);
				distance = distance_final + distance_start;
			}
			distances[i][j] = distance;
			distance = distance_final = distance_start = 0;
		};
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
	int** customers_final = initializearray(rows, cols);

	fillexample(drivers, rows, cols);
	fillexample(customers, rows, cols);
	fillexample(customers_final, rows, cols);
	std::cout << "Driver 's coordinates:" << "\n";
	printarray(drivers, rows, cols);
	std::cout << "Customer 's start coordinates:" << "\n";
	printarray(customers, rows, cols);
	std::cout << "Customer 's final coordinates:" << "\n";
	printarray(customers_final, rows, cols);

	calculate(distances, drivers, customers, customers_final, rows, cols);

	std::cout << "Distances (Driver x Customer):" << "\n";
	printarray(distances, rows, rows);

	freearray(drivers, rows, cols);
	freearray(customers, rows, cols);
	freearray(distances, rows, cols);
	return 0;
};
