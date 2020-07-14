#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
struct Node
{
	int data;
	Node* pRight;
	Node* pLeft;
};

typedef Node* Tree;



void CreateTree(Tree& t)
{
	t = NULL;
}


void InsertANode(Tree& t, int x)
{
	Node* p = new Node;
	if (t == NULL)
	{
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			t->pLeft = p;
		}
		
		else if (t->data < x)
		{
			t->pRight = p;
		}
	}
}

void NLR(Tree& t)
{	
	if (t != NULL)
	{
		if(t->pRight == NULL || t->pLeft == NULL)
		{
			cout << t->data << "\t" << t << "\t\tpLeft:" << t->pLeft << "\t\t\tpRight:" << t->pRight << endl;
		}
		else
		{
			cout << t->data << "\t" << t << "\t\tpLeft:" << t->pLeft << "\t\tRight:" << t->pRight << endl;
		}
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}


void LRN(Tree& t)
{
	
	if (t != NULL)
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		if(t->pRight == NULL || t->pLeft == NULL)
		{
			cout << t->data << "\t" << t << "\t\tpLeft:" << t->pLeft << "\t\t\tpRight:" << t->pRight << endl;
		}
		else
		{
			cout << t->data << "\t" << t << "\t\tpLeft:" << t->pLeft << "\t\tRight:" << t->pRight << endl;
		}
	}
}



void LNR(Tree& t)
{
	
	if (t != NULL)
	{
		LNR(t->pLeft);
		if(t->pRight == NULL || t->pLeft == NULL)
		{
			cout << t->data << "\t" << t << "\t\tpLeft:" << t->pLeft << "\t\t\tpRight:" << t->pRight << endl;
		}
		else
		{
			cout << t->data << "\t" << t << "\t\tpLeft:" << t->pLeft << "\t\tRight:" << t->pRight << endl;
		}
		LNR(t->pRight);
	}
}

void RNL(Tree& t)
{
	
	if (t != NULL)
	{

		RNL(t->pRight);
		if(t->pRight == NULL || t->pLeft == NULL)
		{
			cout << t->data << "\t" << t << "\t\tpLeft:" << t->pLeft << "\t\t\tpRight:" << t->pRight << endl;
		}
		else
		{
			cout << t->data << "\t" << t << "\t\tpLeft:" << t->pLeft << "\t\tRight:" << t->pRight << endl;
		}
		RNL(t->pLeft);
	}
}

Node* iterativeSearch(Tree t, int x) 
{ 
    if (t == NULL)
        return NULL;
 
	Node* p = t;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		else if (p->data > x)
		{
			p = p->pLeft;
		}
		else
		{
			p = p->pRight;
		}
	}
}

void FindAnotherNode(Tree& X, Tree& Y)
{
	if (Y->pLeft != NULL)
	{
		FindAnotherNode(X, Y->pLeft);
	}
	else
	{
		X->data = Y->data;
		X = Y;
		Y = Y->pRight;

	}
}

void DeleteSomeNode(Tree& t, int x)
{
	if (t == NULL)
		return;
	else
	{
		if (x < t->data)
			DeleteSomeNode(t->pLeft, x);
		else if (x > t->data)
			DeleteSomeNode(t->pRight, x);
		else
		{
			Node* X = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else
			{
				Node* Y = t->pRight;
				FindAnotherNode(X, Y);
			}
			delete X;

		}

	}
}


void CreateRandomTree(Tree &t,int n)
{
	srand(time(NULL));
	for(int i = 0;i < n;++i)
	{
		InsertANode(t,rand() % 1001 + 358);
	}
}


void CreateBruteForceTree(Tree &t,int n,int a[])
{
	cout << "Nhap so luong node:\n";
	cin >> n;
	for(int i = 0; i < n;++i)
	{
		cin >> a[i];
		InsertANode(t,a[i]);
	}
}


void deleteTree(Tree &t)  
{  
    if (t == NULL)
    	return;  
    deleteTree(t->pLeft);  
    deleteTree(t->pRight);  
    cout << "\nDeleting node: " << t->data;  
    delete t; 
} 

int CountNodeTree(Tree &t)
{
	int count = 1;
    if (t->pLeft != NULL) 
    {
       count += CountNodeTree(t->pLeft);
    }
    if (t->pRight != NULL) 
    {
        count += CountNodeTree(t->pRight);
    }
    return count;
}

int CountLeafTree(Tree &t)
{
	int count = 0;
    if (t->pLeft == NULL && t->pRight == NULL) 
    {
        count = 1;
    }
    else 
    {
        if (t->pLeft != NULL) {
            count += CountLeafTree(t->pLeft);
        }
        if (t->pRight != NULL) {
            count += CountLeafTree(t->pRight);
        }
    }
    return count;
}

