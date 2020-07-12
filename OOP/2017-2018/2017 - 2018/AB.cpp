#include "AB.h"

AB::AB()
{
	SetMau(4);
}

AB::AB(bool rh)
{
	SetMau(4);
	SetRH(rh);
}

AB::~AB()
{

}


bool AB::KiemTraDiTruyen(LoaiMau* a, LoaiMau* b)
{
	// this->GetMau() la mau cua nguoi me
	int MauCha = a->GetMau();
	int MauCon = b->GetMau();
	if (MauCha == 1 || MauCha == 2 || MauCha == 4)
	{
		if (MauCon == 1 || MauCon == 2 || MauCon == 4)
		{
			return 1;
		}
	}
	if (MauCha == 3)
	{
		if (MauCon == 1 || MauCon == 2)
		{
			return 1;
		}
	}
	return 0;
}

bool AB::KiemTraNhan(LoaiMau* a)
{
	int checkRH = a->GetRH();
	int checkMau = a->GetMau();
	if (this->GetRH())
	{
		if (checkRH == 1 && checkMau == 4)
			return 1;
	}
	else
	{
		if ((checkRH == 1 && checkMau == 4) || (checkRH == 0 && checkMau == 4))
		{
			return 1;
		}
	}
	return 0;
}