#include<iostream>

using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	if(a>b)
	{
		cout<<"Max: "<<a;
		cout<<"\nMin: "<<b;
	}else
	{
		cout<<"Max: "<<b;
		cout<<"\nMin: "<<a;
	}
	return 0;
}
