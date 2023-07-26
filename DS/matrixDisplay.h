#include<iostream>
#define INT_UPPER 2147483647
#define INT_LOWER -2147483646
using namespace std;

int getMax(int* mat, size_t rows, size_t cols){
	int m = INT_LOWER;
	for(int i = 0; i < rows*cols; i++){
		if(*(mat + i) > m) m = *(mat + i);
	}
	return m;
}
int getMax(int* mat, size_t len){
	int m = INT_LOWER;
	for(int i = 0; i < len; i++){
		if(*(mat + i) > m) m = *(mat + i);
	}
	return m;
}
int getMin(int* mat, size_t len){
	int m = INT_UPPER;
	for(int i = 0; i < len; i++){
		if(*(mat + i) < m) m = *(mat + i);
	}
	return m;
}
int getMin(int* mat, size_t rows, size_t	 cols){
	int m = INT_UPPER;
	for(int i = 0; i < rows*cols; i++){
		if(*(mat + i) < m) m = *(mat + i);
	}
	return m;
}

int getCharLength(int num){
	if(num == 0) return 1;
	int len = 0;
	if(num < 0){
		len++;
		num *= -1;
	}
	while(num > 0){
		len++;
		num /= 10;
	}
	return len;	
}
int getLongestNumberLength(int* mat, int rows, int cols){
	int lowerLongest = getCharLength(getMin(mat, rows, cols));
	int upperLongest = getCharLength(getMax(mat, rows, cols));
	return (lowerLongest >= upperLongest)?lowerLongest:upperLongest;
}
string getSpacing(int len, string c){
	string spacing = "";
	for(int i = 0; i < 2+len;i++){	
		spacing += c;
	}
	return spacing;
}

void print2DMatrix(int* mat, size_t rows, size_t cols){
	int max = getMax(mat, rows, cols);
	string spacing = getSpacing(getLongestNumberLength(mat, rows, cols), "━");
	
	cout << " ┏";
	for(int i = 0; i < cols-1;i++){
		cout << spacing <<"┳";
	}
	cout<< spacing <<"┓"<< endl;
	for(int y = 0; y < rows; y++){
		for(int x = 0; x < cols;x++){
			cout << " ┃" << getSpacing(getLongestNumberLength(mat, rows, cols) - getCharLength(*(mat + y*cols + x)) -1, " ") << *(mat + y*cols + x);
		}
		cout << " ┃ " << endl;
		if(y != rows-1){
			cout << " ┣";
			for(int i = 0; i < cols-1; i++){
				cout << spacing <<"╋";
			}
			cout << spacing <<"┫" <<endl;
		}
	}

	cout << " ┗";
	for(int i = 0; i < cols-1;i++){
		cout << spacing <<"┻";
	}
	cout<< spacing <<"┛"<< endl;
}
void get2DMatrix(int* mat, size_t rows, size_t cols){
	for(int y = 0; y < rows; y++){
		cout << "Enter row " << y+1 << " elements : ";
		for(int x = 0; x < cols; x++){
			cin >> *(mat + y*cols + x);
		}
	}
}
