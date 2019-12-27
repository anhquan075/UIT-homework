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


int countposnuminbor(int arr[][100],int n,int m)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		 {
		 	if(i == 0 || i == n-1 || j == 0 || j == m-1 && arr[i][j] > 0)
		 		count++;
		 }
	}
	return count;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[100][100];
	importmatrix(arr,n,m);
	exportmatrix(arr,n,m);
	cout<<countposnuminbor(arr,n,m);
	return 0;
}