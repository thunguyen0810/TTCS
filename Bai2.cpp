#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct NgayThang
{
	int ngay;
	int thang;
	int nam; 
} NgayThang;

//Ham nhap ngay thang nam
void Nhap(string &s, NgayThang &ngay)
{
	cout << "Nhap ngay thang nam : ";
	getline(cin, s);
	cout << s << endl;
}

//Chuyen doi kieu chuoi thanh kieu so
void LayNgay(string &s, NgayThang &ngay)
{
	ngay.ngay = atoi((s.substr(0, 2)).c_str());
	cout << ngay.ngay << " ";
	ngay.thang = atoi((s.substr(3, 2)).c_str());
	cout << ngay.thang << " ";
	ngay.nam = atoi((s.substr(6, 4)).c_str());
	cout << ngay.nam << endl;
}

//Kiem tra nam nhuan
int KiemTra(int nam)
{
	if((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
		return 1;
	else
		return 0;
}

//Tinh so thu tu cua ngay trong nam

int Thang[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int TinhSTT(NgayThang n)
{
	int stt = 0;
	for(int i = 0; i < n.thang; i++)
		stt += Thang[i];
	stt += n.ngay;
	if(KiemTra(n.nam) && n.thang > 2)
		stt + 1;
	return stt;
}

int main()
{
	NgayThang ngay;
	string s;
	Nhap(s, ngay);
	LayNgay(s, ngay);
	if(KiemTra(ngay.nam) == 1)
		cout << "Nam " << ngay.nam << " la nam nhuan" << endl;
	else
		cout << "Nam " << ngay.nam << " khong la nam nhuan" << endl;
	cout << "La ngay thu " << TinhSTT(ngay) << " trong nam" << endl;
}
