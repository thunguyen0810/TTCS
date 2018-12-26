#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std;

typedef struct Contact
{
	char ten[30];
	char sdt[11];
	string gioitinh, email, diachi;
} Contact;

char* fileName = "danhba.dat";

vector<Contact> db;

void DocDBTuFile();
void GhiDBVaoFile();
void ThemMoi(Contact c);
void inContact(Contact c);
void inDB();

int main()
{
	DocDBTuFile();
	//inDB();
	Contact c;
	strcpy(c.sdt, "0338718146");
	strcpy(c.ten, "Nguyen Phan Anh Thu");
	//ThemMoi(c);
	//inDB();
}

void DocDBTuFile()
{
	Contact c;
	db.clear();
	FILE *f;
	f = fopen(fileName, "rb");
	if(f != NULL)
	{
		while(!feof(f))
		{
			Contact c;
			fread(&c, sizeof(Contact), 1, f);
			db.push_back(c);
		}
		fclose(f);
		db.push_back(c);
	}
}

void GhiDBVaoFile()
{
	int size = db.size();
	FILE *f;
	f = fopen(fileName, "wb");
	Contact c;
	for(int i = 0; i < size; i++)
	{
		c = db[i];
		fwrite(&c, sizeof(Contact), 1, f);
	}
	fclose(f);
}

void ThemMoi(Contact c)
{
	db.push_back(c);
	GhiDBVaoFile();
}

void inContact(Contact c)
{
	cout << "So dien thoai " << c.sdt << endl;
	cout << "Ten " << c.ten << endl;
}

void inDB()
{
	int size = db.size();
	for(int i = 0; i < size; i++)
		inContact(db[i]);
}