void PrintLessThanX(Tree t,int x) 
{
	Node* p;
	p = iterativeSearch(t,x);
	NLR(p);
}


int CountLessThanX(Tree &t, int x) 
{ 	
	if (t == NULL) 
	{
		return 0;
	}

	int countingRight = CountLessThanX(t->pRight, x);
	int countingLeft = CountLessThanX(t->pLeft, x);

	if (x > t->data) 
	{
		return (countingLeft + countingRight + 1);
	}
	return (countingLeft + countingRight);
} 

int CountGreaterX(Tree &t,int x)
{
	if (t == NULL)
	{
		return 0;
	}

	int countingRight = CountGreaterX(t->pRight, x);
	int countingLeft = CountGreaterX(t->pLeft, x);

	if (x < t->data) 
	{
		return (countingLeft + countingRight + 1);
	}
	return (countingLeft + countingRight);
}


int CountNodeXY(Tree t, int x, int y)
{
	if (t == NULL)
	{
		return 0;
	}

	int countingRight = CountNodeXY(t->pRight, x,y);
	int countingLeft = CountNodeXY(t->pLeft, x,y);

	if (x < t->data && y > t->data) 
	{
		return (countingLeft + countingRight + 1);
	}
	return (countingLeft + countingRight);
}


int CountEvenNode(Tree t)
{
	if (t == NULL)
	{
		return 0;
	}

	int countingRight = CountEvenNode(t->pRight);
	int countingLeft = CountEvenNode(t->pLeft);

	if (t->data % 2 == 0) 
	{
		return (countingLeft + countingRight + 1);
	}
	return (countingLeft + countingRight);
}


int CountOddNode(Tree t)
{
	if (t == NULL)
	{
		return 0;
	}

	int countingRight = CountOddNode(t->pRight);
	int countingLeft = CountOddNode(t->pLeft);

	if (t->data % 2 != 0) 
	{
		return (countingLeft + countingRight + 1);
	}
	return (countingLeft + countingRight);
}


int SumNodeTree(Tree &t)
{
 	if (t == NULL) 
        return 0; 
    return (t->data + SumNodeTree(t->pLeft) + SumNodeTree(t->pRight));
}


void SumOddNodeTree(Tree t,int &sum)
{
	if (!t) 
        return; 
    if (t->data % 2 != 0) 
        sum += t->data; 
    SumOddNodeTree(t->pLeft, sum); 
    SumOddNodeTree(t->pRight, sum);
}


void SumEvenNodeTree(Tree t,int &sum)
{
	if (!t) 
        return; 
    if (t->data % 2 == 0) 
        sum += t->data; 
    SumEvenNodeTree(t->pLeft, sum); 
    SumEvenNodeTree(t->pRight, sum);
}



int findMax(Tree &t)  
{  
    if(t == NULL)  
    	return -2147483647;  
	int res = t->data; 
	int lres = findMax(t->pLeft); 
	int rres = findMax(t->pRight); 
	if (lres > res) 
		res = lres; 
	if (rres > res) 
		res = rres; 
    return res;  
}  



int findMin(Tree &t) 
{ 
	if(t == NULL) 
		return 2147483647; 
	int res = t->data; 
	int lres = findMin(t->pLeft); 
	int rres = findMin(t->pRight); 
	if (lres < res) 
		res = lres; 
	if (rres < res) 
		res = rres; 
	return res; 
} 


