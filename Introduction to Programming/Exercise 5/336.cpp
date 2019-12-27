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


int counthowmanyappear(int arr[][100],int n,int m,int target)
{
	int count = 0;
	for(int i=0;i< n; i++)
	{
		for(int j = 0;j < m;j++)
			if(arr[i][j] == target)
				count++;
	}
	return count;
}


int main()
{
	int n,m,target;
	cin>>n>>m;
	int arr[100][100];
	importmatrix(arr,n,m);
	exportmatrix(arr,n,m);
	cin>>target;
	cout<<counthowmanyappear(arr,n,m,target);
	return 0;
}