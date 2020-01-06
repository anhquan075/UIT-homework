#include <iostream>

using namespace std;


void Import_Matrix(int arr[][100],int &n,int &m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
			cin>>arr[i][j];
	}
}


void Export_Matrix(int arr[][100],int &n,int &m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

void Multi_2_Matrix(int arr[][100],int b[][100],int c[][100],int n1,int m1,int n2,int m2)
{
	for(int i = 0; i < n1; i++)
    {     
    	for(int j = 0; j < m2; j++)
        {
            c[i][j] = 0;
        }
    }
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < m2; j++)
        {
        	for(int k = 0; k < n1; k++) 
            {
               c[i][j] += arr[i][k]*b[k][j];
            }
        }
    }
}


int main()
{
	int arr[100][100],b[100][100],c[100][100],n1,m1,n2,m2;
	cin>>n1>>m1;
	Import_Matrix(arr,n1,m1);
	Export_Matrix(arr,n1,m1);
	cin>>n2>>m2;
	Import_Matrix(b,n2,m2);
	Export_Matrix(b,n2,m2);
	Multi_2_Matrix(arr,b,c,n1,m1,n2,m2);
	Export_Matrix(c,n1,m2);
	return 0;
}