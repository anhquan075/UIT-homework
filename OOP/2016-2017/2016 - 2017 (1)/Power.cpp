#include "Power.h"


Power::Power()
{
	SetPower(0);
	SetType(1);
}

Power::~Power()
{

}

void Power::Input()
{
	cout << "\nChao mung toi cong suc manh:\n";
	cout << "\nNhap suc manh cua dung sy:\n";
	cin >> power;
}

int Power::GetBack()
{
	return power;
}