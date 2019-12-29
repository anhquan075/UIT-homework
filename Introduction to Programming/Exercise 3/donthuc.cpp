#include <iostream>
#include <math.h>

using namespace std;


struct DONTHUC{
	float heso;
	float somu; 
};

void nhapdonthuc(DONTHUC &dt)
{
	cout<<"Nhap he so:";
	cin>>dt.heso;
	cout<<"Nhap so mu:";
	cin>>dt.somu;
}


void xuatdonthuc(DONTHUC &dt)
{
	cout<<"He so la:"<<dt.heso<<endl;
	cout<<"So mu la:"<<dt.somu<<endl;
	if(dt.heso == 1 && de.somu == 0)
		cout<<"Don thuc la 1"<<endl;
}


DONTHUC tichdonthuc(DONTHUC &a,DONTHUC &b){
	DONTHUC c;
	c.heso =a.heso*b.heso;
	c.somu =a.somu*b.somu;
	return c;
}

DONTHUC thuongdonthuc(DONTHUC &a,DONTHUC &b){
	DONTHUC c;
	c.heso =a.heso/b.heso;
	c.somu = a.somu-b.somu;
	return c;
}



DONTHUC daohamcap1(DONTHUC &dt){
	DONTHUC c;
	c.heso = dt.heso*dt.somu;
	c.somu = dt.somu - 1;
	return c;
}


int tinhgiadonthuc(DONTHUC &dt,int n){
	int giatridt;
	giatridt = dt.heso*(pow(n,dt.somu));
	return giatridt;
}

int main(){
	DONTHUC a,b;
	int n;
	nhapdonthuc(a);
	nhapdonthuc(b);
	cout<<"Nhap gia tri x0: ";
	cin>>n;
	cout<<"Gia tri cua don thuc tai x0: "<<tinhgiadonthuc(a,n)<<"\t"<<tinhgiadonthuc(b,n)<<endl;
	DONTHUC c = tichdonthuc(a,b);
	DONTHUC d = thuongdonthuc(a,b);
	cout<<"Tich cua don thuc: "<<endl;
	xuatdonthuc(c);
	cout<<"Thuong cua don thuc: "<<endl;
	xuatdonthuc(d);
	cout<<"Dao ham cap mot cua don thuc: "<<endl;
	DONTHUC e = daohamcap1(a);
	xuatdonthuc(e);
	DONTHUC h = daohamcap1(b);
	xuatdonthuc(h);
	return 0;
}
