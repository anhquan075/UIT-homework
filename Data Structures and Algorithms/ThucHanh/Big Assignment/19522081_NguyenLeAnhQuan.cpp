#include <iostream>
#include <time.h>
#include <bits/stdc++.h> 

using namespace std;

#define MAX 5e6 

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


void OutputDataset(double a[])
{
	for(int i = 0;i < MAX;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int partition (double arr[], int low, int high)
{
    int pivot = arr[high];    
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
void quickSort(double arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void heapify(double arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  

    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  

void heapSort(double arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
}


void merge(double a[], int left, int mid, int right)
{
	int *temp; 
	int i = left; 
	int j = mid + 1; 
 
	temp = new int[right - left + 1]; 
 
	for (int k = 0; k <= right - left; k++)
	{
		if (a[i] < a[j]) 
		{
			temp[k] = a[i]; 
			i++; 
		}
		else 
		{
			temp[k] = a[j];
			j++; 
		}
		if (i == mid + 1) 
		{
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}
		if (j == right + 1) 
		{
			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}
 
	for (int k = 0; k <= right - left; k++) 
		a[left + k] = temp[k];
	delete temp;
}


void mergeSort(double a[], int left, int right)
{
	if (right > left)
	{
		int mid; 
		mid = (left + right) / 2;
	mergeSort(a, left, mid); 
	mergeSort(a, mid + 1, right); 
	merge(a, left, mid, right); 
	}
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

double SortTime(double a[],int n)
{
	clock_t start, end;	
	double cpu_time_used;
	if(n == 1)
	{
		start = clock();
		quickSort(a,0,MAX-1);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	else if(n == 2)
	{
		start = clock();
		heapSort(a,MAX);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	else if(n == 3)
	{
		start = clock();
	 mergeSort(a,0,MAX-1);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	else if(n == 4)
	{
		start = clock();
		qsort (a, MAX, sizeof(double), compare);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	else if(n == 5)
	{
		start = clock();
		sort(a,a+(int)MAX);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	return cpu_time_used;
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

void Compare(double c[15][(int)MAX],double a[(int)MAX],double b[(int)MAX],double d[(int)MAX],double e[(int)MAX],double f[(int)MAX])
{
	for(int i = 0;i < 15 ;++i)
	{
		for(int j = 0;j < MAX;++j)
		{
			a[j] = c[i][j];
			b[j] = c[i][j];
			d[j] = c[i][j];
			e[j] = c[i][j];
			f[j] = c[i][j];
		}
		cout << "\n=================================================================================================================================================================================================================\n";
		cout << "\tDataset " << i + 1 << "\t|\t\t"  << SortTime(a,1) << "\t\t\t|\t\t" << SortTime(b,2) << "\t\t\t|\t\t" << SortTime(d,3) << "\t\t\t|\t\t" << SortTime(e,4) << "\t\t|\t\t" << SortTime(f,5) << "\t\t|\t";
	}
}


double c[15][(int)MAX];
double a[(int)MAX];
double b[(int)MAX];
double d[(int)MAX];
double e[(int)MAX];
double f[(int)MAX];

int main()
{
	int choice;
	while(1)
	{
		system("cls");
		cout << "\n---------------MENU----------------\n";
		cout << "1. Create 15 datasets\n";
		cout << "2. Experiment Results.\n";
		cout << "Vui long chon tu 1-2 de thuc hien chuong trinh (Nhan 0 de thoat).\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Create15Dataset(c,MAX);
				system("pause");
				break;
			case 2:
				cout << "\n=================================================================================================================================================================================================================\n";
				cout << "\tDataset\t\t|\t\tQuick Sort\t\t|\t\tHeap Sort\t\t|\t\tMerge Sort\t\t|\t\tqsort\t\t|\t\tsort\t\t|";
				Compare(c,a,b,d,e,f);
				cout << "\n=================================================================================================================================================================================================================\n";
                system("pause");
				break;
		}
		if(choice < 1 || choice > 2)
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