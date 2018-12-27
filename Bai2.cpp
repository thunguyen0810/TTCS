#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct NgayThang
{
	int ngay;
	int thang;
	int nam; 
} NgayThang;

//Ham nay dung de nhap ngay thang nam
//s : chuoi ngay thang nam
void Nhap(string &s)
{
	cout << "Nhap ngay thang nam : ";
	getline(cin, s); // Nhap chuoi ngay thang nam
	cout << s << endl;
}

//Ham nay dung de chuyen doi kieu chuoi cua ngay thang nam thanh kieu so
//s : chuoi ngay thang nam
//ngay : sau khi chuyen kieu chuoi cua ngay thang nam thanh so thi dung bien ngay de gan cho cac tham so cua struct
void LayNgay(string &s, NgayThang &ngay)
{
	ngay.ngay = atoi((s.substr(0, 2)).c_str()); // substr dung de tra ve chuoi con
	cout << ngay.ngay << " ";
	ngay.thang = atoi((s.substr(3, 2)).c_str()); // atoi dung de chuyen kieu chuoi ve kieu so
	cout << ngay.thang << " ";
	ngay.nam = atoi((s.substr(6, 4)).c_str());
	cout << ngay.nam << endl;
}

//Ham dung de kiem tra nam nhuan
//nam : nam can kiem tra
//Neu nam can kiem tra la nam nhuan thi tra ve 1 con nguoc lai khong phai nam nhuan thi tra ve 0
int KiemTra(int nam)
{
	if((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
		return 1;
	else
		return 0;
}

//Khai bao mang thang
int Thang[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Ham dung de tinh so thu tu cua ngay trong nam
//n : bien dung de gan cho cac tham so cua struct
//Ham nay tra ve so thu tu cua ngay trong nam
int TinhSTT(NgayThang n)
{
	int stt = 0;
	for(int i = 0; i < n.thang; i++)
		stt += Thang[i];
	stt += n.ngay;
	if(KiemTra(n.nam) && n.thang > 2)
		stt += 1;
	return stt;
}

//Ham dung de chuyen so thu tu cua ngay trong nam thanh kieu ngay thang nam
//stt : so thu tu cua ngay trong nam
//nam : bien nay dung de kiem tra xem nam co nhuan hay khong
//Ham nay tra ve kieu ngay thang nam
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

//Ham nay dung de cong mot so nguyen duong vao ngay
//n : bien dung de gan cho cac tham so cua struct
//x : so nguyen duong de cong vao ngay
//Ham nay tra ve kieu ngay thang nam
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
	Nhap(s);
	LayNgay(s, ngay); 
	cout << "Nhap so nguyen duong : ";
	cin >> x;
	if(KiemTra(ngay.nam) == 1)
		cout << "Nam " << ngay.nam << " la nam nhuan" << endl;
	else
		cout << "Nam " << ngay.nam << " khong la nam nhuan" << endl;
	cout << "La ngay thu " << TinhSTT(ngay) << " trong nam" << endl;
	NgayThang t = CongNgayThang(ngay, x);
	cout << "Ket qua sau khi cong ngay voi so nguyen duong la : ";
	cout << t.ngay << " " << t.thang << " " << t.nam << endl;
}
