#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

typedef struct Contact
{
	string ten;
	char sdt[11];
	string gioitinh, email, diachi;
} Contact;

vector<Contact> db;
ifstream fi("input.dat");

char data[100];

void DocFile()
{
	FILE *f = fopen("input.dat", "rb");
}

void ThemMoi(Contact c)
{
	db.push_back(c);
	
}

void Ghidb()
{
	for(int i = 0; i < db.size(); i++)
		f --> (&db[i], sizeof(db), 1, f)
}

void LietkeDB()
{
	DocFile();
	for(int i = 0; i < sizeof(db); i++)
		Xuat(db[i]);
}

void CapNhat(Contact c)
{
	//Tim contact m co so dien thoai c.sdt
	//Cap nhat c vao m
	//Ghi danh ba vao file
}

void XoaContact(char *sdt)
{
	//Tim contact m co trong danh ba
	//Xoa m
	//Ghi danh ba vao file
}

vector <Contact> TimTheoTen(char *ten)
{
	//Tim cac contact m co ten "ten"
	//Them m vao bien vector
	//Tra ve bien vector
}

int main()
{
	Contact c;
	strcpy(c.ten, "Nguyen Phan Anh Thu");
	c.gioitinh = 1;
	strcpy(c.sdt, "0338718146");
	strcpy(c.email, "thunguyen1918@gmail.com");
	strcpy(c.diachi, "Nha Trang");
	cout << c.ten
}
