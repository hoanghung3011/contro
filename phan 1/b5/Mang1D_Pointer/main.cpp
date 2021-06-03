#include <iostream>
using namespace std;
void Menu() {
	cout << "\n----------------------------------------------------------";
	cout << "\n0: thoat";
	cout << "\n1: Nhap mang";
	cout << "\n2: Xuat mang";
	cout << "\n3: xuat cac so nguyen to trong mang";
	cout << "\n4: kiem tra mang doi xung";
	cout << "\n5: xoa 1 phan tu trong mang";
	cout << "\n6: tim vi tri phan tu lon nhat trong mang";
	cout << "\n7: tim vi tri phan tu co gia tri am lon nhat";
}
void input(int *&a, int &n) {
	cout << "nhap so phan tu mang: ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "]= ";
		cin >> a[i];
	}
}
void output(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void max(int *a, int n) {
	int max = a[0], m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			m = i;
		}
	}
	cout << "max= " << max;
	cout << "\nvi tri la: " << "a[" << m << "]";
}
bool checkPrime(int p) {
	if (p < 2) return false;
	for (int i = 2; i <= p / 2; i++) {
		if (p%i == 0) {
			return false;
		}
	} return true;
}
void coutPrimes(int *a, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (checkPrime(a[i]) == true) {
			cout << a[i] << "\t";
		}
	}
}
void checkSym(int *a, int n) {
	for (int i = 0; i < n / 2; i++) {
		if (a[i] = a[n - i - 1]) {
			cout << "mang doi xung "; break;
		}
		else cout << "mang khong doi xung"; break;

	}
}
void amMax(int *a, int n)
{
	int ammax = a[0];
	int vtam = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0 and a[i] > ammax)
		{
			ammax = a[i];
			vtam = i;
		}
		else continue;
	}
	cout << "vi tri am lon nhat a[" << vtam << "]";
}
int Delete(int *&a, int n) {
	int k;
	cout << "nhap vi tri k can xoa: ";
	cin >> k;
	if (k > 0 && k < n) {
		for (int i = k; i < n - 1; i++) {
			a[i] = a[i + 1];
		}
		n--;
		output(a, n);
		return 1;
	}
	else
	{
		cout << "Khong tim thay vi tri k ";
		return 0;
	}
}
int main() {
	int choice, n;
	int *a;

	while (1) {
		Menu();
		cout << "\nNhap tuy chon voi so tuong ung: ";
		cin >> choice;
		switch (choice) {
		case 0: return -1;
		case 1: input(a, n);
			break;
		case 2: output(a, n);
			break;
		case 3:
			coutPrimes(a, n);
			break;
		case 4:
			checkSym(a, n);
			break;
		case 5:
			Delete(a, n);
			break;
		case 6:
			max(a, n);
			break;
		case 7:
			amMax(a, n);
			break;
			return 0;
		}
	}
}
