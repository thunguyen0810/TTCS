#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct
{
	string cauhoi;
	string A, B, C, D;
	string DA;
} CH_DA;

typedef struct
{
	string ten;
	int diem;
}Nguoi;

vector <CH_DA> dscau;
vector <Nguoi> danhsach;

int KiemTra(string A, string B)
{
	if(A.compare(B) == 0)
	{
		cout << "Dap an dung !" << endl;
		cout << "--------------------"<< endl;
		return 2;
	}
	else
	{
		cout << "Dap an sai !" << endl;
		cout << "--------------------"<< endl;
		return 0;
	}
}

//Kiem tra xem dap an
//A: dap an trong cau hoi
//B: dap an cua nguoi choi
//Ham nay tra ve 2 neu tra loi dung, neu tra loi sai thi tra ve 0
void LuuDiem(string ten, int diem)
{
	fstream f1;
	f1.open("luudiem.txt", ios::out | ios::app);
	f1 << ten << endl << diem ;
	f1.close();
}

//Lay cau hoi ra tu file
void LayDe()
{
	ifstream f("de.txt");
	int sl;
	int diem = 0;
	string s, ans, ten;
	CH_DA ch;
	getline(f,s); 
	sl = atoi(s.c_str());
	
	cout << "Nhap ten cua nguoi choi : " ;
	cin >> ten;
	getline(cin, ten);
	fflush(stdin);
	cout << "--------------------" << endl;
	
	for(int i = 0; i < sl; i++)
	{
		CH_DA qs;
		getline(f,s);
		qs.cauhoi = s;
		cout << qs.cauhoi << endl;
			
		getline(f, s);
		qs.A = s;
		cout << qs.A << endl;
		
		getline(f, s);
		qs.B = s;
		cout << qs.B << endl;
		
		
		getline(f, s);
		qs.C = s;
		cout << qs.C << endl;
		
		getline(f, s);
		qs.D = s;
		cout << qs.D << endl;
		
		getline(f, s);
		qs.DA = s;
		cout << "Nhap dap an : ";
		getline(cin, ans);
		if(KiemTra(qs.DA, ans) == 2)
			diem += 2;
		dscau.push_back(qs);
	}
	cout << "Diem cua ban la : " << diem << endl;
	fflush(stdin);
	LuuDiem(ten, diem);
}

void XemDiem()
{
	string s;
	ifstream f1("luudiem.txt");
	getline(f1, s);
	do
	{
		cout << s << endl;
		getline(f1, s); 
	}
	while (s.compare("") != 0);
	f1.close();
}

int main()
{
	LayDe();
//	XemDiem();
}
