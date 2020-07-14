// STT: 15
/// Họ và tên : Nguyễn Lê Anh Quân
/// Buổi 3 - Bài 01


#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 1000


struct Stack
{
	int a[MAX];
	int Top;
};

void CreateStack(Stack &s)
{
	s.Top = -1;
}

bool isEmpty(Stack &s) 
{ 
    return (s.Top < 0); 
} 

bool isFull(Stack &s)
{
	return (s.Top >= MAX);
}

bool Push(Stack &s,int x) 
{ 
    if (s.Top >= (MAX - 1)) 
    { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else 
    { 
        s.a[++s.Top] = x; 
        return true; 
    } 
} 
  
int Pop(Stack &s) 
{ 
    if (s.Top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = s.a[s.Top--]; 
        return x; 
    } 
} 

int Peek(Stack &s) 
{ 
    if (s.Top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = s.a[s.Top]; 
        return x; 
    } 
} 
  

void stackDisplay(Stack &s)
{
   if(s.Top>=0)
   {
      cout<<"STACK\t<";
      for(int i = 0; i <= s.Top; ++i)
      {
      	if(i == s.Top)
      		cout << "\t" << s.a[i] << "\t";
      	else
      		cout << "\t" << s.a[i];
      }
      cout << ">\n\n";
   } 
   else
      cout << "STACK\t<\t\t\t\t>\n\n\n";
} 


int countNumber(Stack &s)
{
	int count = 0;
	if(s.Top >= 0)
	{
		for(int i = 0; i <= s.Top; ++i) count++;
	}
	return count;
}

void displayStackTower(Stack &s1,Stack &s2,Stack &s3)
{
	cout << "==============================================\n\n";
	stackDisplay(s1);
	stackDisplay(s2);
	stackDisplay(s3);
}

void towerofHaNoi(Stack &s1,Stack &s2,Stack &s3)
{
	CreateStack(s1);
	CreateStack(s2);
	CreateStack(s3);
	displayStackTower(s1,s2,s3);
	int n,optimal_choice,choice,temp1,temp2,temp3,temp4,temp5,temp6,count = 0;
	do
	{
		cout << "\nNhap so luong dia ban muon tao: ";
		cin >> n;
		if(n < 3)
			cout << "\nSo luong dia khong hop le, vui long nhap lai !\n\n";
	}while(n < 3);
	optimal_choice = pow(2,n) - 1;
	for (int i = n; i > 0; --i)
	{
		Push(s1,i);
	}
	displayStackTower(s1,s2,s3);
	while(1)
	{
		cout << "\n==============================================\n\n";
		cout << "\n1. A->B";
		cout << "\n2. A->C";
		cout << "\n3. B->C";
		cout << "\n4. B->A";
		cout << "\n5. C->B";
		cout << "\n6. C->A";
		cout << "\nChon tu 1 den 6 de thuc hien cac thao tac: \n";
		cin >> choice;
		switch (choice)
		{
			case 1:
				temp1 = Peek(s1);
				if(Peek(s2) > temp1 || isEmpty(s2) == 1)
				{
					Pop(s1);
					Push(s2,temp1);
					displayStackTower(s1,s2,s3);
				}
				else
					cout << "\nKhong hop le, vui long nhap lai !\n";
				break;
			case 2:
				temp2 = Peek(s1);
				if(Peek(s3) > temp2 || isEmpty(s3) == 1)
				{
					Pop(s1);
					Push(s3,temp2);
					displayStackTower(s1,s2,s3);
				}
				else
					cout << "\nKhong hop le, vui long nhap lai !\n";
				break;
			case 3:
				temp3 = Peek(s2);
				if(Peek(s3) > temp3 || isEmpty(s3) == 1)
				{
					Pop(s2);
					Push(s3,temp3);
					displayStackTower(s1,s2,s3);
				}
				else
					cout << "\nKhong hop le, vui long nhap lai !\n";
				break;
			case 4:
				temp4 = Peek(s2);
				if(Peek(s1) > temp4 || isEmpty(s1) == 1)
				{
					Pop(s2);
					Push(s1,temp4);
					displayStackTower(s1,s2,s3);
				}
				else
					cout << "\nKhong hop le, vui long nhap lai !\n";
				break;
			case 5:
				temp5 = Peek(s3);
				if(Peek(s2) > temp5 || isEmpty(s2) == 1)
				{
					Pop(s3);
					Push(s2,temp5);
					displayStackTower(s1,s2,s3);
				}
				else
					cout << "\nKhong hop le, vui long nhap lai !\n";
				break;
			case 6:
				temp6 = Peek(s3);
				if(Peek(s1) > temp6 || isEmpty(s1) == 1)
				{
					Pop(s3);
					Push(s1,temp6);
					displayStackTower(s1,s2,s3);
				}
				else
					cout << "\nKhong hop le, vui long nhap lai !\n";
				break;
			default:
				cout << "\nLenh khong hop le vui long nhap lai !";
		}
		count++;
		if(countNumber(s3) == n)
		{
			cout << "\nBan da thang tro choi!";
			break;
		}
	}
	if(count == optimal_choice)
	{
		cout << "\n\nBan da di chuyen dung voi muc de xuat cho " << n << " dia la " << optimal_choice << "luot\n";
	}
	else
		cout << "\n\nBan da di chuyen trong " << count << " luot. Ban co the di chuyen chi trong " << optimal_choice << " luot.Hay co gang hon o lan sau !\n";
}

int main()
{
	Stack s1,s2,s3;
	towerofHaNoi(s1,s2,s3);
	return 0;
}