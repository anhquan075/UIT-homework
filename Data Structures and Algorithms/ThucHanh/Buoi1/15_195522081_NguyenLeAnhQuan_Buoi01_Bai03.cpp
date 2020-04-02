// STT: 15
/// Họ và tên : Nguyễn Lê Anh Quân
/// Buổi 1 - Bài 03




#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

#define MAX 100
#define RANGE_MAX 99


void import_array(int arr[],int n)
{
	srand(time(NULL));
	for(int i = 0; i < n;++i)
	{
		arr[i] = rand() % 445 + 555;
	}
}

int random(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void import_progressive_array(int arr[],int &n)
{
	int delta = RANGE_MAX/n;
	srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        if(i == 0) 
           arr[i] = random(delta,10);
        else 
           arr[i] = random((i + 1) * delta,arr[i - 1] + 1);
    }
}

void export_array(int arr[],int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l)
    { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
}

int main()
{
	srand(time(NULL));
	int n = rand() % 16 + 15,x;
	int arr[MAX],choice;
	while(1)
	{
		system("cls");
		cout <<"Cau 1\n";
		cout <<"Cau 2\n";
		cout <<"Cau 3\n";
		cout <<"Cau 4\n";
		cout << "Nhap 0 de thoat khoi chuong trinh\n";
		cout <<"Vui long chon cau can su dung:";
		cin >> choice;
		switch(choice)
		{
			case 1:
				import_array(arr,n);
				break;
			case 2:
				import_progressive_array(arr,n);
				break;
			case 3:
				export_array(arr,n);
				system("pause");
				break;
			case 4:
				cout << "Nhap vi tri can tim:\n";
				cin >> x;
				int result = binarySearch(arr, 0, n - 1, x); 
				cout << "\nVi tri phan tu: ";
				if(result == -1)
					cout << "Phan tu khong co trong mang.\n";
				else
					cout << result << endl;
				system("pause");
				break;
		}
		if(choice > 4 || choice < 1)
		{
			if(choice == 0)
			{
				cout << "Good bye!";
				exit(1);
			}
			else
			{
				cout << "Vui long nhap lai hoac nhap 0 de thoat chuong trinh\n";
			}
			system("pause");
		}
	}
	system("pause");
	return 0;
}

