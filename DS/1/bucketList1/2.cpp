#include <iostream>
#include<fstream>

using namespace std;
int main(){
	int chars[26+26+10];
	ofstream f;
	f.open("6digitotpcodes.txt");

	for(int i = 0; i < 26; i++){
		chars[i] = 'A' + i; 
	}
	for(int i = 26; i < 52; i++){
		chars[i] = 'a' + i - 26; 
	}
	for(int i = 52; i < 62; i++){
		chars[i] = '0' + i - 52; 
	}
	for(int i = 0 ; i < 62 ;i++) cout << (char)chars[i];
	cout << endl;

	for(int i0 = 0; i0 < 62; i0++){
		for(int i1 = 0; i1 < 62; i1++){
			for(int i2 = 0; i2 < 62; i2++){
				for(int i3 = 0; i3 < 62; i3++){
					for(int i4 = 0; i4 < 62; i4++){
						for(int i5 = 0; i5 < 62; i5++){
							f << (char)chars[i0] <<  (char)chars[i1] <<  (char)chars[i2] <<  (char)chars[i3] <<  (char)chars[i4] << (char)chars[i5] << endl;
						}
					}
				}		
			}
		}
	}



	return 0;
}