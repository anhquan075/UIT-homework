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


void Rotate_Right_Side_In_Border(int arr[][100],int &n,int &m)
{
	int i, j;
	int temp = arr[0][0]; 
	for(i = 0, j = i; i < n - 1; i++) 
	{
		arr[i][j] = arr[i + 1][j]; 
	}

	for (j, i; j < m - 1; j++)  
	{   
		arr[i][j] = arr[i][j + 1]; 
	}

	for (i, j; i > 0; i--) 
	{
		arr[i][j] = arr[i - 1][j]; 
	}
	for (i, j; j > 1; j--) 
	{
		arr[i][j] = arr[i][j - 1]; 
	}
	arr[0][1] = temp;
}

int main(){
	int arr[100][100],n,m;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	for(int i = 1;i <= 8;i++)
	{
		Rotate_Right_Side_In_Border(arr,n,m);
		cout<<endl;
		Export_Matrix(arr,n,m);
	}
	return 0;
}