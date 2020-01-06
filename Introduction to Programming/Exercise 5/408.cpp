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

void Arrange_Down_to_Up(int arr[][100],int n,int m,int x)
{
	for(int i = 0; i < m - 1; i++)
		{
			for(int j = i + 1; j < m; j++)
			{
				if(arr[x][i] < arr[x][j])
				{
					Permute(arr[x][i], arr[x][j]);
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
	do{
		cin>>x;
		if(x <= 0 || x >= m)
			cout<<"Vui long nhap lai !";
	}while(x <= 0 || x >= m);
	Arrange_Down_to_Up(arr,n,m,x);
	Export_Matrix(arr,n,m);
	return 0;
}