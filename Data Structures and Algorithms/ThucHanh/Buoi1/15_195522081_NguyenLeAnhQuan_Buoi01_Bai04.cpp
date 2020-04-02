// STT: 15
/// Họ và tên : Nguyễn Lê Anh Quân
/// Buổi 1 - Bài 04




#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX 100
#define ll long long int

void import_vector(vector<int> &vec,int &n)
{
	srand(time(NULL));
	n = rand() % 16 + 15;
	for(int i = 0; i < n;++i)
	{
		vec[i] = rand() % 199 - 99;
	}
}

void export_vector(vector<int>& vec,int &n)
{
	for(int i = 0; i < n;++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void export_vector_temp(vector<int> temp)
{
	for(int i = 0; i < temp.size();++i)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
}

void maxSubvectorProduct(vector<int>& vec,int &n,vector<int>& temp) 
{ 
    // max positive product ending at the current position 
    int max_ending_here = 1; 
  
    // min negative product ending at the current position 
    int min_ending_here = 1; 
  
    // Initialize overall max product 
    int max_so_far = 1; 
    int flag = 0; 

    for (int i = 0; i < n; i++)
    { 
        if (vec[i] > 0) { 
            max_ending_here = max_ending_here * vec[i]; 
            min_ending_here = min(min_ending_here * vec[i], 1); 
            flag = 1; 
        } 
        else if (vec[i] == 0) { 
            max_ending_here = 1; 
            min_ending_here = 1; 
        } 
        else { 
            int tmp = max_ending_here; 
            max_ending_here = max(min_ending_here * vec[i], 1); 
            min_ending_here = tmp * vec[i]; 
        } 
  
        // update max_so_far, if needed 
        if (max_so_far < max_ending_here) 
        {
			max_so_far = max_ending_here; 
			temp.push_back(vec[i]);
		}   
    } 
    if (flag == 0 && max_so_far == 1) 
        max_so_far = 0;
	export_vector_temp(temp); 
} 


int main()
{
	int n,choice;
	vector<int> vec(MAX);
	vector<int> temp;
	while(1)
	{
		cout <<"Cau 1\n";
		cout <<"Cau 2\n";
		cout <<"Cau 3\n";
		cout << "Nhap 0 de thoat khoi chuong trinh\n";
		cout <<"Vui long chon cau can su dung:";
		cin >> choice;
		switch(choice)
		{
			case 1:
				import_vector(vec,n);
				break;
			case 2:
				export_vector(vec,n);
				system("pause");
				break;
			case 3:
				maxSubvectorProduct(vec,n,temp);
				system("pause");
				break;
		}
		if(choice > 3 || choice < 1)
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