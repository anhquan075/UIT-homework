#include "LucBat.h"


LucBat::LucBat()
{

}

LucBat::~LucBat()
{

}

void LucBat::Input()
{
	cout << "Nhap tho luc bat:\n";
	vector<string> veccautho;
	do
	{
		cout << "\nNhap so cau: ";
		cin >> SoCau;
		if (SoCau % 4 != 0)
			cout << "\nVui long nhap lai so cau.\n\n";
	} while (SoCau % 4 != 0);
	veccautho.resize(SoCau);
	for (int i = 0; i < SoCau; i++)
	{
		if (i % 2 != 0)
		{
			cout << "Nhap cau luc: ";
			for (int j = 0; j < 6; ++j)
			{
				cin >> veccautho[i];
			}
		}
		else
		{
			cout << "Nhap cau bat: ";
			for (int j = 0; j < 8; ++j)
			{
				cin >> veccautho[i];
			}
		}
	}
	cin.ignore();
	SetVecCauTho(veccautho);
}

void LucBat::Output()
{
	cout << "\nBai tho luc bat:\n";
	Poem::Output();
}