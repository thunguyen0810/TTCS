#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

fstream f;

void DocFile(int a[10][10])
{
	int n;
	f.open("dothi.txt", ios::in);
	f >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			f >> a[i][j];
	f.close();
}

void XuatDoThi(int a[10][10])
{
	int n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
			cout << endl;
	}	
}

void TaoMoi(int A[10][10], int &n)
{
	cout << "Nhap n : ";
	cin >> n;
	f.open("dothi.txt", ios::out);
	f << n << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << "trong so tu " << i << " den " << j << " : ";
			cin >> A[i][j];
			f << A[i][j] << " ";
		}
		f << endl;
	}
	f.close();
}

int main()
{
	int A[10][10];
	int n;
	TaoMoi(A, n);
	DocFile(A);
	XuatDoThi(A);
}
