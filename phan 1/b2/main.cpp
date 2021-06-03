#include <iostream>
using namespace std;
const int n = 10;

int main(int argc, char** argv) {
	int a[n];
	int *p=a;
	*(p+5)=100;
	cout<<"a[5]= "<<a[5];
	for (int i=0;i<n;i++){
		cin>>*(p+i);
	}
	for (int i=0; i<n; i++){
		cout<<p[i]<<" ";
	}
	return 0;
}
