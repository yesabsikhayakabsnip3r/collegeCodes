#include<iostream>

// len, rev, concat, substr.
using namespace std;

const size_t width = 10, height = 10;


size_t len(char str[]){
	size_t c = 0;
	while(str[c] != '\0'){
		c++;
	}
	return c;
}

template <typename T>
void swap(T* d1, T* d2){
	char t;
	t = *d1;
	*d1 = *d2;
	*d2 = t;

	// Addition method doesn't work because buffer overflows. No negative numbers in char, this loops back.
	// cout << (int)*d1 << " " << (int)*d2 << endl; 
	// *d1 = *d1 + *d2; // 10, 5
	
	// cout << (int)*d1 << " " << (int)*d2 << endl; 
	// *d2 = *d1 - *d2; // 10, 5
	
	// cout << (int)*d1 << " " << (int)*d2 << endl; 
	// *d1 = *d1 - *d2; // 5, 5
	
	// cout << (int)*d1 << " " << (int)*d2 << endl << endl; 
}


void rev(char str[]){
	short int end = len(str) - 1;
	for(int i = 0; i < (end / 2)+1; i++){
		swap(&str[i], &str[end - i]); 
	}
}


void concat(char dest[], char src[]){
	size_t destLen = len(dest);
	int i = 0;
	while(src[i]!= '\0'){
		dest[destLen + i] = src[i];
		i++;
	}
}

char* substr(char str[], int l, int r){
	char* sub = new char[r - l];

	int c = 0;
	for(int i = l; i < r; i++){
		sub[c] =  str[i];
		c++;
	}
	return sub;
}

short int index(char str[], char c){
	for(int i = 0; i < len(str); i++){

		if(str[i] == c) return i;
	}
	return -1;
}

short int index(char str[], char c, int after){
	for(int i = after; i < len(str); i++){

		if(str[i] == c) return i;
	}
	return -1;
}

void print2DMat(char mat[width][width], size_t w, size_t h){
	cout << "┏";
	for(int y = 1; y <= w; y++) cout << "━";
	cout << "┓" << endl;
	for(int y = 0; y < h; y++){
		cout << "┃";
		for(int x = 0; x < w; x++){
			cout << mat[y][x];
		}
		cout << "┃" << endl;
	}
	cout << "┗";
	for(int y = 1; y <= w; y++) cout << "━";
	cout << "┛" << endl;
}

int main(){
	// char str[200];
	// char strOther[200] = " Jai Hind!\0";
	// cout << "Enter your string: ";
	// cin >> str;
	// rev(str);
	// cout << "Reversed      : " <<str << endl;

	// concat(str, strOther);
	// cout << "Appending     : " <<str << endl;
	// cout << "Substr 0 to 5 : " << substr(str, 0, 5) << endl;


	// Timepass hai iske niche
	char mat[height][width];
	for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			mat[y][x] = ' ';
		}
		cout << endl;
	}
	int playerPos[2] = {0, 0};

	while (1){
		print2DMat(mat, width, height);
		char c;
		cout << "Enter your direction === > ";
		cin >> c;
		mat[playerPos[1]][playerPos[0]] = ' ';
		switch(c){
			case 'w':
				playerPos[1] -= 1;
				break;
			case 's':
				playerPos[1] += 1;
				break;
			case 'a':
				playerPos[0] -= 1;
				break;
			case 'd':
				playerPos[0] += 1;
				break;
		}
		if(playerPos[0] >= width) playerPos[0] = 0;
		else if(playerPos[0] < 0) playerPos[0] = width - 1;


		if(playerPos[1] >= height) playerPos[1] = 0;
		if(playerPos[1] < 0) playerPos[1] = height - 1;

		mat[playerPos[1]][playerPos[0]] = '@';
	}



	return 0;
}