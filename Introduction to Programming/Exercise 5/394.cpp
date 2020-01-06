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

void Permute(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Permute_2Rows(int arr[][100],int Rows1,int Rows2,int n,int m)
{
	if((Rows1 >= 0 && Rows1 < n) && (Rows2 >= 0 && Rows2 < n))
	{
		for(int i = 0; i < m; i++)
			Permute(arr[Rows1][i],arr[Rows2][i]);
	}
}

void Move_Round_Clock_Down_To_Up(int arr[][100],int n,int m)
{
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			Permute(arr[i][j],arr[i-1][j]);
		}
	}
}

int main(){
	int arr[100][100],n,m;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	Move_Round_Clock_Down_To_Up(arr,n,m);
	cout<<endl;
	Export_Matrix(arr,n,m);
	return 0;
}
