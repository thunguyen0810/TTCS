#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct
{
	char ten[20];
	bool gioitinh;
	char sdt[11],email[20],diachi[50];
} Contact;

vector<Contact> DB;

void ThemMoi()
{
	Contact c;
	
	strcpy(c.ten, "Nguyen Phan Anh Thu");
	strcpy(c.sdt, "123");
	c.gioitinh = 0;
	strcpy(c.email, "abc");
	strcpy(c.diachi, "NT");
	DB.push_back(c);
	
	
	strcpy(c.ten, "Tran Thi Ngoc Tram");
	strcpy(c.sdt, "456");
	c.gioitinh = 1;
	strcpy(c.email, "xyz");
	strcpy(c.diachi, "QN");
	DB.push_back(c);
	
	strcpy(c.ten, "Tu");
	strcpy(c.sdt, "789");
	c.gioitinh = 1;
	strcpy(c.email, "lmn");
	strcpy(c.diachi, "BA");
	DB.push_back(c);
}

void GhiDBVaoFile()
{
	FILE *f = fopen("input.dat", "wb");
	Contact db;
	for(int i = 0; i < DB.size(); i++) {
		db = DB[i];
		fwrite(&db, sizeof(Contact), 1, f);
	}
	fclose(f);
}

void DocDBTuFile()
{
	FILE *f = fopen("input.dat", "rb");
	if(f != NULL)
		while(!feof(f))
		{
			Contact c;
			fread(&c, sizeof(Contact), 1, f);
			DB.push_back(c);
		}
	fclose(f);
}

void InDanhBa(Contact c)
{
	cout << "Ten : " << c.ten << endl;
	cout << "So dien thoai : " << c.sdt << endl;
	cout << "Gioi tinh : " << c.gioitinh << endl;
	cout << "Email : " << c.email << endl;
	cout << "Dia chi : " << c.diachi << endl;
	cout << "-------------------------------//-------------------" << endl;
}

void LietKe()
{
	for(int i = 0; i < DB.size(); i++)
	{
		InDanhBa(DB[i]);
	}
}

//void ChinhSua(char tt[])
//{
//	for(int i = 0; i < DB.size(); i++)
//	{
//		Contact c;
//		c = DB[i];
//		if(strcmp(c.sdt, tt) == 0)
//			strcpy(c.ten, "Pham Duy Uyen Phuong");
//	}
//		
//}
//
//void Xoa(char t[])
//{
//	for(int i = 0; i < DB.size(); i++)
//	{
//		if(strcmp(DB[i].sdt, t) == 0)
//			DB.erase(DB.begin() + i);
//	}
//}
//
//Contact TimKiem(char t[])
//{
//	for(int i = 0; i < DB.size(); i++)
//	{
//		if(strcmp(DB[i].sdt, t) == 0)
//			return DB[i];
//	}
//}

int main()
{
	ThemMoi();
	GhiDBVaoFile();
	LietKe();
//	cout << "--------------------------------------------------" << endl;
	
//	ChinhSua("123");
//	cout << "Danh ba sau khi chinh sua : " << endl;
//	LietKe();
//	cout << "--------------------------------------------------" << endl;
//	
//	Xoa("Nguyen Phan Anh Thu");
//	cout << "Danh ba sau khi xoa : " << endl;
//	LietKe();
//	cout << "--------------------------------------------------" << endl;
//	
//	Contact c = TimKiem("Tu");
//	cout << "Contact : " << endl;
//	LietKe();
//	cout << "--------------------------------------------------" << endl;
}

