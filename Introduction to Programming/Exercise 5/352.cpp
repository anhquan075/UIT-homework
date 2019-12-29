#include <iostream>

using namespace std;


void Import_Matrix(int arr[][100],int n,int m)
{
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			cin>>arr[i][j];
		}
	}
}


void Export_Matrix(int arr[][100],int n,int m)
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



int Check_Rows_Up(int arr[][100],int x,int n)
{
	int flag = 0;
	for(int j = 0;j < n - 1;j++)
	{
		for(int k = j + 1;k < n;k++)
		{
			if(arr[x][j] < arr[x][k])
				flag = 1;
		}
	}
	return flag;
}

int main(){
	int arr[100][100];
	int n,m,x;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	do
	{
		cin>>x;
		if(x < 0 || x > n -1)
			cout<<"Vui long nhap lai !";
	}while(x < 0 || x > n -1);
	if(Check_Rows_Up(arr,x,n) == 1)
		cout<<"Dong "<<x<<" tang dan !";
	else
		cout<<"Dong "<<x<<" khong tang dan !";
	return 0;
}