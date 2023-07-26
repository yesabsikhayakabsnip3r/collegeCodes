#include<iostream>
#include "../matrixDisplay.h"

using namespace std;


void displaySaddlePoint(int* mat, int rows, int cols){
	// *(mat + y*cols + x)
	// max col and min element = saddle point

	//Approach 1
	// Find col maxes
	// Find row mins
	// Display intersection
	int* columnMaxes = new int[cols];
	int* columnMaxesIndices = new int[cols];
	for(int x = 0; x < cols; x++){
		*(columnMaxes + x) = INT_LOWER;
		for(int y = 0; y < rows; y++){
			if (*(mat + y*cols+x) >= *(columnMaxes + x)){
				*(columnMaxes + x) = *(mat + y*cols+x);
				*(columnMaxesIndices + x) = y*cols+x;
			}
		}
	}

	int* rowMins = new int[rows];
	int* rowMinsIndices = new int[rows];
	for(int y = 0; y < rows; y++){
		*(rowMins + y) = INT_UPPER;
		for(int x = 0; x < cols; x++){
			if (*(mat + y*	cols+x) <= *(rowMins + y)){
				*(rowMins + y) = *(mat + y*cols+x);
				*(rowMinsIndices + y) = y*cols+x;
			}
		}
	}

	cout << "The row minimums are : " << endl;
	print2DMatrix(rowMins, 1, rows);
	cout << "The column maximums are : " << endl;
	print2DMatrix(columnMaxes, 1, cols);


	print2DMatrix(rowMinsIndices, 1, rows);
	print2DMatrix(columnMaxesIndices, 1, cols);


	int* saddlePoints = new int[rows*cols];
	int numberOfSaddlePoints = 0;

	for(int y = 0; y < rows; y++){
		for(int x = 0; x < cols; x++){
			if(*(rowMins + y) == *(columnMaxes + x)) {
				*(saddlePoints + numberOfSaddlePoints) = *(columnMaxesIndices + x);
				numberOfSaddlePoints++;
			}
		}
	}

	for(int i = 0; i < numberOfSaddlePoints; i++){
		cout << "The saddle points are : " << endl;
		int pos = *(saddlePoints + i);
		cout << "At index" <<  *(saddlePoints + i) << " " << *(mat + *(saddlePoints + i)) << endl;
	}


}


int main(){
	int cols, rows;

	cout << "Enter the number of columns and rows: "<< endl;
	cin >> cols;
	cin >> rows;

	int* mat = new int[rows * cols];
	get2DMatrix(mat, rows, cols);

	displaySaddlePoint(mat, rows, cols);

	return 0;
}