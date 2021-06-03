#include <iostream>
using namespace std;
void inputA(int *p,int n){
	for(int i=0; i<n; i++){
		p[i]=i;
	}
}
void chuyenAB(int *pA,int *pB, int n){
	for(int i=0; i<n; i++){
		pB[i]=pA[i];
		cout<<pB[i]<<" ";
	}
}
int main(int argc, char** argv) {
	cout<<"nhap so luong phan tu: ";
	int n;
	cin>>n;
	int *pA=new int[n];
	int *pB=new int[n];
	inputA(pA,n);
	chuyenAB(pA,pB,n);
	return 0;
}
