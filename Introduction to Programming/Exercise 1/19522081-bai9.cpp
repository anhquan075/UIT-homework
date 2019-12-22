#include<iostream>

using namespace std;

int main()
{
	int n;
	int ngan,tram,chuc,dv,sonut,s1,s2;
	cout <<"Nhap bien so xe cua ban: ";
	cin>>n;
	ngan=n/1000;
	tram=(n/100)%10;
	chuc=(n/10)%10;
	dv=n%10;
	s1=(ngan+tram+chuc+dv)/10;
	s2=(ngan+tram+chuc+dv)%10;
	sonut=s1+s2;
	cout<<"So nut cua xe ban la: "<<sonut;
	return 0;


}