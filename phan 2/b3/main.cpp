#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv) {
	const int n=12;
	char **a;
	a=new char*[n];
	for (int i=0; i<n; i++){
		a[i]=new char[n];
	}
	for(int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			*(*(a+i)+j)='X';	
		}
	}
	for(int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
