#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//Khai bao cau truc cau hoi - dap an
typedef struct
{
	string cauhoi;
	string A, B, C, D;
	string DA;
} CH_DA;

//khai bao cau truc nguoi choi
typedef struct
{
	string ten;
	int diem;
}Nguoi;

vector <CH_DA> dscau;
vector <Nguoi> danhsach;

/* Kiem tra xem dap an
   A: dap an trong cau hoi
   B: dap an cua nguoi choi
   Ham nay tra ve true neu tra loi dung, neu tra loi sai thi tra ve false */
bool KiemTra(string A, string B)
{
	if(A.compare(B) == 0)
	{
		cout << "Dap an dung !" << endl;
		cout << "--------------------"<< endl;
		return true;
	}
	else
	{
		cout << "Dap an sai !" << endl;
		cout << "--------------------"<< endl;
		return false;
	}
}

/* Ham nay dung de luu diem cua nguoi choi
   ten : ten nguoi choi
   diem : diem nguoi choi */
void LuuDiem(string ten, int diem)
{
	fstream f1;
	//ios::out dung de mo mot file de ghi, ios::app la che do append (cong them) tuc la cac output toi file duoc them vao cuoi file
	f1.open("luudiem.txt", ios::out | ios::app); 
	f1 << ten << "\t" << diem << endl;
	f1.close();
}

/*Lay cau hoi ra tu file
  Ham nay yeu cau nhap ten nguoi choi, xuat ra cau hoi va yeu cau nguoi choi nhap cau tra loi
  Ham nay con xuat ra diem cua nguoi choi sau khi tra loi cac cau hoi va luu diem cua nguoi choi */
void LayDe()
{
	ifstream f("de.txt");
	int sl;
	int diem = 0;
	string s, ans, ten;
	CH_DA qs;
	getline(f,s);
	sl = atoi(s.c_str());//Chuyen chuoi s thanh so nguyen va gan no cho bien sl 
	
	cout << "Nhap ten cua nguoi choi : " ;
	getline(cin, ten);	//Dung getline de nhap chuoi ten
	fflush(stdin); //Xoa bo dem
	cout << "--------------------" << endl;
	
	for(int i = 0; i < sl; i++)
	{
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
		cout << "Nhap cau tra loi : ";
		getline(cin, ans);
		if(KiemTra(qs.DA, ans) == true)
			diem += 2;
		dscau.push_back(qs);
	}
	cout << "Diem cua ban la : " << diem << endl;
	fflush(stdin);
	LuuDiem(ten, diem); // Goi ham luu diem de luu diem cua nguoi choi
}

//Ham nay dung de xem diem cua nhung nguoi choi
void XemDiem()
{
	string s;
	ifstream f1("luudiem.txt");// Doc thong tin tu file luudiem.txt
	getline(f1, s);
	do
	{
		cout << s << endl;
		getline(f1, s); 
	}
	while (s.compare("") != 0);
	f1.close(); // Dong file sau khi thao tac
}

int main()
{
	LayDe();
	XemDiem();
}
