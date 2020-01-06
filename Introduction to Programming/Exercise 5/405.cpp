#include <iostream>

using namespace std;



void Import_Matrix(int arr[][100],int &n,int &m)
{
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			cout<<"Nhap phan tu a["<<i<<"]["<<j<<"]:"<<endl;
			cin>>arr[i][j];
		}
	}
}


void Export_Matrix(int arr[][100],int &n,int &m)
{
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		 {
		 	cout<<arr[i][j]<<" ";
		 }
		 cout<<endl;
	}
}


void Mirror_Y_Axis(int arr[][100],int &n,int &m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = m - 1;j >=0;j--)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}


int main()
{
	int arr[100][100],n,m;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	Mirror_Y_Axis(arr,n,m);
	return 0;
}