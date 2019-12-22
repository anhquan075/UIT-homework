#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

int calculate(int a,int b)
{
	int tong,hieu,tich;
	float thuong;
	tong=a+b;
	hieu=a-b;
	tich=a*b;
	thuong=(a)/(b);
	cout<<tong<<" "<<hieu<<" "<<tich<<" "<<thuong<<" ";
	return 0;
}

int main()
{
	int x,y;
	cin>>x>>y;
	cout<<calculate(x,y);
	return 0;
}