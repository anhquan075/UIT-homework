#include "DuongLuat.h"


DuongLuat::DuongLuat()
{
	SetSoCau(8);
}

DuongLuat::~DuongLuat()
{
	
}

void DuongLuat::Input()
{
	vector<string> veccautho;
	veccautho.resize(GetSoCau());
	for (int i = 0; i < GetSoCau(); ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			cin >> veccautho[j];
		}
	}
	cin.ignore();
	SetVecCauTho(veccautho);
}

void DuongLuat::Output()
{
	cout << "\nBai tho theo the duong luat:\n";
	Poem::Output();
}