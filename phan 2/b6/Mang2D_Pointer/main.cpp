#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void Menu() {
	cout << "\n----------------------------------------------------------";
	cout << "\n0: Exit";
	cout << "\n1: Input Array";
	cout << "\n2: Output Array";
	cout << "\n3: Find a Element in Array";
	cout << "\n4: Count Primes in Array";
	cout << "\n5: Check symmetric over main diagonal";
	cout << "\n6: Check symmetric over no main diagonal";
	cout << "\n71: Calculate the sum of value of row";
	cout << "\n72: Calculate the sum of half on main diagonal";
	cout << "\n8: Find value Max & Min of Array";
	cout << "\n9: Calculate the sum of 2 matrices";
	cout << "\n10: Calculate multily of 2 matrices";
	cout << "\n11: Check Unit Matrix ";
	cout << "\n12: Arrange the elements on each row in ascending order";
}
void input(int **&arr, int &d, int &c) {
	cout << "Enter number of row, col: \n";
	cin >> d >> c;
	arr = new int*[d];
	for (int i = 0; i < d; i++) {
		arr[i] = new int[c];
	}
	for (int i = 0; i < c; i++)
		srand((unsigned)time(NULL));
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] = rand() % 100;
}
void output(int **arr, int d, int c) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
int check(int **arr, int d, int c) {
	int f;
	cout << "input a number: ";
	cin >> f;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == f) {
				cout << "Element found at position: " << "a[" << i << "]" << "[" << j << "]"; return 1;
			}

		}

	}
	cout << "Element not found.";
}
bool checkPrime(int p) {
	for (int i = 2; i <= p / 2; i++) {
		if (p%i == 0) {
			return false;
		}
	} return true;
}
int countPrimes(int **arr, int d, int c) {
	int numPrime = 0;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			if (checkPrime(arr[i][j]) == true)
				numPrime++;
		}
	}
	return numPrime;
}
int DX1(int **arr, int d, int c) {
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] != arr[j][i])
			{
				cout << " Is not symmetric matrix"; return 0;
			}
	cout << " Is symmetric matric";
}
int DX2(int **arr, int d, int c) {
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] != arr[c - 1 - i][d - 1 - j])
			{
				cout << " Is not symmetric matrix"; return 0;
			}
	cout << " Is symmetric matric";
}
void Sum71(int **arr, int d, int c) {
	for (int i = 0; i < d; i++) {
		int s = 0;
		for (int j = 0; j < c; j++) {
			s += arr[i][j];
		}cout << "Sum row " << i << " is " << s << "\n";
	}
}
void Sum72(int **arr, int d, int c) {
	int s = 0;
	if (d != c) {
		cout << " - Error, please input a square matrix";
	}
	else {
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < c; j++) {
				if (j > i)
					s += arr[i][j];
			}
		}
		cout << "Sum half on naim diagonal is: " << s;
	}
}
void max(int **arr, int d, int c) {
	int max = arr[0][0], m = 0, n = 0;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] > max) {
				//swap(max,arr[i][j]);
				max = arr[i][j];
				n = i;
				m = j;
			}
		}
	}cout << "max= " << max;
}
void min(int **arr, int d, int c) {
	int min = arr[0][0], m = 0, n = 0;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
				n = i;
				m = j;
			}
		}
	}cout << "min= " << min;
}
void Sum2Arr(int **arr1, int **arr2, int **S, int d, int c) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			S[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
}
void Mult2Arr(int **arr1, int **arr2, int **S, int d, int c, int c2) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c2; j++) {
			S[i][j] = 0;
			for (int k = 0; k < c; k++)
				S[i][j] += arr1[i][k] * arr2[k][j];
		}
	}
}
int checkUnit(int **arr, int d, int c) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][i] != 1 || i != j & arr[i][j] != 0) {
				cout << " - Is not a Unit Matrix";
				return 0;
			}
		}
	}
	cout << " - Is a Unit Matrix";
	return 1;
}
void Arrange(int **arr, int d, int c) {
	for (int k = 0; k < d; k++) {
		for (int i = 0; i < c - 1; i++)
			for (int j = c - 1; j > i; j--)
				if (arr[k][j] < arr[k][j - 1])
				{
					int temp = arr[k][j];
					arr[k][j] = arr[k][j - 1];
					arr[k][j - 1] = temp;
				}
	}
}
int main() {
	int choice, **a, n, m, f, p;
	int **b, n2, m2, **c, n3, m3;
	while (1) {
		Menu();
		cout << "\nEnter your choice and press return: ";
		cin >> choice;
		switch (choice) {
		case 0: return -1;
		case 1: input(a, n, m);
			break;
		case 2: output(a, n, m);
			break;
		case 3: check(a, n, m);
			break;
		case 4: countPrimes(a, n, m);
			cout << "countPrimes= " << countPrimes(a, n, m);
			break;
		case 5: DX1(a, n, m);
			break;
		case 6: DX2(a, n, m);
			break;
		case 71:Sum71(a, n, m);
			break;
		case 72:Sum72(a, n, m);
			break;
		case 8:
			max(a, n, m);
			cout << "\n";
			min(a, n, m);
			break;
		case 9:
			input(a, n, m);
			cout << "output Array 1\n";
			output(a, n, m);
			input(b, n2, m2);
			cout << "output Array 2 \n";
			output(b, n2, m2);
			cout << "sum 2 Array:  \n";
			Sum2Arr(a, b, c, n, m);
			output(c, n, m);
			break;
		case 10:
			input(a, n, m);
			cout << "output Array 1\n";
			output(a, n, m);
			input(b, n2, m2);
			cout << "output Array 2 \n";
			output(b, n2, m2);
			cout << "Multiply 2 Array:  \n";
			Mult2Arr(a, b, c, n, m, m2);
			n3 = n;
			m3 = m2;
			output(c, n3, m3);
		case 11:
			checkUnit(a, n, m);
			break;
		case 12:
			cout << "Input 1 Array:\n";
			input(a, n, m);
			cout << "Output Array:\n";
			output(a, n, m);
			Arrange(a, n, m);
			cout << "Arrange array in ascending: \n";
			output(a, n, m);
			break;
		}

	}
	return 0;
}

