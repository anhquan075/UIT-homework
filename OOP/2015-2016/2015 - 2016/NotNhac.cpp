#include "NotNhac.h"


NotNhac::NotNhac()
{

}

NotNhac::~NotNhac()
{

}


void NotNhac::Input()
{
	int temp;
	cout << "\nNhap vao cao do:\n";
	cout << "1. Do(C)\n2. Re(D)\n3. Mi(E)\n4. Fa(F)\n5. Sol(G)\n6. La(A)\n7. Si(B)\n";
	cin >> temp;
	switch (temp)
	{
	case 1:
		SetCaoDo(1);
		break;
	case 2:
		SetCaoDo(2);
		break;
	case 3:
		SetCaoDo(3);
		break;
	case 4:
		SetCaoDo(4);
		break;
	case 5:
		SetCaoDo(5);
		break;
	case 6:
		SetCaoDo(6);
		break;
	case 7:
		SetCaoDo(7);
		break;
	default:
		break;
	}
	KyHieu::Input();
}

