#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
using namespace std;

fstream f;

//Khai bao cau truc cua do thi
struct Cap
{
	int Dinh;
	int Tong;
};

vector <Cap> DS;

/*Ham nay dung de doc file txt
  a[10][10]: ma tran cua do thi */
void DocFile(int a[10][10])
{
	int n;
	f.open("dothi.txt", ios::in); //ios::in dung de mo file dothi.txt de doc
	f >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			f >> a[i][j];
	f.close();
}

/*Ham nay dung de xuat do thi ra man hinh
  a[10][10]: ma tran cua do thi */
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

/*Ham nay dung de tao moi do thi va luu vao file dothi.txt
  A[10][10]: ma tran cua do thi
  n : so dinh cua ma tran cua do thi */
void TaoMoi(int a[10][10], int &n)
{
	cout << "Nhap n : ";
	cin >> n;
	f.open("dothi.txt", ios::out); //ios::out dung de mo file dothi.txt de ghi
	f << n << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << "trong so tu " << i << " den " << j << " : ";
			cin >> a[i][j];
			f << a[i][j] << " ";
		}
		f << endl;
	}
	f.close();
}

int main()
{
	int A[10][10];
	int n;
	int Dau, Cuoi;
	TaoMoi(A, n);
	DocFile(A);
	XuatDoThi(A);
}
