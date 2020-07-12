#include "B.h"

B::B()
{
	SetMau(2);
}

B::B(bool rh)
{
	SetMau(2);
	SetRH(rh);
}

B::~B()
{

}


bool B::KiemTraDiTruyen(LoaiMau* a, LoaiMau* b)
{
	int MauCha = a->GetMau();
	int MauCon = b->GetMau();
	if (MauCha == 1)
	{
			return 1;
	}
	if (MauCha == 2)
	{
		return 1;
	}
	if (MauCha == 4)
	{
		if (MauCon == 1 || MauCon == 2 || MauCon == 4)
		{
			return 1;
		}
	}
	if (MauCha == 3)
	{
		if (MauCon == 2 || MauCon == 3)
		{
			return 1;
		}
	}
	return 0;
}

bool B::KiemTraNhan(LoaiMau* a)
{
	int checkRH = a->GetRH();
	int checkMau = a->GetMau();
	if (this->GetRH())
	{
		if (checkRH == 1)
		{
			if (checkMau == 2 || checkMau == 4)
				return 1;
		}
	}
	else
	{
		if (checkRH == 1 || checkRH == 0)
		{
			if (checkMau == 2 || checkMau == 4)
				return 1;
		}
	}
	return 0;
}


