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

int Main_Wavy_Line(int a[][100], int n)
{
	int flag = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i][i] > a[j][j])
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}


int main()
{
	int arr[100][100],n,m;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	if(Main_Wavy_Line(arr,n) == 1)
	{
		cout<<"Duong cheo chinh tang dan !";
	}else
	{
		cout<<"Duong cheo chinh khong tang dan !";
	}

	return 0;
}