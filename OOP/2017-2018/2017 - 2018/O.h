#pragma once
#include "LoaiMau.h"
class O :public LoaiMau
{
public:
	O();
	O(bool rh);
	~O();

	bool KiemTraDiTruyen(LoaiMau* a, LoaiMau* b);
	bool KiemTraNhan(LoaiMau* a);
};

