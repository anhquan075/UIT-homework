#include "Personality.h"

Personality::Personality()
{
	SetYeuTo("");
	SetChiSo(0);
}

Personality::Personality(string yt, int cs)
{
	SetYeuTo(yt);
	SetChiSo(cs);
}

Personality::~Personality()
{

}

void Personality::Output()
{
	cout << GetChiSo() << "\t|\t" << GetTenYeuTo() << " " << GetYeuTo() << "||" << endl;
}

void Personality::Input()
{
	cout << "\nNhap yeu to:\n";
	cin >> this->YeuTo;
	cout << "\nNhap chi so:\n";
	cin >> this->ChiSo;
}

void Personality::CheckChiSo()
{

}