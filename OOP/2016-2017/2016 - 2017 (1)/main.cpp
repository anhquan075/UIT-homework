#include "Hero.h"
#include "Gate.h"
#include "Power.h"
#include "Academic.h"
#include "Business.h"

#define MAX 100

int main()
{
	Gate* DS[MAX];
	Hero h;
	// Cau 1
	int n;
	cout << "\nNhap vao so luong cong:\n";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		system("cls");
		cout << "1. Power.\n";
		cout << "2. Academic.\n";
		cout << "3. Business.\n";
		int temp;
		cin >> temp;
		switch (temp)
		{
		case 1:
			DS[i] = new Power();
			break;
		case 2:
			DS[i] = new Academic();
			break;
		case 3:
			DS[i] = new Business();
			break;
		default:
			break;
		}
		DS[i]->Input();
	}
	//Cau 2
	h.Input();
	int temp1 = h.GetMoney(), temp2 = h.GetPower();
	for (int i = 0; i < n; ++i)
	{
		if (DS[i]->GetType() == 3)
		{
			temp1 -= DS[i]->GetBack();
			if (temp1 < 0)
			{
				cout << "\nHiep si chua vuot qua duoc cong giao thuong.\n";
				continue;
			}
			else
			{
				h.SetMoney(temp1);
				cout << "\nHiep si da vuot qua duoc cong giao thuong.\n";
				cout << "\nThong so hien tai cua hiep sy:\n";
				cout << "- So tien: " << h.GetMoney() << endl;
				cout << "- Tri tue: " << h.GetIntel() << endl;
				cout << "- Suc manh: " << h.GetPower() << endl;
			}
		}
		if (DS[i]->GetType() == 2)
		{
			if (h.GetIntel() >= DS[i]->GetBack())
			{
				cout << "\nHiep si da vuot qua duoc cong hoc thuat.\n";
				cout << "\nThong so hien tai cua hiep sy:\n";
				cout << "- So tien: " << h.GetMoney() << endl;
				cout << "- Tri tue: " << h.GetIntel() << endl;
				cout << "- Suc manh: " << h.GetPower() << endl;
			}
			else
			{
				cout << "\nHiep si chua vuot qua duoc cong hoc thuat.\n";
				continue;
			}
		}
		if (DS[i]->GetType() == 1)
		{
			temp2 -= DS[i]->GetBack();
			if (temp2 < 0)
			{
				cout << "\nHiep si chua vuot qua duoc cong suc manh.\n";
				continue;
			}
			else
			{
				h.SetPower(temp2);
				cout << "\nHiep si da vuot qua duoc cong suc manh.\n";
				cout << "\nThong so hien tai cua hiep sy:\n";
				cout << "- So tien: " << h.GetMoney() << endl;
				cout << "- Tri tue: " << h.GetIntel() << endl;
				cout << "- Suc manh: " << h.GetPower() << endl;
			}
		}
	}
	return 0;
}