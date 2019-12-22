#include<iostream>

using namespace std;

int main()
{
	int t,l,h;
	int hst,hsl,hsh,dtb;
	cout<<"Nhap so diem Toan: ";
	cin>>t;
	cout<<"\nNhap he so mon Toan: ";
	cin>>hst;
	cout<<"\nNhap so diem Hoa: ";
	cin>>h;
	cout<<"\nNhap he so mon Hoa: ";
	cin>>hsh;
	cout<<"\nhap so diem Ly: ";
	cin>>l;
	cout<<"\nNhap he so mon Ly: ";
	cin>>hsl;
	dtb=(t*hst+h*hsh+l*hsl)/(hst+hsh+hsl);
	cout<<"\nDiem trung binh la: "<<dtb;
	return 0;
}