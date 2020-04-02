// STT: 15
/// Họ và tên : Nguyễn Lê Anh Quân
/// Buổi 1 - Bài 05




#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define ll long long unsigned int


int finaci(int n) 
{ 
  int f[n+1]; 
  int i; 
  f[0] = 0;   
  f[1] = 1;  
  for (i = 2; i <= n; i++) 
      f[i] = f[i-1] + f[i-2]; 
  
  return f[n]; 
} 
 

void array_w_fibonacci(int arr[],int n)
{
	srand(time(NULL));
	for(int i = 0; i < n; ++i)
	{
		arr[i] = finaci(i);
	}
}

void export_fibonacci(int arr[],int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
}

void find_fibonacci(int x)
{
	cout << "Nhap so fibonacci can tim:\n";
	cin >> x;
	cout << "So fibonacci can tim: " << finaci(x) << endl;
}

int main()
{
	srand(time(NULL));
	int n = rand() % 41 + 10;
	int arr[n],choice,x;
	while(1)
	{
		system("cls");
		cout <<"Cau 1\n";
		cout <<"Cau 2\n";
		cout <<"Cau 3\n";
		cout <<"Vui long chon cau can su dung (Chon so 0 de thoat chuong trinh):";
		cin >> choice;
		if(choice > 3 || choice < 1)
		{
			if(choice == 0)
				exit(0);
			else
			{
				cout << "Vui long chon lai!\n";
				system("pause");
			}
		}
		switch(choice)
		{
			case 1:
				array_w_fibonacci(arr,n);
				continue;
			case 2:
				export_fibonacci(arr,n);
				system("pause");
				continue;
			case 3:
				find_fibonacci(x);
				system("pause");
				continue;
		}
	}
	return 0;
}