#include "O.h"

O::O()
{
	SetMau(3);
}

O::O(bool rh)
{
	SetMau(3);
	SetRH(rh);
}

O::~O()
{

}


bool O::KiemTraDiTruyen(LoaiMau* a, LoaiMau* b)
{
	int MauCha = a->GetMau();
	int MauCon = b->GetMau();
	if (MauCha == 1)
	{
		return 1;
	}
	if (MauCha == 2)
	{
		if (MauCon == 2 || MauCon == 3)
		{
			return 1;
		}
	}
	if (MauCha == 4)
	{
		if (MauCon == 1 || MauCon == 2)
		{
			return 1;
		}
	}
	if (MauCha == 3)
	{
		if (MauCon == 3)
		{
			return 1;
		}
	}
	return 0;
}

bool O::KiemTraNhan(LoaiMau* a)
{
	int checkRH = a->GetRH();
	int checkMau = a->GetMau();
	if (this->GetRH())
	{
		if (checkRH == 1)
		{
			if (checkMau == 3 || checkMau == 1 || checkMau == 2 || checkMau == 4)
				return 1;
		}
	}
	else
	{
		return 1;
	}
	return 0;
}