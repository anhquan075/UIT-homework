#include "Button.h"
#include "Label.h"
#include "Web.h"
#include <math.h>

#define MAX 100

bool CheckColor(int a,int b)
{
	return abs(a - b) == 6;
}

bool CheckDuplicate(int x, int y, int z) 
{
	int data[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,1,2 };
	return (data[x + 1] == y && data[x + 2] == z);
}

int main()
{
	Web* DS[MAX];
	// Cau 1
	int n, temp;
	cout << "\nNhap vao phan tu cua trang web:\n";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		system("cls");
		cout << "1. Button\n";
		cout << "2. Label\n";
		cin >> temp;
		switch (temp)
		{
		case 1:
			DS[i] = new Button();
			break;
		case 2:
			DS[i] = new Label();
		default:
			break;
		}
		DS[i]->Input();
	}
	cout << "\n\nCac thanh phan cua trang web:\n";
	for (int i = 0; i < n; ++i)
	{
		cout << "\n- Thanh phan thu " << i + 1 << ":\n";
		DS[i]->Output();
	} 

	// Cau 2
	if (CheckColor(DS[0]->GetTextColor(),DS[0]->GetBackGroundColor()))
		cout << "\n\nThanh phan dau tien la mau bo tuc!\n";
	else
		cout << "\n\nThanh phan dau tien Khong la mau bo tuc!\n";
	// Cau 3
	int dd[13];
	for (int i = 0; i <= 12; i++)
		dd[i] = 0;
	for (int i = 0; i < n; i++)
		dd[DS[i]->GetBackGroundColor()]++;

	int spt = 0;
	int mau[13];
	for (int i = 1; i <= 12; i++)
		if (dd[i] != 0)
			mau[spt++] = i;
	cout << "\nMau nen cac thanh phan: ";
	if (spt == 1)
		cout << "Theo nguyen tac: mau don sac\n";
	else
		if (spt == 2 && CheckColor(mau[0], mau[1]))
			cout << "Theo nguyen tac: Mau bo tuc\n";
		else
			if (spt == 3 && CheckDuplicate(mau[0], mau[1], mau[2]))
				cout << "\nTheo nguyen tac: Mau tuong dong\n";
			else
				cout << "\nKhong theo nguyen tac nao!\n";
	return 0;
}