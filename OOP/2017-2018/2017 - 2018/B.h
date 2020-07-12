#pragma once
#include "LoaiMau.h"
class B :public LoaiMau
{
public:
	B();
	B(bool rh);
	~B();

	bool KiemTraDiTruyen(LoaiMau* a, LoaiMau* b);
	bool KiemTraNhan(LoaiMau* a);
};

