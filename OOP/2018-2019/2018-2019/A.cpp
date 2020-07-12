#include "A.h"


A::A()
{
	SetYeuTo("");
	SetChiSo(0);
}

A::~A()
{

}

void A::CheckChiSo()
{
	if (GetChiSo() >= 70)
	{
		SetYeuTo("Nguoi co diem so cao o yeu to nay thuong than thien, coi mo, dong cam voi moi nguoi nhung nhieu khi \"thieu chinh kien \" ");

	}
	else if (GetChiSo() <= 30)
	{
		SetYeuTo("Nguoi co diem so thap o yeu to nay thuong dat loi ich cua ban than len tren, it dong cam, chia se voi dong nghiep, co tinh canh tranh cao.");
	}
	else
	{
		SetYeuTo("Khong xac dinh ro.");
	}
}

void A::Input()
{
	cout << "\nNhap yeu to A:\n";
	Personality::Input();
}

void A::Output()
{
	SetTenYeuTo("Hoa dong de chiu (A):");
	Personality::Output();
}