#include <iostream>

using namespace std;


void Import_Matrix(int arr[][100],int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		{
			cout<<"Nhap phan tu a["<<i<<"]["<<j<<"]:"<<endl;
			cin>>arr[i][j];
		}
	}
}

void Export_Matrix(int arr[][100],int n,int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

void Minus_2_Matrix(int arr[][100],int b[][100],int c[][100],int n,int m)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0; j < m;j++)
		{
			c[i][j] += arr[i][j] - b[i][j];
		}
	}
}


int main()
{
	int arr[100][100],b[100][100],c[100][100],n,m;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	Import_Matrix(b,n,m);
	Export_Matrix(b,n,m);
	Minus_2_Matrix(arr,b,c,n,m);
	Export_Matrix(c,n,m);
	return 0;
}