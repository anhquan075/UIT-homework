#include<math.h>
#include<iostream>
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
	int SoMu;
};


void KhoiTaoDaThucRong(DATHUC &dt)
{
	dt.SoMu = 0;
	for (int i = 0; i < MAX; i++)
		dt.HeSo[i] = 0;
}
void NhapDaThuc(DATHUC &dt)
{
	KhoiTaoDaThucRong(dt);
	do
	{
		cout<<"Nhap bac da thuc: ";
		cin>>dt.SoMu;
		if(dt.SoMu < 1)
		{
			cout<<"\nSo bac cua da thuc phai >= 1. Xin kiem tra lai !";
		}
	}while(dt.SoMu < 1);

	for(int i = dt.SoMu; i >= 0; i--)
	{
		float temp;
		cout<<"\nNhap he so: ";
		cin>>temp;
		dt.HeSo[i] = temp;
	}
}

void XuatDaThuc(DATHUC dt)
{
	for(int i = dt.SoMu; i > 0; i--)
	{
		if (dt.HeSo[i] != 0)
		{
			cout<<dt.HeSo[i]<<"x^"<<i<<" + ";
		}
	}
	cout<<dt.HeSo[0]<<endl;
}


//  Tính tổng 2 đa thức
DATHUC TinhTong2DaThuc(DATHUC a, DATHUC b)
{
	DATHUC ketqua;
	KhoiTaoDaThucRong(ketqua);

	// xét bậc đa thức kết quả
	// nếu bậc đa thức a lớn hơn bậc đa thức b
	if(a.SoMu > b.SoMu)
	{
		ketqua.SoMu = a.SoMu;  // bậc đa thức kết quả là bậc đa thức a
	}
	else
	{
		ketqua.SoMu = b.SoMu;
	}
	// xét hệ số đa thức kết quả:
	for(int i = 0; i <= ketqua.SoMu; i++)
	{
		ketqua.HeSo[i] = a.HeSo[i] + b.HeSo[i];
	}
	return ketqua;
}

// Tính hiệu đa thức
DATHUC TinhHieu2DaThuc(DATHUC a, DATHUC b)
{
	DATHUC ketqua;
	KhoiTaoDaThucRong(ketqua);

	// xét bậc đa thức kết quả
	// nếu bậc đa thức a lớn hơn bậc đa thức b
	if(a.SoMu > b.SoMu)
	{
		ketqua.SoMu = a.SoMu;  // bậc đa thức kết quả là bậc đa thức a
	}
	else
	{
		ketqua.SoMu = b.SoMu;
	}
	// xét hệ số đa thức kết quả:
	for(int i = 0; i <= ketqua.SoMu; i++)
	{
		ketqua.HeSo[i] = a.HeSo[i] - b.HeSo[i];
	}
	return ketqua;
}

// Tính tích 2 đa thức

DATHUC TinhTich2DaThuc(DATHUC a, DATHUC b)
{
	DATHUC ketqua;
	KhoiTaoDaThucRong(ketqua);

	// xét bậc đa thức kết quả
	ketqua.SoMu = a.SoMu + b.SoMu; 

	// Xét hệ số đa thức kết quả
	int i, j;
	for(i = 0; i <= a.SoMu; i++)
	{
		for(j = 0; j <= b.SoMu; j++)
		{
			ketqua.HeSo[i + j] += a.HeSo[i] * b.HeSo[j];
		}
	}
	return ketqua;
}


DATHUC TinhDaoHamCap1(DATHUC dt)
{
	DATHUC ketqua;
	ketqua.SoMu = dt.SoMu - 1;
	for(int i = dt.SoMu; i >= 0; i--)
	{		
		ketqua.HeSo[i - 1] = dt.HeSo[i] * i;
	}
	return ketqua;
}

DATHUC TinhDaoHamCapk(DATHUC dt)
{
	DATHUC ketqua,temp;
	int k;
	cout<<"Nhap k:";
	cin>>k;
	temp = dt;
	for(int i = k; i >=1;i--)
	{
		ketqua = TinhDaoHamCap1(temp);
		temp = ketqua;
	}
	return temp;
}


int tinhgiatritaix0(DATHUC &dt,int x0)
{
	cout<<"\nNhap gia tri x0 can tinh:\n ";
	cin>>x0;
	float ketqua = 0;
	for(int i = 0;i < dt.SoMu;i++)
	{
		ketqua += dt.HeSo[i]*pow(x0,i);
	}
	cout<<"Gia tri cua da thuc tai x0 la: "<<ketqua<<endl;
	return 0;
}

int main(void)
{
	DATHUC kq;
	DATHUC dt1, dt2;
	int k,x0;
	cout<<"\nDa thuc 1:\n";
	NhapDaThuc(dt1);
	XuatDaThuc(dt1);
	cout<<"\nDa thuc 2:\n";
	NhapDaThuc(dt2);
    XuatDaThuc(dt2);
    cout<<"\nTong cua 2 da thuc la: ";
	XuatDaThuc(TinhTong2DaThuc(dt1, dt2));
	cout<<"\nHieu cua 2 da thuc la: ";
	XuatDaThuc(TinhHieu2DaThuc(dt1, dt2));
	cout<<"\nTich cua 2 da thuc la: ";
	XuatDaThuc(TinhTich2DaThuc(dt1, dt2));
	cout<<"\nDao ham cap 1 cua da thuc thu nhat la: ";
	XuatDaThuc(TinhDaoHamCap1(dt1));
	cout<<"\nDao ham cap 1 cua da thuc thu hai la: ";
	XuatDaThuc(TinhDaoHamCap1(dt2));
	XuatDaThuc(TinhDaoHamCapk(dt1));
	XuatDaThuc(TinhDaoHamCapk(dt2));
	tinhgiatritaix0(dt1,x0);
	tinhgiatritaix0(dt2,x0);
}
