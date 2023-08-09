#include <iostream>
#include<fstream>
#include<string>

using namespace std;
int main(){
	ofstream f;
	f.open("N_Range_and_k_length_passwords.txt");

	int n = 20, k = 5;

	string* passCharacters = new string[k];
	for(int i = 0; i < k; i++)
		*(passCharacters + i) = '1';

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			*(passCharacters + j) = to_string(i);
			for(int passIndex = 0; passIndex < k; passIndex++)
				f << *(passCharacters + passIndex) + " ";
			f << endl;
		}
	}

	return 0;
}