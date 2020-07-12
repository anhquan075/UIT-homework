#include "N.h"


N::N()
{
	SetYeuTo("");
	SetChiSo(0);
}

N::~N()
{

}

void N::CheckChiSo()
{
	if (GetChiSo() >= 70)
	{
		SetYeuTo("Nguoi co diem so cao o yeu to nay thuong co cac cam xuc tieu cuc nhu: lo lang, buc boi,tu ti, yeu duoi va kha nang chiu ap luc kem.");

	}
	else if (GetChiSo() <= 30)
	{
		SetYeuTo("Nguoi co diem so thap o yeu to nay thuong kiem soat duoc cam xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong den tinh trang cua ban than.");
	}
	else
	{
		SetYeuTo("Khong xac dinh ro.");
	}
}

void N::Input()
{
	cout << "\nNhap yeu to N:\n";
	Personality::Input();
}

void N::Output()
{
	SetTenYeuTo("Bat on cam xuc (N):");
	Personality::Output();
}