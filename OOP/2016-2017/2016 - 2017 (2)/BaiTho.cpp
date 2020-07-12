#include "BaiTho.h"


Poem::Poem()
{
	SetSoCau(0);
	SetTenBaiTho("");
	SetSoTieng(0);
	vector<string> veccautho;
	veccautho.resize(0);
	SetVecCauTho(veccautho);
}

Poem::~Poem()
{

}

void Poem::Input()
{
	cout << "Nhap ten bai tho: ";
	getline(cin, TenBaiTho);
	cout << "Nhap so cau: ";
	cin >> SoCau;
	vector<string> veccautho;
	veccautho.resize(SoCau);
	for (int i = 0; i < SoCau; i++)
	{
		cout << "Nhap so tieng: ";
		cin >> SoTieng;
		for (int j = 0; j < SoTieng; ++j)
		{
			cin >> veccautho[j];
		}
	}
	cin.ignore();
	SetVecCauTho(veccautho);
}

void Poem::Output()
{
	vector<string> veccautho = GetVecCauTho();
	for (int i = 0; i < veccautho.size(); i++)
	{
		cout << veccautho[i] << endl;
	}
	cout << endl;
}