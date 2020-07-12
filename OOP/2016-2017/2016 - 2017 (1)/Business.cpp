#include "Business.h"

Business::Business()
{
	SetDonGia(0);
	SetSoHang(0);
	SetType(3);
}

Business::~Business()
{

}


void Business::Input()
{
	cout << "\nChao mung toi cong giao thuong:\n";
	cout << "\nNhap don gia:\n";
	cin >> dongia;
	cout << "\nNhap so hang:\n";
	cin >> sohang;
}

int Business::GetBack()
{
	return dongia * sohang;
}