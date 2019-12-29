#include <iostream>
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


int Check_MaxElements(int arr[][100], int num_row, int num_col, int n, int m)
{
	int flag = 1;
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			if(n + i >= 0 && m + j >= 0 && n + i < num_row && m + j < num_col && !(i == 0 && j == 0)) 
			{
				  if (arr[n][m] <= arr[n + i][m + j])
				  {
					  flag = 0;
				  }
			}
		}
	}
	return flag;
}



void Find_Max_Element(int arr[][100],int n,int m)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		 {
		 	if(Check_MaxElements(arr,n,m,i,j) == 1)
		 	{
		 		cout<<arr[i][j]<<" ";
		 		count++;
		 	}
		 }
	}
	cout<<endl<<count;
}



int main()
{
	int arr[100][100],n,m;
	cin>>n>>m;
	importmatrix(arr,n,m);
	exportmatrix(arr,n,m);
	Find_Max_Element(arr,n,m);
	return 0;
}