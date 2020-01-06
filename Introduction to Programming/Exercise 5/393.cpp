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


void Permute(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void Permute_2Cols(int arr[][100],int Cols1,int Cols2,int n,int m)
{
	if((Cols1 >= 0 && Cols1 < m) && (Cols2 >= 0 && Cols2 < m))
	{
		for(int i = 0; i < n; i++)
			Permute(arr[i][Cols1],arr[i][Cols2]);
	}
}


int main(){
	int arr[100][100],n,m,Cols1,Cols2;
	cin>>n>>m;
	Import_Matrix(arr,n,m);
	Export_Matrix(arr,n,m);
	do{
		cin>>Cols1;
		if(Cols1 < 0 && Cols1 >= m)
			cout<<"Vui long nhap lai !";
	}while(Cols1 < 0 && Cols1 >= m);

	do{
		cin>>Cols2;
		if(Cols2 < 0 && Cols2 >= m)
			cout<<"Vui long nhap lai !";
	}while(Cols2 < 0 && Cols2 >= n);
	
	Permute_2Cols(arr,Cols1,Cols2,n,m);
	Export_Matrix(arr,n,m);
	return 0;
}