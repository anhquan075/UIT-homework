#include <iostream>

using namespace std;


void Import_Matrix(int arr[][100],int n,int m)
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


int Check_Rows_Down(int arr[][100],int x,int n)
{
	int flag = 0;
	for(int j = 0;j < n - 1;j++)
	{
		for(int k = j + 1;k < n;k++)
		{
			if(arr[x][j] > arr[x][k])
			{	
				flag = 1;
			}
		}
	}
	return flag;
}

int Check_Cols_Down(int arr[][100],int x,int m)
{
	int flag = 0;
	for(int j = 0; j < m - 1; j++)
	{
		for(int k = j + 1; k < m; k++)
		{
			if(arr[j][x] > arr[k][x])
			{	
				flag = 1;
			}
		}
	}
	return flag;
}


int Check_Matrix_Down(int arr[][100],int n,int m)
{
	int flag = 1;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(Check_Rows_Down(arr,i,n) == 0 || Check_Cols_Down(arr,j,m) == 0)
			{	
				flag = 0;
			}
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
	if(Check_Matrix_Down(arr,n,m) == 1)
		cout<<"Ma tran giam dan !";
	else 
		cout<<"Ma tran khong thoa dieu kien !";
	return 0;
}