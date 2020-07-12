#include "Academic.h"

Academic::Academic()
{
	SetIntel(0);
	SetType(2);
}

Academic::~Academic()
{

}

void Academic::Input()
{
	cout << "\nChao mung toi cong hoc thuat:\n";
	cout << "\nNhap tri tue cua nha hien triet:\n";
	cin >> intel;
}

int Academic::GetBack()
{
	return intel;
}