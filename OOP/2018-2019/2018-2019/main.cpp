#include "Personality.h"
#include "QuanLiTamLy.h"

#define MAX 100

int main()
{
	// Cau 1
	QuanLiTamLy q;
	q.InputPersonality();
	q.OutputPersonality();

	// Cau 2
	int n,temp ;
	cout << "\nNhap danh sach nguoi:\n";
	cin >> n;
	vector<QuanLiTamLy> quanli;
	quanli.resize(MAX);
	for (int i = 0; i < n; ++i)
	{
		cout << "\nNhap nguoi thu " << i + 1 << ":\n";
		quanli[i].InputPersonality();
	}
	for (int i = 0; i < n; ++i)
	{
		cout << "\nNguoi thu " << i + 1 << ":\n";
		quanli[i].OutputPersonality();
	}
	// Cau 3
	cout << "\nNhap nguoi trong danh sach " << n << " nguoi:\n";
	cin >> temp;
	for (int i = 0; i < n; ++i)
	{
		if (i == temp)
		{
			cout << "\nNguoi ban can tim la:\n";
			quanli[i].OutputPersonality();
			break;
		}
		else if (temp > n)
		{
			cout << "\nVuot qua danh sach cho truoc.\n";
		}
	}
	return 0;
}