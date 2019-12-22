#include<iostream>
#include <string>
using namespace std;

int main()
{
	int sl,dg,t,vat;

	string sp;

	cout<<"Nhap ten san pham: ";

	cin>>sp;

	cout<<"Nhap so luong san pham:\n ";

	cin>>sl;

	cout<<"Nhap don gia\n";

	cin>>dg;

	t=sl*dg;

	vat=t*0.1;

	cout<<"So tien can tinh la bao gom tien va thue VAT la: ";

	cout<<t<<","<<vat;

	return 0;

}