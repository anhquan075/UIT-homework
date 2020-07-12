#pragma once
#include "LoaiMau.h"
class A :public LoaiMau
{
public:
	A();
	A(bool rh);
	~A();

	bool KiemTraDiTruyen(LoaiMau* a, LoaiMau* b);
	bool KiemTraNhan(LoaiMau* a);
};

