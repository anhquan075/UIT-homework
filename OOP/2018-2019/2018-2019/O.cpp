#include "O.h"


O::O()
{
	SetYeuTo("");
	SetChiSo(0);
}

O::~O()
{

}

void O::CheckChiSo()
{
	if (GetChiSo() >= 70)
	{
		SetYeuTo("Nguoi co diem so cao o yeu to nay thuong la nguoi thich nhung y tuong moi, thich hieu biet nhieu linh vuc nhung dong thoi cung thich tu do, khong thic bi rang buoc.");

	}
	else if (GetChiSo() <= 30)
	{
		SetYeuTo("Nguoi co diem so thap o yeu to nay thuong kha bao thu, kho tiep nhan nhung y tuong moi, la. Ho thich su on dinh, quen thuoc va thuc te.");
	}
	else
	{
		SetYeuTo("Khong xac dinh ro.");
	}
}

void O::Input()
{
	cout << "\nNhap yeu to O:\n";
	Personality::Input();
}

void O::Output()
{
	SetTenYeuTo("San sang trai nghiem (O):");
	Personality::Output();
}