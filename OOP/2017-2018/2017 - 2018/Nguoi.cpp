#include "Nguoi.h"


Nguoi::Nguoi()
{

}

Nguoi::~Nguoi()
{
	
}

void Nguoi::Input(int n)
{
	vector<LoaiMau*> lm;
	lm.resize(100);
	SetSoLuong(n);
	for (int i = 0; i < GetSoLuong();++i)
	{
		cout << "\nNhap nguoi thu " << i + 1 << ":\n";
		int temp, rh;
		cout << "\nNhap loai mau voi A ,B, O, AB tuong ung voi (1,2,3,4):\n";
		cin >> temp;
		cout << "\nNhap loai rh(rhedus) voi + (1), - (0):\n";
		cin >> rh;
		switch (temp)
		{
		case 1:
			lm[i] = new A(rh);
			lm[i]->SetRH(rh);
			break;
		case 2:
			lm[i] = new B(rh);
			lm[i]->SetRH(rh);
			break;
		case 3:
			lm[i] = new O(rh);
			lm[i]->SetRH(rh);
			break;
		case 4:
			lm[i] = new AB(rh);
			lm[i]->SetRH(rh);
			break;
		default:
			break;
		}
	}
	SetNguoi(lm);
}

void Nguoi::Output()
{
	vector<LoaiMau*> lm = GetNguoi();
	for (int i = 0; i < GetSoLuong(); ++i)
	{
		cout << "\nNguoi thu " << i + 1 << " :\n";
		cout << "- Nhom: ";
		switch (lm[i]->GetMau())
		{
		case 1:
			cout << " A " << endl;
			break;
		case 2:
			cout << " B " << endl;
			break;
		case 3:
			cout << " O " << endl;
			break;
		case 4:
			cout << " AB " << endl;
			break;
		}
		cout << "- Rh:";
		if (lm[i]->GetRH())
		{
			cout << "+" << endl;
		}
		else
		{
			cout << "-" << endl;
		}
	}
}

void Nguoi::CheckDiTruyen()
{
	vector<LoaiMau*> lm = GetNguoi();
	if (lm[1]->KiemTraDiTruyen(lm[0], lm[2]))
	{
		cout << "\nDay la con cua chung ta.\n";
	}
	else
	{
		cout << "\nChia buon cung gia dinh. :(\n";
	}
}

void Nguoi::CheckNhanMau()
{
	vector<LoaiMau*> ng = GetNguoi();
	int temp;
	cout << "\nNhap SBD cua nguoi can tim trong danh sach:\n";
	cin >> temp;
	for (int i = 0; i < GetSoLuong(); ++i)
	{
		if (i == temp)
		{
			ng[i] = ng[temp];
		}
		if (ng[temp]->KiemTraNhan(ng[i]))
		{
			cout << "\nCo the nhan mau nguoi nay.\n";
		}
		else
		{
			cout << "\nKhong the nhan mau nguoi nay.\n";
		}
	}
}