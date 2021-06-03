#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char** argv) {
	char str[20]= "hello class";
	char *p;
	p=str;
	int n=strlen(str);
	for (int i=0; i<n; i++){
		p[i]=toupper(*(p+i));
	}
	cout<<p;
	
	return 0;
}
