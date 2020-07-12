#include "TapTho.h"


TapTho::TapTho()
{

}

TapTho::~TapTho()
{

}

void TapTho::InputTapTho()
{
	int n, temp;
	cout << "\nNhap so luong bai tho:\n";
	cin >> n;
	vector<Poem*> vectaptho;
	vectaptho.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cout << "1. Tho luc bat" << endl;
		cout << "2. Tho song that luc bat" << endl;
		cout << "3. Tho that ngon bat cu duong luat" << endl;
		cin >> temp;
		switch (temp)
		{
		case 1:
			vectaptho[i] = new LucBat();
			break;
		case 2:
			vectaptho[i] = new SongThat();
			break;
		case 3:
			vectaptho[i] = new DuongLuat();
			break;
		default:
			break;
		}
		vectaptho[i]->Input();
	}
	SetTapTho(vectaptho);
}

void TapTho::OutputTapTho()
{
	vector<Poem*> vtt = GetTapTho();
	for (int i = 0; i < vtt.size(); ++i)
	{
		cout << "\nBai tho thu " << i + 1 << ":\n";
		vtt[i]->Output();
	}
}

void TapTho::BaiThoDaiNhat()
{
	vector<Poem*> vtt = GetTapTho();
	int max = vtt[0]->GetSoCau(), vt = 0;
	for (int i = 0; i < vtt.size(); ++i)
	{
		if (max < vtt[i]->GetSoCau())
		{
			max = vtt[i]->GetSoCau();
			vt = i;
		}
	}
	vtt[vt]->Output();
}