#include "KyHieu.h"


KyHieu::KyHieu()
{
	SetTruongDo(0);
}

KyHieu::~KyHieu()
{

}


void KyHieu::Input()
{
	int temp;
	cout << "\nNhap gia tri truong do:\n";
	cout << "1. Tron \n2. Trang \n3. Den \n4. Don \n5. Doi \n6. Tam \n7. Tu \n";
	cin >> temp;
	switch (temp)
	{
	case 1:
		SetTruongDo(4);
		break;
	case 2:
		SetTruongDo(2);
		break;
	case 3:
		SetTruongDo(1);
		break;
	case 4:
		SetTruongDo(0.5);
		break;
	case 5:
		SetTruongDo(0.25);
		break;
	case 6:
		SetTruongDo(0.125);
		break;
	case 7:
		SetTruongDo(0.0625);
		break;
	default:
		break;
	}
}


bool KyHieu::KiemTraDauLang()
{
	return false;
}

float KyHieu::GetCaoDo()
{
	return 0;
}