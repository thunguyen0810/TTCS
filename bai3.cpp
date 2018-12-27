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

int KiemTra(string A, string B);

//Xuat cau hoi
void Xuat(CH_DA ch)
{
	string s;
	cout << "Nhap ten nguoi choi : ";
	cin >> s;
	cout << "--------------------" << endl;
	
	string dapan;
	int diem;
	cout << ch.cauhoi << endl;
	cout << ch.A << endl;
	cout << ch.B << endl;
	cout << ch.C << endl;
	cout << ch.D << endl;
	cout << "Nhap dap an : ";
	cin >> dapan;
	if(KiemTra(ch.DA, dapan) == 2)
	{
		cout << "Dap an dung !" << endl;
		diem += KiemTra(ch.DA, dapan);
	}
	else
		cout << "Dap an sai !" << endl;
		cout << "-------//---------" << endl;
	dscau.push_back(ch);
}

void Xuat1()
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

//Doc cau hoi trong file
void DocDe()
{
	for(int i = 0; i < dscau.size(); i++)
		Xuat(dscau[i]);
}

//Lay cau hoi ra tu file
void LayDe()
{
	ifstream f("de.txt");
	int sl;
	string s, ans;
	CH_DA ch;
	getline(f,s);
	sl = atoi(s.c_str());
	for(int i = 0; i < sl; i++)
	{
		CH_DA qs;
		getline(f,s);
		qs.cauhoi = s;
			
		getline(f, s);
		qs.A = s;
		
		getline(f, s);
		qs.B = s;
		
		getline(f, s);
		qs.C = s;
		
		getline(f, s);
		qs.D = s;
		
		getline(f, s);
		qs.DA = s;

		dscau.push_back(qs);
	}
}

//Kiem tra xem dap an
//A: dap an trong cau hoi
//B: dap an cua nguoi choi
//Ham nay tra ve 2 neu tra loi dung, neu tra loi sai thi tra ve 0
int KiemTra(string A, string B)
{
	if(A.compare(B) == 0)
		return 2;
	else
		return 0;
}

void LuuDiem(string s, int diem)
{
	fstream f1;
	f1.open("luudiem.txt", ios::out | ios::app);
	f1 << s << endl << diem ;
	f1.close();
}

int main()
{
	string s;
	int diem;
	fflush(stdin);
	LayDe();
	DocDe();
	LuuDiem(s, diem);
}
