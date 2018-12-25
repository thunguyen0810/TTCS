#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct NgayThang
{
	int d;
	int m;
	int y;
} NgayThang;

//Ham nhap ngay thang nam 
void Nhap(string &s, NgayThang &ngay)
{
	cout << "Nhap ngay, thang, nam : ";
	getline(cin, s);
	cout << s << endl;
}

//Chuyen chuoi ngay thang nam thanh kieu so
void LayNgay(string &s, NgayThang &ngay)
{
	ngay.d = atoi((s.substr(0, 2)).c_str());
	cout << ngay.d << " ";
	ngay.m = atoi((s.substr(3, 2)).c_str());
	cout << ngay.m << " ";
	ngay.y = atoi((s.substr(6, 4)).c_str());
	cout << ngay.y << endl;
}

//Kiem tra nam nhuan
int KiemTra(int nam)
{
	if((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
		return 1;
	else 
		return 0;
}

//Tinh so thu tu cua ngay

int Thang[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int TinhSTT(NgayThang n)
{
	int stt = 0;
	for(int i = 0; i < n.m; i++)
	{
		stt += Thang[i];
		stt += n.d;
	}
	if(KiemTra && n.m > 2)
		stt + 1;
	return stt;
}

int STTNgayTrongNam(NgayThang n);

NgayThang NgayTuSTT(int stt, int nam)
{
	int t = 1;
	int ngay = stt;
	int kt = KiemTra(nam);
	while(stt > 0)
	{
		if(kt == 1 && t == 2)
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
	nt.d = ngay;
	nt.m = t;
	nt.y = nam;
	return nt;
}

NgayThang CongNgayThang(NgayThang n, int x)
{
	int kq = x + STTNgayTrongNam(n);
	int nam = n.y;
	if(kq <= 365)
		return NgayTuSTT(kq, n.y);
	else
		if(KiemTra(n.y) == 1)
			if(kq == 366)
				return NgayTuSTT(kq, n.y);
			else
				return NgayTuSTT(kq - 366, nam + 1);
		else
			return NgayTuSTT(kq - 365, nam + 1);
}

int main()
{
	NgayThang ngay;
	string s;
	Nhap(s, ngay);
	LayNgay(s, ngay);
	cout << "La ngay thu " << TinhSTT(ngay) << " trong nam";
	cout << NgayTuSTT(TinhSTT(ngay), );
	cout << CongNgayThang(s, ngay);
}
