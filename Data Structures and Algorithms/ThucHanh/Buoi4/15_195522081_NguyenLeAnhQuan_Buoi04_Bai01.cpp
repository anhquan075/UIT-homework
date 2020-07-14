#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <string>

using namespace std;


int random(int min, int max)
{
    return min + rand() % (max - min + 1);
}


void InputArray1th(int A[],int n)
{
	srand(time(NULL));
	for(int i = 0; i < n;++i)
	{
		A[i] = random(100,999);
	}
}

void InputArray2th(int A[],int n)
{
	srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        if(i == 0) 
           A[i] = random(100,130);
        else 
           A[i] = A[i - 1] + random(0,15);
    }
}


int LinearSearch(int A[],int n,int x)
{
	for (int i = 0; i < n; ++i)
	{
		if(A[i] == x)
			return i;
	}
	return -1;
}

int BinarySearch(int A[],int n,int x)
{
	int left = 0,right = n - 1;
	while(left <= right )
	{
		int mid = (left + right) / 2;
		if(A[mid] == x)
			return mid;
		if(A[mid] > x)
			right = mid - 1;
		if(A[mid] < x)
			left = mid + 1;
	}
	return -1;
}

int InterpolationSearch(int A[],int n,int x)
{
	int left = 0,right = n - 1;
   	while(left < right && x >= A[left] && x <= A[right]) 
    { 

        int mid = left + (((double)(right - left) / (A[right] - A[left])) * (x - A[left])); 
        if(A[mid] == x)
			return mid;
  
        if (A[mid] == x) 
            return mid; 

        if (A[mid] < x) 
            left = mid + 1;  
        else
            right = mid - 1; 
    } 
    return -1;
}

void OutputArray(int A[],int& n)
{
	for(int i = 0; i < n;++i)
		cout << A[i] << " ";
	cout << endl;
}


int CountLinearSearch(int A[],int n,int x)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		count++;
		if(A[i] == x)
			return count;
	}
	return count;
}

int CountBinarySearch(int A[],int n,int x)
{
	int left = 0,right = n - 1,count = 0;
	while(left <= right )
	{
		count++;
		int mid = (left + right) / 2;
		if(A[mid] == x)
			return count;
		if(A[mid] > x)
			right = mid - 1;
		if(A[mid] < x)
			left = mid + 1;
	}
	return count;
}


int CountInterpolationSearch(int A[],int n,int x)
{
	int left = 0,right = n - 1,count = 0;
   	while(left < right && x >= A[left] && x <= A[right]) 
    { 
    	count++;
        int mid = left + (((double)(right - left) / (A[right] - A[left])) * (x - A[left])); 
        if(A[mid] == x)
			return count;
  
        if (A[mid] == x) 
            return mid; 

        if (A[mid] < x) 
            left = mid + 1;  
        else
            right = mid - 1; 
    } 
    return count;
}

bool comp(int a, int b) 
{ 
    return (a < b); 
} 

void CompareSearch(int A[],int n,int x)
{

	int l1 = CountLinearSearch(A,n,x);
	int l2 = CountBinarySearch(A,n,x);
	int l3 = CountInterpolationSearch(A,n,x);
	cout << l1 << " " << l2 << " " << l3 << endl;

	if(l1 == min({l1,l2,l3},comp))
		cout << "\nTim kiem tuyen tinh nhanh nhat voi " << l1 << " lan thuc hien\n";
	else if (l1 == max({l1,l2,l3},comp))
		cout << "\nTim kiem tuyen tinh cham nhat voi " << l1 << " lan thuc hien\n";
	
	if(l2 == min({l1,l2,l3},comp))
		cout << "\nTim kiem nhi phan nhanh nhat voi " << l2 << " lan thuc hien\n";
	else if (l2 == max({l1,l2,l3},comp))
		cout << "\nTim kiem nhi phan cham nhat voi " << l2 << " lan thuc hien\n";
	
	if(l3 == min({l1,l2,l3},comp))
		cout << "\nTim kiem noi suy nhanh nhat voi " << l3 << " lan thuc hien\n";
	else if (l3 == max({l1,l2,l3},comp))
		cout << "\nTim kiem noi suy cham nhat voi " << l3 << " lan thuc hien\n";

}

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;
	return (*x - *y);
}


