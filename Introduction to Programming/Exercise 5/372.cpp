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


void Find_Max_Element_In_Cow(int arr[][100],int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		int max = arr[i][0];
		for(int j = 0;j < m;j++)
		{
		 	if(arr[i][j] > max)
		 		max = arr[i][j];
		}
		cout<<max<<" ";
	}
}


int main(){
	int arr[100][100];
	int n,m;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	Find_Max_Element_In_Cow(arr,n,m);
	return 0;
}