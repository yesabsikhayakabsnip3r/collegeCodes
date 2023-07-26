#include<iostream>
#include "matrixDisplay.h"
#define INT_UPPER 2147483647
#define INT_LOWER -2147483646
using namespace std;


bool isLowerTriangle(int* mat, int rows, int cols){
	for(int y = 0; y < rows-1; y++){
		for(int x = y+1; x < cols; x++){
			// All elements in the upper triangle should be 0;
			if (*(mat + y*cols + x) != 0)
				return false;
		}
	}
	return true;
}


bool isUpperTriangle(int* mat, int rows, int cols){
	for(int y = 1; y < rows; y++){
		for(int x = 0; x < y; x++){
			// All elements in the lower triangle should be 0;
			if (*(mat + y*cols + x) != 0)
				return false;
		}
	}
	return true;
}



int* addTwo2DMatrices(int* mat1, int* mat2, int rows, int cols){
	int* mat = new int[rows * cols];
	for(int y = 0; y < rows; y++){
		for(int x = 0; x < cols; x++){
			*(mat + y*cols + x) = *(mat1 + y*cols + x) + *(mat2 + y*cols + x);
		}
	}
	return mat;
}
int* subtractTwo2DMatrices(int* mat1, int* mat2, int rows, int cols){
	int* mat = new int[rows * cols];
	for(int y = 0; y < rows; y++){
		for(int x = 0; x < cols; x++){
			*(mat + y*cols + x) = *(mat1 + y*cols + x) - *(mat2 + y*cols + x);
		}
	}
	return mat;
}
int* multiplyTwo2DMatrices(int* mat1, int* mat2, int size){
	int rows = size;
	int cols = size;

	int* mat = new int[rows * cols];
	for(int y = 0; y < rows; y++){
		for(int x = 0; x < cols; x++){

			for(int i = 0; i < size; i++){
				*(mat + y*cols + x) += *(mat1 + y*cols + i) *  *(mat2 + i*cols + x);
				
				// newMat[y][x] += mat1[y][i] * mat2[i][x]

			}
		}
	}
	return mat;
}

void printStats(int* mat, int rows, int cols){
	cout << "Max = " << getMax(mat, rows, cols) << endl;
	cout << "Min = " << getMin(mat, rows, cols) << endl;

	if(isUpperTriangle(mat, rows, cols))
		cout << "The triangle is an upper triangle." << endl;
	else
		cout << "The triangle is NOT an upper triangle." << endl;

	if(isLowerTriangle(mat, rows, cols))
		cout << "The triangle is a lower triangle." << endl;
	else
		cout << "The triangle is NOT a lower triangle." << endl;

	cout << "Flattened : " << endl;
	print2DMatrix(mat, 1, cols*rows);

}

int main(){

	cout << "Enter the number of rows and columns : ";
	int rows, cols;
	cin >> rows >> cols;

	cout << "Matrix 1 :" << endl;
	int* mat1 = new int[rows*cols];
	cout << "Matrix 1 size : " << cols << "x" << rows << endl;
	get2DMatrix(mat1, rows, cols);
	print2DMatrix(mat1, rows, cols);
	printStats(mat1, rows, cols);

	cout << endl;

	cout << "Matrix 2 : " << endl;
	int* mat2 = new int[rows*cols];
	cout << "Matrix 2 size : " << cols << "x" << rows << endl;
	get2DMatrix(mat2, rows, cols);
	print2DMatrix(mat2, rows, cols);
	printStats(mat2, rows, cols);

	cout << endl;

	cout << "Matrix 1 + Matrix 2 : " << endl;
	print2DMatrix(addTwo2DMatrices(mat1, mat2, rows, cols), rows, cols);

	cout << endl;

	cout << "Matrix 1 - Matrix 2 : " << endl;
	print2DMatrix(subtractTwo2DMatrices(mat1, mat2, rows, cols), rows, cols);
	
	cout << endl;

	cout << "Matrix 1 x Matrix 2 : " << endl;
	print2DMatrix(multiplyTwo2DMatrices(mat1, mat2, rows), rows, cols);
	

	delete mat1;
	delete mat2;
	return 0;

}