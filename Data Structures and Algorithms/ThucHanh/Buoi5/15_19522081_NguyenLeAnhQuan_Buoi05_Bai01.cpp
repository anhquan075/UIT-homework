/// STT:15
/// Họ và tên: Nguyễn Lê Anh QUân
/// Buổi 05 - Bài 01



#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

#define MAX 1e5


void CreateDataset(double a[])
{
	srand(time(NULL));
	for(int i = 0;i < MAX;++i)
	{
		a[i] = rand() + rand()/RAND_MAX;
	}
}

void CopyArray(double b[],double a[])
{
	for(int i = 0;i < MAX;++i)
	{
		b[i] = a[i];
	}
}

double calculateCreateTime(double a[])
{
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	CreateDataset(a);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}



void OutputDataset(double a[])
{
	for(int i = 0;i < MAX;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(double *xp, double *yp) 
{ 
    double temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}


void selectionSort(double arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
}

void insertionSort(double arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
	{ 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void Create15Dataset(double c[15][(int)MAX],int n)
{
	srand(time(NULL));
	for(int i = 0;i < 15;i++)
	{
		for(int j = 0;j < MAX;++j)
		{
			c[i][j] = rand() + (double)rand()/RAND_MAX;
		}
	}
}


double SortTime(double a[(int)MAX],int n)
{	
	clock_t start, end;	
	double cpu_time_used;
	if(n == 1)
	{
		start = clock();
		selectionSort(a,MAX);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	else if(n == 2)
	{
		start = clock();
		insertionSort(a,MAX);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	return cpu_time_used;
}



void Compare(double c[15][(int)MAX],double a[(int)MAX],double b[(int)MAX])
{
	for(int i = 0;i < 15 ;++i)
	{
		for(int j = 0;j < MAX;++j)
		{
			a[j] = c[i][j];
			b[j] = c[i][j];
		}
		cout << "\n=========================================================================================\n";
		cout << "\tDataset " << i + 1 << "\t|\t\t"  << SortTime(b,1) << "\t\t|\t\t" << SortTime(a,2) << "\t\t|\t\t";
	}
}

double c[15][(int)MAX];
double a[(int)MAX];
double b[(int)MAX];

int main()
{
	int choice,choice1;
	while(1)
	{
		system("cls");
		cout << "\n---------------MENU----------------\n";
		cout << "1. Create 100k elements.\n";
		cout << "2. Output.\n";
		cout << "3. Selection Sort.\n";
		cout << "4. Insertion Sort.\n";
		cout << "5. Compare insertion sort and selection sort.\n";
		cout << "Vui long chon tu 1-5 de thuc hien chuong trinh (Nhan 0 de thoat).\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
				CreateDataset(a);
				CopyArray(b,a);
				system("pause");
				break;
			case 2:
				do
				{
					cout << "\nChon tiep:";
					cin >> choice1;
					if(choice < 1|| choice1 > 2)
						cout << "\nVui long nhap lai.\n";
				}while(choice1 < 1 || choice1 > 2);
				if(choice1 == 1)
				{
					OutputDataset(a);
					system("pause");
					break;
				}
				else
				{
					OutputDataset(b);
					system("pause");
					break;	
				}
			case 3:
				cout << "\nTime to use selection sort: " << SortTime(b,1) << endl;
				system("pause");
				break;
			case 4:
				cout << "\nTime to use insertion sort: " << SortTime(b,2) << endl;
				system("pause");
				break;
			case 5:
				cout << "=========================================================================================\n";
				cout << "\tDataset\t\t|\tSelection Sort\t\t|\tInsertion Sort\t\t|";
				Create15Dataset(c,MAX);
				Compare(c,a,b);
				cout << endl;
                system("pause");
				break;
		}
		if(choice < 1 || choice > 5)
		{
			if(choice == 0)
			{
				cout << "\nGood bye <3";
				exit(1);
			}
			else
			{
				cout << "\nVui long chon lai.\n";
				system("pause");
			}
		}
	}
	return 0;
}