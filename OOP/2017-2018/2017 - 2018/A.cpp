#include "A.h"

A::A()
{
	SetMau(1);
}

A::A(bool rh)
{
	SetMau(1);
	SetRH(rh);
}

A::~A()
{

}

bool A::KiemTraDiTruyen(LoaiMau* a, LoaiMau* b)
{
	// this->GetMau() la mau cua nguoi me
	int MauCha = a->GetMau();
	int MauCon = b->GetMau();
	if (MauCha == 1)
	{
		if (MauCon == 1 || MauCon == 3)
		{
			return 1;
		}
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
		if (MauCon == 1 || MauCon == 3)
		{
			return 1;
		}
	}
	return 0;
}

bool A::KiemTraNhan(LoaiMau* a)
{
	int checkRH = a->GetRH();
	int checkMau = a->GetMau();
	if (this->GetRH())
	{
		if (checkRH == 1)
		{
			if (checkMau == 1 || checkMau == 4)
				return 1;
		}
	}
	else
	{
		if (checkRH == 1 || checkRH == 0)
		{
			if (checkMau == 1 || checkMau == 4)
				return 1;
		}
	}
	return 0;
}