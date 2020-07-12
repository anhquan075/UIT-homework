#include "E.h"


E::E()
{
	SetYeuTo("");
	SetChiSo(0);
}

E::~E()
{

}

void E::CheckChiSo()
{
	if (GetChiSo() >= 70)
	{
		SetYeuTo("Nguoi co diem so cao o yeu to nay thuong la nguoi la nguoi nhiet tinh, nang dong, giao tiep tot, thich the hien ban than. ");

	}
	else if (GetChiSo() <= 30)
	{
		SetYeuTo("Nguoi co diem so thap o yeu to nay thuong ngai giao tiep, khong thich su noi bat , thich duoc lam viec doc lap.");
	}
	else
	{
		SetYeuTo("Khong xac dinh ro.");
	}
}

void E::Input()
{
	cout << "\nNhap yeu to E:\n";
	Personality::Input();
}

void E::Output()
{
	SetTenYeuTo("Huong ngoai (E):");
	Personality::Output();
}