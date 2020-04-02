// STT: 15
/// Họ và tên : Nguyễn Lê Anh Quân
/// Buổi 1 - Bài 01



#include <iostream>
#include <math.h>
#include <stdlib.h> 
#include <time.h>
using namespace std;


#define MAX 100
#define E(x, i) x.HeSo[i]

struct DonThuc
{
	float HeSo;
	int SoMu;
};
typedef struct DonThuc DONTHUC;
struct DATHUC
{
	float HeSo[MAX];
	int SoMu[MAX];
	int SoPhanTu;
};


void KhoiTaoDaThucRong(DATHUC &dt)
{
	dt.SoPhanTu = 0;
	for (int i = 0; i < MAX; i++)
		dt.HeSo[i] = 0;
}

void NhapDaThuc1(DATHUC &dt)
{
	KhoiTaoDaThucRong(dt);
	do
	{
		cout<<"Nhap bac da thuc: ";
		cin>>dt.SoPhanTu;
		if(dt.SoPhanTu < 1)
		{
			cout<<"\nSo bac cua da thuc phai >= 1. Xin kiem tra lai !";
		}
	}while(dt.SoPhanTu < 1);

	for(int i = dt.SoPhanTu; i >= 0; i--)
	{
		float temp1;
		cout<<"\nNhap he so: ";
		cin>>temp1;
		dt.HeSo[i] = temp1;
	}
}




void XuatDaThuc(DATHUC &dt)
{
	for(int i = dt.SoPhanTu; i > 0; i--)
	{
		if (dt.HeSo[i] != 0)
		{
			cout<<dt.HeSo[i]<<"x^"<<i<<" + ";
		}
	}
	cout<<dt.HeSo[0]<<endl;
}



void NhapDaThuc2(DATHUC &dt)
{
	srand(time(NULL));
	dt.SoPhanTu = rand() % 5 + 5;
	for(int i = 0; i <= dt.SoPhanTu; ++i)
	{
		dt.HeSo[i] = rand() % 90 + 10;
	}

}

float FindXinFx(DATHUC &dt,int x)
{
	float ketqua = 0;
	for(int i = 0;i <= dt.SoPhanTu;i++)
	{
		ketqua += dt.HeSo[i]*pow(x,i);
	}
	return ketqua;
}

int main()
{
	DATHUC dt1;
	int x,choice;
	while(1)
	{
	system("cls");
	cout <<"Cau 1\n";
	cout <<"Cau 2\n";
	cout <<"Cau 3\n";
	cout <<"Cau 4\n";
	cout << "Nhap 0 de thoat khoi chuong trinh\n";
	cout <<"Vui long chon cau can su dung:";
	cin >> choice;
	switch(choice)
	{
		case 1:
			NhapDaThuc1(dt1);
			break;
		case 2:
			NhapDaThuc2(dt1);
			break;
		case 3:
			XuatDaThuc(dt1);
			system("pause");
			break;
		case 4:
			cout<<"\nNhap gia tri x0 can tinh: ";
			cin >> x;
			cout << "Ket qua can tinh: " << FindXinFx(dt1,x) << endl;
			system("pause");
	}
	if(choice > 4 || choice < 1)
	{
		if(choice == 0)
		{
			cout << "Good bye!";
			exit(1);
		}
		else
		{
			cout << "Vui long nhap lai hoac nhap 0 de thoat chuong trinh\n";
		}
		system("pause");
	}
	}
	system("pause");
	return 0;
}