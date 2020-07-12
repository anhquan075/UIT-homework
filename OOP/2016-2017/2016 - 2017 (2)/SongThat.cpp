#include "SongThat.h"

SongThat::SongThat()
{

}

SongThat::~SongThat()
{

}

void SongThat::Input()
{
	vector<string> veccautho;
	cout << "Nhap tho song that luc bat:\n";
	int count = 0; // Biến count để phân biệt câu nào là câu lục, thất, bát
	do
	{
		cout << "Nhap so cau: ";
		cin >> SoCau;
		if (SoCau % 4 != 0)
		{
			cout << "\nVui long nhap lai.\n\n";
		}
	} while (SoCau % 4 != 0);
	veccautho.resize(SoCau);
	for (int i = 0; i < SoCau; i++)
	{
		if (count == 0 || count == 1)
		{
			cout << "Nhap cau that: ";
			for (int j = 0; j < 7; ++j)
			{
				cin >> veccautho[i];
			}

		}
		if (count == 2)
		{
			cout << "Nhap cau luc: ";
			for (int j = 0; j < 6; ++j)
			{
				cin >> veccautho[i];
			}
		}
		else if (count == 3)
		{
			cout << "Nhap cau bat: ";
			for (int j = 0; j < 8; ++j)
			{
				cin >> veccautho[i];
			}
			count = 0;
		}
		count++;
	}
	cin.ignore();
	SetVecCauTho(veccautho);
}

void SongThat::Output()
{
	cout << "\nBai tho song that luc bat:\n";
	Poem::Output();
}