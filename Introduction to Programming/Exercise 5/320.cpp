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


int sumpositivenum(int arr[][100],int n,int m)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		 {
		 	if(arr[i][j] > 0)
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
	cout<<sumpositivenum(arr,n,m);
	return 0;
}
