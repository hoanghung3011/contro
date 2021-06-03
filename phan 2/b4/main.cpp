#include <iostream>
using namespace std;
const int n = 10;
int main(int argc, char** argv) {
	float *p= new float[n];
	for (int i=0; i<n; i++){
		cin>>*(p+i);
	}
	for (int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if (p[i]>p[j]){
				int t=p[i];
				p[i]=p[j];
				p[j]=t;
				}
		}
	}
	for (int i=0; i<n; i++){
		cout<<*(p+i)<<" ";
	}
	return 0;
}
