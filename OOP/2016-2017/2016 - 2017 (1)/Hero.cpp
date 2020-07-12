#include "Hero.h"


Hero::Hero()
{
	SetIntel(0);
	SetPower(0);
	SetMoney(0);
}

Hero::~Hero()
{

}

void Hero::Input()
{
	cout << "\nNhap thong so cua hiep si:\n";
	cout << "\n- Nhap suc manh cua hiep si:\n";
	cin >> power;
	cout << "\n- Nhap tri tue cua hiep si:\n";
	cin >> intel;
	cout << "\n- Nhap so tien cua hiep si:\n";
	cin >> money;
}