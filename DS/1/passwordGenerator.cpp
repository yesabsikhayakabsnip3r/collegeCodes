#include<iostream>
#include<string.h>

using namespace std;
int main(){
	int len = 3;
	string chars = "abc";
	bool repeatCharacters = 0;
	string newP = "";
	for(int i = 0; i < chars.length(); i++){
		for(int j = 0; j < len; j++){
			newP[j] = chars[i];
		}
		cout << newP;
		newP = "";
	}
	cout << endl;
	return 0;
}