int main()
{
	Tree t;
	CreateTree(t);
	int n = rand() % 11 + 10,x,y,sumOdd = 0,sumEven = 0,choice,choice1,m,x1,y1,x2,y2,x_remain;
	int a[n];
	while(1)
	{
		system("cls");
		cout << "------------MENU----------------\n";
		cout << "1. Insert Node\n";
		cout << "2. NLR, LNR, LRN\n";
		cout << "3. Search Node.\n";
		cout << "4. Delete Node.\n";
		cout << "5. Delete Entrie Node.\n";
		cout << "6. Count all nodes in tree.\n";
		cout << "7. Count all leaves in tree.\n";
		cout << "8. Print remain nodes.\n";
		cout << "9. Count nodes less than x.\n";
		cout << "10. Count nodes greater than x.\n";
		cout << "11. Count nodes greater than x and less than y.\n";
		cout << "12. Compare question 9 & question 10.\n";
		cout << "13. Count even and odd nodes. Compare two counters\n";
		cout << "14. Sum all nodes in tree.\n";
		cout << "15. Sum all even nodes in tree.\n";
		cout << "16. Sum all odd nodes in tree.\n";
		cout << "17. Compare question 15 & question 16.\n";
		cout << "18. Find max and min nodes in tree.\n";
		cout << "Select between 1 and 18 to use the program. Select 0 to exit.\n";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "1. Insert node manually\n";
				cout << "2. Insert node automatically.\n";
				cin >> choice1;
				if(choice1 == 1)
				{
					CreateBruteForceTree(t,m,a);
				}
				else if(choice1 == 2)
				{
					CreateRandomTree(t,n);
				}
				system("pause");
				break;
			case 2:
				cout << "\nNLR:\n\n";
				NLR(t);
				cout << "\nLNR:\n\n";
				LNR(t);
				cout << "\nLRN:\n\n";
				LRN(t);
				system("pause");
				break;
			case 3:
				cout << "\nNhap node can tim:\n";
				cin >> x;
				if(iterativeSearch(t,x) != NULL)
				{
					cout << x << " co trong cay.\n";
				}
				else
				{
					cout << x << " khong co trong cay.\n";
				}
				system("pause");
				break;
			case 4:
				cout << "\nNhap node can xoa:\n";
				cin >> y;
				DeleteSomeNode(t,y);
				cout << "\nDa xoa node " << y << endl;
				system("pause");
				break;
			case 5:
				deleteTree(t);
				system("pause");
				break;
			case 6:
				cout << "\nTong so node tren cay:" << CountNodeTree(t) << endl;
				system("pause");
				break;
			case 7:
				cout << "\nTong so la tren cay: " << CountLeafTree(t) << endl;
				system("pause");
				break;
			case 8:
				cout << "\nNhap so can tim:\n";
				cin >> x_remain;
				cout << "\nCac nut con lai:\n";
				PrintLessThanX(t,x_remain);
				system("pause");
				break;
			case 9:
				cout << "\nNhap gia tri x:\n";
				cin >> x1;
				cout << "\nSo nut nho hon " << x1 << " la: " << CountLessThanX(t,x1) << endl;
				system("pause");
				break;
			case 10:
				cout << "\nNhap gia tri x:\n";
				cin >> x1;
				cout << "\nSo nut lon hon " << x1 << " la: " << CountGreaterX(t,x1) << endl;
				system("pause");
				break;
			case 11:
				cout << "\nNhap gia tri x va y:\n";
				cin >> x2 >> y2;
				cout << "\n So nut lon hon " << x << " va nho hon " << y << " la: " << CountNodeXY(t,x,y) << endl;
				system("pause");
				break;
			case 12:
				if(CountLessThanX(t,x1) > CountGreaterX(t,x1))
				{
					cout << "\nSo nut nho hon " << x1 << " lon hon so nut lon hon " << x1 << endl;
				}
				else if(CountLessThanX(t,x1) < CountGreaterX(t,x1))
				{
					cout << "\nSo nut nho hon " << x1 << " nho hon so nut lon hon " << x1 << endl;
				}
				else
				{
					cout << "\nSo nut nho hon " << x1 << " bang so nut lon hon " << x1 << endl;
				}
				system("pause");
				break;
			case 13:
				cout << "\nSo node le: " << CountOddNode(t) << endl;
				cout << "\nSo node chan: " << CountEvenNode(t) << endl;
				if(CountOddNode(t) > CountEvenNode(t))
				{
					cout << "\nSo nut le nhieu hon so nut chan.\n";
				}
				else if(CountEvenNode(t) > CountOddNode(t))
				{
					cout << "\nSo nut chan nhieu hon so nut le.\n";
				}
				else
				{
					cout << "\nSo nut chan bang so nut le.\n";
				}
				system("pause");
				break;
			case 14:
				cout << "\nTong gia tri so nut tren cay :" << SumNodeTree(t) << endl;
				system("pause");
				break;
			case 15:
				SumEvenNodeTree(t,sumEven);
				cout << "\nTong gia tri so nut chan tren cay: " << sumEven << endl;
				system("pause");
				break;
			case 16:
				SumOddNodeTree(t,sumOdd);
				cout << "\nTong gia tri so nut le tren cay: " << sumOdd << endl;
				system("pause");
				break;
			case 17:
				if(sumEven > sumOdd)
				{
					cout << "\nTong gia tri so nut chan tren cay lon hon tong gia tri so nut le tren cay\n";
				}
				else if (sumEven < sumOdd)
				{
					cout << "\nTong gia tri so nut chan tren cay nho hon tong gia tri so nut le tren cay\n";
				}
				else
				{
					cout << "\nTong gia tri so nut chan tren cay bang tong gia tri so nut le tren cay\n";
				}
				system("pause");
				break;
			case 18:
				cout << "\nGia tri lon nhat trong cay la: " << findMax(t) << endl;
				cout << "\nGia tri nho nhat trong cay la: " << findMin(t) << endl;
				system("pause");
				break;
			if(choice > 18 || choice < 1)
			{
				if(choice == 0)
				{
					cout << "\nGoodbye <3";
					exit(1);
				}
				else
				{
					cout << "\nPlease try again.\n";
					system("pause");
				}	
			}

		}	
	}
	return 0;
}
