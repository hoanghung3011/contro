#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	double sum=0;
	double tich=0;
	cout<<"nhap so phan tu: ";
	int n;
	cin>>n;
	double *p=new double[n];
	for (int i=0; i<n; i++){
		cin>>*(p+i);
	}
	for( int i=0; i<n; i++){
		if(p[i]<1){
			cout<<p[i]<<" ";
		}
		sum+=p[i];
		tich*=p[i];
	}
	cout<<"\ntong ="<<sum<<", tich= "<<tich;
	return 0;
}
