#include <iostream>
#include<fstream>

using namespace std;
int main(){
	ofstream f;
	f.open("4digitATMPins.txt");
	// NEsted Approach
	for(int i0 = 0; i0 < 10; i0++){
		for(int i1 = 0; i1 < 10; i1++){
			for(int i2 = 0; i2 < 10; i2++){
				for(int i3 = 0; i3 < 10; i3++){
					f << (char)(i0 + '0') << (char)( i1 + '0') << (char)( i2 + '0') << (char)( i3 + '0') << endl;
				}		
			}
		}
	}


	return 0;
}