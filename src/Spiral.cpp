/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void tracePath(int * ans, int row, int col, int rows, int cols, int layer, int ** input_array, int pos, int way){
	if (way == -2){
		ans[pos++] = input_array[row][col];
		if (col != cols - layer - 1)
			tracePath(ans, row, col + 1, rows, cols, layer, input_array, pos, -2);
		else{
			if (row == rows - layer - 1)
				return;
			tracePath(ans, row + 1, col, rows, cols, layer, input_array, pos, -1);
		}
		return;
	}
	else if (way == -1){
		ans[pos++] = input_array[row][col];
		if (row != rows - layer - 1)
			tracePath(ans, row + 1, col, rows, cols, layer, input_array, pos, -1);
		else{
			if (col == layer)
				return;
			tracePath(ans, row, col - 1, rows, cols, layer, input_array, pos, 2);
		}
		return;
	}
	else if (way == 1){
		ans[pos++] = input_array[row][col];
		if (row != layer + 1)
			tracePath(ans, row - 1, col, rows, cols, layer, input_array, pos, 1);
		else{
			if (col == cols - layer - 1)
				return;
			tracePath(ans, row, col + 1, rows, cols, layer + 1, input_array, pos, -2);
		}
		return;
	}
	else{
		ans[pos++] = input_array[row][col];
		if (col != layer)
			tracePath(ans, row, col - 1, rows, cols, layer, input_array, pos, 2);
		else{
			if (row == layer)
				return;
			tracePath(ans, row - 1, col, rows, cols, layer, input_array, pos, 1);
		}
		return;
	}
}

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int * ans = (int *)malloc(sizeof(int)*rows*columns);
	tracePath(ans, 0, 0, rows, columns, 0, input_array, 0, -2);
	return ans;
}