// STT: 15
/// Họ và tên : Nguyễn Lê Anh Quân
/// Buổi 1 - Bài 02





#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define MAX_SIZE 1000

void importArray(int arr[],int &n)
{
	cout << "Nhap so luong phan tu:\n";
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
}

void importArray2(int arr[],int &n)
{
	srand(time(NULL));
	n = rand() % 41 + 10;
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 21 + 100;
	}
}
void export_array(int arr[], int &n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] <<"\t";
	}
	cout << endl;
}

void findFrequency(int arr[],int &n)
{
	int freq[100000]={0}; 
    for(int i = 0;i < n;i++)
        freq[arr[i]]++;    //Increment count of freq[a[i]] for each a[i].
    for(int i = 0 ;i< 100000;i++)
    {
        if(freq[i])
        cout <<i <<" : "<<freq[i]<<endl;
	}
}

int main()
{
	int choice,n;
	int arr[MAX_SIZE];
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
			importArray(arr,n);
			break;
		case 2:
			importArray2(arr,n);
			break;
		case 3:
			export_array(arr,n);
			system("pause");
			break;
		case 4:
			cout << "Tan suat xuat hien cua tung gia tri la:\n";
			findFrequency(arr,n);
			system("pause");
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
