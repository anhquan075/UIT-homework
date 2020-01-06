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

void Permute(int &a,int &b)
{
    a = b - a; 
    b = b - a; 
    a = a + b;
}

void Even_Number_Up_to_down(int a[][100], int n, int m)
{
	int temp[100];
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				temp[index++] = a[i][j];
			}
		}
	}
	for(int i = 0; i < index - 1; i++)
	{
		for(int j =  i + 1; j < index; j++)
		{
			if(temp[i] < temp[j])
			{
				Permute(temp[i], temp[j]);
			}
		}
	}
	for(int i = 0;i < index; i++)
		cout<<temp[i]<<" ";
}

int main(){
	int arr[100][100],n,m;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	Even_Number_Up_to_down(arr,n,m);
	return 0;
}


