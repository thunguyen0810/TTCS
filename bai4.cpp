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

int main()
{
	int A[10][10];
	DocFile(A);
	XuatDoThi(A);
}
