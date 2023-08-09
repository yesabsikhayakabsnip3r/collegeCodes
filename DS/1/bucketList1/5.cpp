#include<iostream>


using namespace std;
int main(){
	int n = 9;
	for(int i = 0; i < n; i+=1){
		for(int left = n - i; left >=0 ; left--)
			cout << " ";
		for(int c = 0; c < i+1; c++)
			cout << (char)(c + 'A') << " ";
		cout << endl;
	}

	for(int i = n; i >= 0; i-=1){
		for(int left = n - i; left >=0 ; left--)
			cout << " ";
		for(int c = 0; c < i+1; c++)
			cout << (char)(c + 'A') << " ";
		cout << endl;
	}
}