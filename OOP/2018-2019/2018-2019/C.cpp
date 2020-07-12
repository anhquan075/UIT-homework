#include "C.h"


C::C()
{
	SetYeuTo("");
	SetChiSo(0);
}

C::~C()
{

}

void C::CheckChiSo()
{
	if (GetChiSo() >= 70)
	{
		SetYeuTo("Nguoi co diem so cao o yeu to nay thuong la nguoi cham chi, co kha nang chiu ap luc tot. Ho thuong la gan bo, trung thanh voi to chuc.");

	}
	else if (GetChiSo() <= 30)
	{
		SetYeuTo("Nguoi co diem so thap o yeu to nay thuong de bo cuoc, kha nang chiu ap luc, tuan thu ky luc cua to chuc kem.");
	}
	else
	{
		SetYeuTo("Khong xac dinh ro.");
	}
}

void C::Input()
{
	cout << "\nNhap yeu to C:\n";
	Personality::Input();
}

void C::Output()
{
	SetTenYeuTo("Tu chu tan tam (C):");
	Personality::Output();
}