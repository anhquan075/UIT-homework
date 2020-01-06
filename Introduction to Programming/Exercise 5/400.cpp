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


void Del_A_Cow(int arr[][100],int &n,int &m,int &pos)
{
	for(int i = pos;i < n - 1;i++)
	{
		for(int j = 0;j < m;j++)
			arr[i][j] = arr[i+1][j];
	}
	n--;
}

int main(){
	int arr[100][100],n,m,pos;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	cin>>pos;
	Del_A_Cow(arr,n,m,pos);
	Export_Matrix(arr,n,m);
	return 0;
}