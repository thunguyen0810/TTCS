#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//Khai bao cau truc contact
typedef struct
{
	char ten[20];
	bool gioitinh;
	char sdt[11],email[20],diachi[50];
} Contact;

vector<Contact> DanhBa; //Vector DanhBa dung de them cac Contact vao
vector<Contact> DB; //Vector DB la lay ra tu file input.dat de kiem tra xem viec doc va ghi file dung hay khong

//Ham nay dung de ghi danh ba vao file nhi phan
void GhiDBVaoFile()
{
	FILE *f = fopen("input.dat", "wb"); //Mo file nhi phan input.dat
	for(int i = 0; i < DanhBa.size(); i++) 
	{
		fwrite(&DanhBa[i], sizeof(Contact), 1, f);// sizeof dung de tim kich co cua struct Contact
	}
	fclose(f);
}

//Ham nay dung de in thong tin cua tung contact
void InDanhBa(Contact c)
{
	cout << "Ten : " << c.ten << endl;
	cout << "So dien thoai : " << c.sdt << endl;
	cout << "Gioi tinh : " << c.gioitinh << endl;
	cout << "Email : " << c.email << endl;
	cout << "Dia chi : " << c.diachi << endl;
	cout << "-------------------------------//-------------------" << endl;
}

//Ham nay dung de them cac contact vao file nhi phan
//Ham nay in ra man hinh thong tin cua tung contact
void ThemMoi()
{
	Contact c;
	
	strcpy(c.ten, "Nguyen Phan Anh Thu"); //Dung strcpy de gan chuoi vao cac tham so cua struct Contact
	strcpy(c.sdt, "123");
	c.gioitinh = 0;
	strcpy(c.email, "abc");
	strcpy(c.diachi, "NT");
	DanhBa.push_back(c); //push_back dung de them cac tham so trong struct duoc gan boi bien Contact c vao cuoi vector DanhBa
	InDanhBa(c);
	
	strcpy(c.ten, "Tran Thi Ngoc Tram");
	strcpy(c.sdt, "456");
	c.gioitinh = 1;
	strcpy(c.email, "xyz");
	strcpy(c.diachi, "QN");
	DanhBa.push_back(c);
	InDanhBa(c);
	
	strcpy(c.ten, "Tu");
	strcpy(c.sdt, "789");
	c.gioitinh = 1;
	strcpy(c.email, "lmn");
	strcpy(c.diachi, "BA");
	DanhBa.push_back(c);
	InDanhBa(c);
}

//Ham nay dung de doc danh ba tu file nhi phan
void DocDBTuFile()
{
	FILE *f = fopen("input.dat", "rb"); //Mo file input.dat
	for(int i = 0; i < DanhBa.size(); i++) //DanhBa.size() = Kich co cua vector DanhBa
	{
		Contact c;
		fread(&c, sizeof(c), 1, f);
		DB.push_back(c);
	}
	fclose(f);
}

//Ham nay dung de liet ke cac contact, in ra toan bo danh ba
void LietKe()
{
	for(int i = 0; i < DB.size(); i++)
	{
		InDanhBa(DB[i]);
	}
}

//Ham chinh sua contact theo so dien thoai
void ChinhSua(char tt[])
{
	for(int i = 0; i < DanhBa.size(); i++)
		if(strcmp(DB[i].sdt, tt) == 0)
			strcpy(DB[i].ten, "Pham Duy Uyen Phuong");
		
}

//Ham xoa contact theo ten
void Xoa(char t[])
{
	for(int i = 0; i < DB.size(); i++)
	{
		if(strcmp(DB[i].ten, t) == 0)
			DB.erase(DB.begin() + i);
			//erase dung de xoa 1 phan chuoi trong vector DB
			//begin dung de bat dau tu phan tu dau tien trong vector DB 
	}
}

//Ham tim kiem contact theo ten
Contact TimKiem(char t[])
{
	for(int i = 0; i < DB.size(); i++)
		if(strcmp(DB[i].ten, t) == 0)
			return DB[i];
}

int main()
{
	ThemMoi();
	GhiDBVaoFile();
	DocDBTuFile();
	cout << "--------------------------------------------------" << endl;
	
	ChinhSua("123");
	cout << "Danh ba sau khi chinh sua : " << endl;
	for(int i = 0; i < DB.size(); i++)
	{
		InDanhBa(DB[i]);
	}
	cout << "--------------------------------------------------" << endl;
	
	Xoa("Tran Thi Ngoc Tram");
	cout << "Danh ba sau khi xoa : " << endl;
	for(int i = 0; i < DB.size(); i++)
	{
		InDanhBa(DB[i]);
	}
	cout << "--------------------------------------------------" << endl;
	
	Contact c = TimKiem("Tu");
	cout << "Contact sau khi tim kiem : " << endl;
	InDanhBa(c);
	cout << "--------------------------------------------------" << endl;
}

