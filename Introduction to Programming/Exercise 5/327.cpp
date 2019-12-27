#include <iostream>
#include <vector>
using namespace std;


void importmatrix(int arr[][100],int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		 cin>>arr[i][j];
	}
}


void exportmatrix(int arr[][100],int n,int m)
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


int sumbordermatrix(int arr[][100],int n,int m)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		 {
		 	if(i == 0 || i == n-1 || j == 0 || j == m-1)
		 		sum+=arr[i][j];
		 }
	}
	return sum;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[100][100];
	importmatrix(arr,n,m);
	exportmatrix(arr,n,m);
	cout<<sumbordermatrix(arr,n,m);
	return 0;
}
