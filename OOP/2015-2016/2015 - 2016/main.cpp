#include "KyHieu.h"
#include "NotNhac.h"
#include "DauLang.h"

#define MAX 100

int main()
{
	KyHieu* DS[MAX];
	int n,count = 0;
	cout << "\nNhap vao so luong cac ky hieu am nhac:\n";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		system("cls");
		cout << "1. Soan not nhac\n";
		cout << "2. Soan dau lang\n";
		cin >> temp;
		switch (temp)
		{
		case 1:
			DS[i] = new NotNhac();
			break;
		case 2:
			DS[i] = new DauLang();
			break;
		default:
			break;
		}
		DS[i]->Input();
	}

	// Cau 2
	for (int i = 0; i < n; ++i)
	{
		if (DS[i]->KiemTraDauLang())
			count++;
	}
	cout << "Ban nhac co so dau lang la: " << count << endl;

	// Cau 3
	float max = DS[0]->GetCaoDo(), vt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (max < DS[i]->GetCaoDo())
		{
			max = DS[i]->GetCaoDo();
			vt = i;
		}
	}
	cout << "\nNot nhac co do cao nhat trong bang tai vi tri : " << vt << endl;

	return 0;
}