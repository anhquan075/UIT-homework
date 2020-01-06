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



int Find_Max_Element(int arr[][100],int n,int m)
{
	int max = arr[0][0];
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		{
			if(arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}



int main(){
	int arr[100][100];
	int n,m,x;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	cout<<Find_Max_Element(arr,n,m);
	return 0;
}
