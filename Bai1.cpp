#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct Contact
{
	char ten[20];
	bool gioitinh;
	char sdt[11],email[20],diachi[50];
} Contact;

vector<Contact> DB;
vector<Contact> db;

void GhiDBVaoFile()
{
	FILE *f = fopen("input.dat", "wb");
	for(int i = 0; i < db.size(); i++)
		fwrite(&DB[i], sizeof(Contact), 1, f);
	fclose(f);
}

void InDanhBa(Contact c)
{
	cout << "Ten : " << c.ten << endl;
	cout << "So dien thoai : " << c.sdt << endl;
	cout << "Gioi tinh : " << c.gioitinh << endl;
	cout << "Email : " << c.email << endl;
	cout << "Dia chi : " << c.diachi << endl;
}

void ThemMoi()
{
	char str1[] = "Vi du chuoi";
	Contact c;
	strcpy(c.ten, "Nguyen Phan Anh Thu");
	strcpy(c.sdt, str1);
	c.gioitinh = 0;
	strcpy(c.email, str1);
	strcpy(c.diachi, str1);
	DB.push_back(c);
	strcpy(c.ten, str1);
	strcpy(c.sdt, "0338718146");
	c.gioitinh = 1;
	strcpy(c.email, str1);
	strcpy(c.diachi, str1);
	DB.push_back(c);
	strcpy(c.ten, "Thu");
	strcpy(c.sdt, "0338148562");
	c.gioitinh = 1;
	strcpy(c.email, "thunguyen1918@gmail.com");
	strcpy(c.diachi, str1);
	DB.push_back(c);
}

void DocDBTuFile()
{
	FILE *f = fopen("input.dat", "rb");
	for(int i = 0; i < db.size(); i++)
	{
		Contact c;
		fread(&c, sizeof(c), 1, f);
		DB.push_back(c);
	}
	fclose(f);
}

void LietKe()
{
	for(int i = 0; i < db.size(); i++)
	{
		InDanhBa(DB[i]);
	}
}

void ChinhSua(char tt[])
{
	for(int i = 0; i < db.size(); i++)
		if(strcmp(DB[i].sdt, tt) == 0)
			strcpy(DB[i].ten, "Pham Duy Uyen Phuong");
}

void Xoa(char t[])
{
	for(int i = 0; i < db.size(); i++)
	{
		if(strcmp(DB[i].sdt, t) == 0)
			DB.erase(DB.begin() + i);
	}
}

Contact TimKiem(char t[])
{
	for(int i = 0; i < db.size(); i++)
	{
		if(strcmp(DB[i].sdt, t) == 0)
			return DB[i];
	}
}

int main()
{
	ThemMoi();
	GhiDBVaoFile();
	DocDBTuFile();
	ChinhSua("0338718144");
	cout << "Danh ba sau khi chinh sua : " << endl;
	for(int i = 0; i < db.size(); i++)
		InDanhBa(db[i]);
	Xoa("Nguyen Phan Anh Thu");
	cout << "Danh ba sau khi xoa : " << endl;
	for(int i = 0; i < db.size(); i++)
		InDanhBa(db[i]);
	Contact c = TimKiem("Thu");
	cout << "Contact muon tim la : " << endl;
		InDanhBa(c);
}

