#include <iostream>

using namespace std;


void Import_Matrix(int arr[][100],int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		{
			cout<<"Nhap phan tu a["<<i<<"]["<<j<<"]:"<<endl;
			cin>>arr[i][j];
		}
	}
}

void Export_Matrix(int arr[][100],int n,int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}


void Sum_All_Rows(int a[][100], int n, int b[])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			b[i] += a[i][j];
		}
	}
}
void Permute(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Permute_2Rows(int a[][100], int n, int Row1, int Row2)
{
	if((Row1 >= 0 && Row1 < n) && (Row2 >= 0 && Row2 < n))
	{
		for(int j = 0; j < n; j++)
		{
			Permute(a[Row1][j], a[Row2][j]);
		}
	}
}

void Arrrange_Sum_Down_to_Up(int a[][100], int n)
{
	int b[100] = {0};
	Sum_All_Rows(a, n, b);
	for (int i = 0; i < n - 1; i++)  
	{   
		for (int j = i + 1; j < n; j++)   
		{    
			if (b[i] > b[j])    
			{
				Permute_2Rows(a, n, i, j);
				Permute(b[i], b[j]);
			}
		}
	}
}


int main()
{
	int arr[100][100],n,m,x;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	Arrrange_Sum_Down_to_Up(arr,n);
	Export_Matrix(arr,n,m);
	return 0;
}