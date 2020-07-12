#pragma once
#include "LoaiMau.h"
class AB :public LoaiMau
{
public:
	AB();
	AB(bool rh);
	~AB();

	bool KiemTraDiTruyen(LoaiMau* a, LoaiMau* b);
	bool KiemTraNhan(LoaiMau* a);
};

