#pragma once
#include "Gate.h"
class Business:public Gate
{
private:
	int dongia;
	int sohang;
public:
	Business();
	~Business();

	void SetDonGia(int dg) { dongia = dg; }
	int GetDonGia() { return dongia; }

	void SetSoHang(int sh) { sohang = sh; }
	int GetSoHang() { return sohang; }

	void Input();
	int GetBack();
};

