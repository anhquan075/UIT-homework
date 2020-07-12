#pragma once
#include <iostream>
#include <string>

using namespace std;
class LoaiMau
{
protected:
	int Mau;
	bool rh;
public:
	LoaiMau();
	LoaiMau(int);
	LoaiMau(bool);
	virtual ~LoaiMau();

	void SetMau(int mau) { Mau = mau; }
	int GetMau() { return Mau; }

	void SetRH(bool rhedus) { rh = rhedus; }
	bool GetRH() { return rh; }

	virtual bool KiemTraDiTruyen(LoaiMau* a, LoaiMau* b)
	{
		return 0;
	}
	virtual bool KiemTraNhan(LoaiMau* a)
	{
		return 0;
	}

};