int main()
{
	int n = random(30,50);
	int A[n],B[n],x,choice,choice1,choice2,choice3,choice4,choice5;
	while(1)
	{
		system("cls");
		cout << "===================MENU==================\n";
		cout << "1.Tao Mang:\n";
		cout << "\t1.1 Tao mang Array X\n";
		cout << "\t1.2 Tao mang Array Y\n";
		cout << "2.Xuat mang:\n";
		cout << "\t2.1 Xuat mang Array X\n";
		cout << "\t2.2 Xuat mang Array Y\n";
		cout << "3.Tim kiem tuyen tinh\n";
		cout << "\t3.1 Ap dung mang Array X\n";
		cout << "\t3.2 Ap dung mang Array Y\n";
		cout << "4.Tim kiem nhi phan, ap dung mang Array Y\n";
		cout << "5.Tim kiem noi suy, ap dung mang Array Y\n";
		cout << "6.So sanh cac lan tim kiem, su dung mang Array Y\n";
		cout << "7.Su dung ham built-in cua C++ de thuc hien tim kiem\n";
		cout << "8.Su dung ham tu cac thu vien co san cua C++ de thuc hien tim kiem\n";
		cout << "\nNhap tu 1->8 de thuc hien thao tac (0 de thoat khoi chuong trinh):";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "\nChon 1 de tao mang Array x hoac chon 2 da tao mang Array Y\n";
				do
				{
					cin >> choice1;
					if(choice1 < 1 || choice1 > 2)
						cout << "\nVui long nhap lai\n\n";
				}while(choice1 < 1 || choice1 > 2);
				if(choice1 == 1)
				{
					InputArray1th(A,n);
					break;
				}
				if(choice1 == 2)
				{
					InputArray2th(B,n);
					break;
				}
			case 2:
				cout << "\nChon 1 de xuat mang Array x hoac chon 2 da xuat mang Array Y\n";
				do
				{
					cin >> choice2;
					if(choice2 < 1 || choice2 > 2)
						cout << "\nVui long nhap lai\n\n";
				}while(choice2 < 1 || choice2 > 2);
				if (choice2 == 1)
				{
					OutputArray(A,n);
					system("pause");
				}	
				if (choice2 == 2)
				{
					OutputArray(B,n);
					system("pause");
				}	
				break;
			case 3:
				cout << "\nChon 1 de tim phan tu trong mang Array x hoac chon 2 de tim phan tu trong mang Array Y\n";
				do
				{
					cin >> choice3;
					if(choice3 < 1 || choice3 > 2)
						cout << "\nVui long nhap lai\n\n";
				}while(choice3 < 1 || choice3 > 2);
				if(choice3 == 1)
				{
					cout << "\nNhap x:";
					cin >> x;
					cout << "\nX nam o vi tri thu " << LinearSearch(A,n,x) << endl;
				}
				else if(choice3 == 2)
				{
					cout << "\nNhap x:";
					cin >> x;
					cout << "\nX nam o vi tri thu " << LinearSearch(B,n,x) << endl;
				}
				system("pause");
				break;
			case 4:
				cout << "\nNhap x:";
				cin >> x;
				cout << "\nX nam o vi tri thu " << BinarySearch(B,n,x) << endl;
				system("pause");
				break;
			case 5:
				cout << "\nNhap x:";
				cin >> x;
				cout << "\nX nam o vi tri thu " << InterpolationSearch(B,n,x) << endl;
				system("pause");
				break;
			case 6:
				CompareSearch(B,n,x);
				system("pause");
				break;
			case 7:
				cout << "\nChon 1 de tim kiem tren mang Array x hoac chon 2 de tim kiem tren mang Array Y\n";
				do
				{
					cin >> choice4;
					if(choice4 < 1 || choice4 > 2)
						cout << "\nVui long nhap lai\n\n";
				}while(choice4 < 1 || choice4 > 2);
				if(choice4 == 1)
				{
					cout << "\nNhap x:";
					cin >> x;
					sort(A, A + n);
					if (binary_search(A, A + n, x)) 
        				cout << x << " co trong mang Array X\n"; 
   					else
        				cout << x << " khong co trong mang Array X\n";
					system("pause");
					break;
				}
				if(choice4 == 2)
				{
					cout << "\nNhap x:";
					cin >> x;
					if (binary_search(B, B + n, x)) 
        				cout << x << " co trong mang Array Y\n"; 
   					else
        				cout << x << " khong co trong mang Array Y\n";
					system("pause");		
					break;
				}
			case 8:
				cout << "\nChon 1 de tim kiem tren mang Array x hoac chon 2 de tim kiem tren mang Array Y\n";
				do
				{
					cin >> choice5;
					if(choice5 < 1 || choice5 > 2)
						cout << "\nVui long nhap lai\n\n";
				}while(choice5 < 1 || choice5 > 2);
				if(choice5 == 1)
				{
					cout << "\nNhap x:";
					cin >> x;
					int *p = (int*)bsearch(&x,A,n,sizeof(int),compare);
					if(p == NULL)
						cout << x << " khong co trong mang " << endl;
					else
						cout << x << " co trong mang tai vi tri " << (p-A) << endl;
					//delete [] p;
					system("pause");
					break;
				}
				if(choice5 == 2)
				{
					cout << "\nNhap x:";
					cin >> x;
					int *p = (int*)bsearch(&x,B,n,sizeof(int),compare);
					if(p == NULL)
						cout << x << " khong co trong mang " << endl;
					else
						cout << x << " co trong mang tai vi tri " << (p-B) << endl;
					//delete [] p;
					system("pause");
					break;
				}
		}
		if(choice > 8 || choice < 1)
		{
			if(choice == 0)
			{
				cout << "\nGood Bye <3\n";
				exit(1);
			}
			else
				cout << "\nKhong hop le vui long nhap lai!\n";
		}
	}
	return 0;
}