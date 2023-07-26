#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;
int main(){
	int len = 5;
	string chars = "13asti";
	ofstream pfile;
	pfile.open("PasswordsWithRepition.txt");

	for(int i0 = 0; i0 < chars.length(); i0++){
		for(int i1 = 0; i1 < chars.length(); i1++){
			for(int i2 = 0; i2 < chars.length(); i2++){
				for(int i3 = 0; i3 < chars.length(); i3++){
					for(int i4 = 0; i4 < chars.length(); i4++){
						pfile << chars[i0] <<  chars[i1] <<  chars[i2] <<  chars[i3] <<  chars[i4] << endl;
					}
				}		
			}
		}
	}

	ofstream pwrfile;
	pwrfile.open("PasswordsWithoutRepition.txt");
	
	for(int i0 = 0; i0 < chars.length(); i0++){
		for(int i1 = 0; i1 < chars.length(); i1++){
			for(int i2 = 0; i2 < chars.length(); i2++){
				for(int i3 = 0; i3 < chars.length(); i3++){
					for(int i4 = 0; i4 < chars.length(); i4++){
						if(i0 == i1 || i0 == i2 || i0 == i3 || i0 == i4 || 
						   i1 == i2 || i1 == i3 || i1 == i4 || 
						   i2 == i3 || i2 == i4 ||
						   i3 == i4)
							continue;
						pwrfile << chars[i0] <<  chars[i1] <<  chars[i2] <<  chars[i3] <<  chars[i4] << endl;

					}
				}
			}	
		}
	}

	cout << endl;

	for(int i = 0; i < 5; i++){
		for(int j =0 ; j < i; j++){
			cout << " * ";
		}
		cout << endl;
	}
	for(int i = 4; i >= 0; i--){
		for(int j = i ; j >= 0 ;j--){
			cout << " * ";
		}
		cout << endl;
	}
	
	for(int i = 0; i < 5; i++){
		for(int j =1 ; j < 5-i; j++){
			cout << "   ";
		}
		for(int j =0 ; j < i; j++){
			cout << " * ";
		}
		cout << endl;
	}

	int s = 20;
	int spacingIndex = s/2;
	for(int i = 1; i < s; i+= 2){
		
		for(int k = 0; k < spacingIndex; k++)
			cout << "   ";
		spacingIndex--;

		for(int j = 0; j < i; j++){
			cout << " * ";
		}
		cout << endl;
	}
	for(int i = s; i >= 0; i-= 2){
		
		for(int k = spacingIndex-1; k >= 0; k--)
			cout << "   ";
		spacingIndex++;

		for(int j = i; j >= 0; j--){
			cout << " * ";
		}
		cout << endl;
	}
	return 0;
}