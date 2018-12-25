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

NgayThang NgayTuSTT(int stt, int nam)
{
	int t = 1;
	int ngay = stt;
	int kt = KiemTra(nam);
	while(stt > 0)
	{
		if((kt == 1) && (t == 2))
			stt = stt - 29;
		else
			stt = stt - Thang[t];
		if(stt > 0)
		{
			ngay = stt;
			t++;
		}
	}
	NgayThang nt;
	nt.ngay = ngay;
	nt.thang = t;
	nt.nam = nam;
	return nt;
}

NgayThang CongNgayThang(NgayThang n, int x)
{
	int kq = x + TinhSTT(n);
	int nam = n.nam;
	if(kq <= 365)
		return NgayTuSTT(kq, nam);
	else
		if(KiemTra(n.nam) == 1)
			if(kq == 366)
				return NgayTuSTT(kq, nam);
			else
				return NgayTuSTT(kq - 366, nam + 1);
		else
			return NgayTuSTT(kq - 365, nam + 1);
}

int main()
{
	NgayThang ngay;
	string s;
	int x;
	Nhap(s, ngay);
	LayNgay(s, ngay);
	if(KiemTra(ngay.nam) == 1)
		cout << "Nam " << ngay.nam << " la nam nhuan" << endl;
	else
		cout << "Nam " << ngay.nam << " khong la nam nhuan" << endl;
	cout << "La ngay thu " << TinhSTT(ngay) << " trong nam" << endl;
	CongNgayThang(ngay, x);
}
