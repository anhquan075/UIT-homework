#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

#define M 10

struct Node
{
	int data;
	Node *pNext;
};


struct SingleList
{
	Node *pHead;
	Node *pTail;
};

void Initialize(SingleList &list)
{
	list.pHead = NULL;
	list.pTail = NULL;
}


Node *CreateNode(int d)
{
	Node *pNode = new Node;
	if(pNode != NULL)
	{
		pNode->data = d;
		pNode->pNext = NULL;
	}else
	{
		cout << "\nError allocating node!"  << endl;
		exit(1);
	}
	return pNode;
}

void AddHead(SingleList &list,Node *pNode)
{
	if(list.pHead == NULL)
	{
	   list.pHead = list.pTail = pNode;
    }
    else 
    {
       pNode->pNext = list.pHead;
       list.pHead = pNode;
    }
}


void AddTail(SingleList &list,Node *pNode)
{
	if(list.pHead == NULL)
    {
    	list.pHead = list.pTail = pNode;
    }
    else 
    {
       list.pTail->pNext = pNode;
       list.pTail = pNode;
    }
}

void printLinkedList(SingleList &list)
{
	for(Node *pTemp = list.pHead;pTemp != NULL;pTemp = pTemp->pNext)
	{
		cout << pTemp->data << " ";
	}
	cout << endl;
}


int hashFunction(int data)
{
	return data % M;
}

void InitBucket(SingleList Bucket[])
{
	for(int i = 0; i < M; ++i)
	{
		Initialize(Bucket[i]);
	}
}

void printBucket(SingleList Bucket[])
{
	for(int i = 0; i < M; ++i)
	{
		cout << i << ". ";
		printLinkedList(Bucket[i]);
	}
}

void insertBucketDirect(SingleList Bucket[],int data)
{
	int b = hashFunction(data);
	AddTail(Bucket[b],CreateNode(data));
}

void insertBucketLinear(SingleList Bucket[],int data)
{
	int index = hashFunction(data);
    while(Bucket[index].pHead != NULL && Bucket[index].pHead->data != data && Bucket[index].pHead->data != -1)
        index = (index + 1) % M;
    AddTail(Bucket[index],CreateNode(data));
}

void insertBucketQuadratic(SingleList Bucket[],int data)
{
	int index = hashFunction(data);
	int base = index;
	int step = 0;
    while(Bucket[index].pHead != NULL && Bucket[index].pHead->data != data && Bucket[index].pHead->data != -1)
    {
    	step++;
    	index = (base + step*step) % M;
    }    
    AddTail(Bucket[index],CreateNode(data));	
}


void insertDoubleHasing(SingleList Bucket[],int data)
{
	int index = hashFunction(data),sec = (M - 2) - data % (M - 2);
	int base = index,step = 0;
	while(Bucket[index].pHead != NULL && Bucket[index].pHead->data != data)
    {
    	step++;
    	index = (base + sec*step) % M;
    }
    AddTail(Bucket[index],CreateNode(data));
}



Node *SearchNodeDirect(SingleList Bucket[],int data)
{
	int iBucket = hashFunction(data);
	Node *pTemp = Bucket[iBucket].pHead;
	while(pTemp != NULL)
	{
		if(pTemp->data == data)
			return pTemp;
		pTemp = pTemp->pNext;
	}
	return NULL;
}	


Node *SearchNodeLinear(SingleList Bucket[],int data)
{
	int iBucket = hashFunction(data);
	int step = 0,base = iBucket;
	while(1)
	{
		if(Bucket[iBucket].pHead == NULL)
		{
			return NULL;
			break;
		}
		else if(Bucket[iBucket].pHead->data == data)
		{
			return Bucket[iBucket].pHead;
			break;
		}
		else
		{
			step++;
			iBucket = (base + step*1) % M;
		}
	}
	return NULL;
}


Node *SearchNodeQuadratic(SingleList Bucket[],int data)
{
	int iBucket = hashFunction(data);
	int step = 0,base = iBucket;
	while(1)
	{
		if(Bucket[iBucket].pHead == NULL)
		{
			return NULL;
			break;
		}
		else if(Bucket[iBucket].pHead->data == data)
		{
			return Bucket[iBucket].pHead;
			break;
		}
		else
		{
			step++;
			iBucket = (base + step*step) % M;
		}
	}
	return NULL;	
}

Node *SearchDoubleHasing(SingleList Bucket[],int data)
{
	int iBucket = hashFunction(data);
	int sec = (M - 2) - data % (M - 2);
	int base = iBucket,step = 0;
	while(1)
	{
		if(Bucket[iBucket].pHead == NULL)
		{
			return NULL;
			break;
		}
		else if(Bucket[iBucket].pHead->data == data)
		{
			return Bucket[iBucket].pHead;
			break;
		}
		else
		{
			step++;
			iBucket = (base + step*sec) % M;
		}
	}
	return NULL;		
}

int RemoveHead(SingleList &list, int &x)
{
	Node *p;
	if(list.pHead != NULL)
	{ 
		p = list.pHead;
		x = p->data; 
		list.pHead = list.pHead->pNext;
		delete p;
		if(list.pHead==NULL)
			list.pTail=NULL;
		return 1;
	}
	return 0;
}

int DeleteAfterQ(SingleList &list,Node *q, int x)
{ 
	Node *p;
	if( q != NULL)
	{ 
		p = q->pNext; 
		if(p != NULL) 
		{ 
			if(p == list.pTail) 
				list.pTail = q;
			q->pNext=p->pNext;
			x = p->data;
			delete p;
		}
		return 1;
	}
	return 0;
}

bool RemoveDirect(SingleList Bucket[],int x)
{ 
	Node *p,*q = NULL; 
	int iBucket = hashFunction(x);
	p = Bucket[iBucket].pHead;
	while((p != NULL) && (p->data != x)) 
	{ 
		q = p;
		p = p->pNext;
	}
	if( p == NULL) 
		return 0;
	if(q != NULL)
		DeleteAfterQ(Bucket[iBucket],q,x);
	else 
		RemoveHead(Bucket[iBucket],x);
	return 1;
}

bool RemoveLinear(SingleList Bucket[],int x)
{
	int step = 0,index = hashFunction(x);
	int base = index;
	while(1)
	{
		if(Bucket[index].pHead == NULL)
		{
			return 0;
			break;
		}
		else if(Bucket[index].pHead->data == x)
		{
			RemoveHead(Bucket[index],x);
			break;
		}
		else
		{
			step++;
			index = (base + step*1) % M;
		}
	}	
	return 1;
}

bool RemoveQuadratic(SingleList Bucket[],int x)
{
	int step = 0,index = hashFunction(x);
	int base = index;
	while(1)
	{
		if(Bucket[index].pHead == NULL)
		{
			return 0;
			break;
		}
		else if(Bucket[index].pHead->data == x)
		{
			RemoveHead(Bucket[index],x);
			break;
		}
		else
		{
			step++;
			index = (base + step*step) % M;
		}
	}
	return 1;
}

bool RemoveDouble(SingleList Bucket[],int x)
{
	int index = hashFunction(x);
	int sec = (M - 2) - x % (M - 2);
	int base = index,step = 0;
	while(1)
	{
		if(Bucket[index].pHead == NULL)
		{
			return 0;
			break;
		}
		else if(Bucket[index].pHead->data == x)
		{
			RemoveHead(Bucket[index],x);
			break;
		}
		else
		{
			step++;
			index = (base + step*sec) % M;
		}		
	}	
	return 1;
}

void CreatingTable(SingleList Bucket[],int a[],int n,int vec,int test)
{
	if(vec == 1 && test == 1)
	{
		cout << "\nInput array:" << endl;
		for(int i = 0;i < n; ++i)
		{
			cin >> a[i];
			insertBucketDirect(Bucket,a[i]);
		}
	}
	else if (vec == 2 && test == 1)
	{
		for(int i = 0;i < n; ++i)
		{
			insertBucketDirect(Bucket,rand() % 90 + 10);
		}
		cout << "\nDone\n";
	}
	else if(vec == 1 && test == 2)
	{
		cout << "\nInput array:" << endl;
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
			insertBucketLinear(Bucket,a[i]);
		}
	}
	else if(vec == 2 && test == 2)
	{
		for(int i = 0;i < n; ++i)
		{
			insertBucketLinear(Bucket,rand() % 90 + 10);
		}		
		cout << "\nDone\n";
	}
	else if(vec == 1 && test == 3)
	{
		cout << "\nInput array:" << endl;
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
			insertBucketQuadratic(Bucket,a[i]);
		}
	}
	else if(vec == 2 && test == 3)
	{
		for(int i = 0;i < n; ++i)
		{
			insertBucketQuadratic(Bucket,rand() % 90 + 10);
		}		
		cout << "\nDone\n";
	}
	else if(vec == 1 && test == 4)
	{
		cout << "\nInput array:" << endl;
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
			insertDoubleHasing(Bucket,a[i]);
		}
	}
	else if(vec == 2 && test == 4)
	{
		for(int i = 0;i < n; ++i)
		{
			insertDoubleHasing(Bucket,rand() % 90 + 10);
		}		
		cout << "\nDone\n";		
	}
}



void MainMenu(int &choice)
{
	cout << "1. Direct chaining" << endl;
	cout << "2. Linear probing" << endl;
	cout << "3. Quadratic probing" << endl;
	cout << "4. Double hashing" << endl;
	cout << "Choice 0 to exit" << endl;
	cin >> choice;
	if(choice > 4 || choice < 1)
	{
		if(choice == 0)
		{
			cout << "\nGood bye <3\n";
			exit(1);
		}
		else
		{
			cout << "\nPlease try again." << endl;
			system("pause");				
		}
	}		
}

void Menu(int &choice)
{
	cout << "1. Manually input" << endl;
	cout << "2. Automatically input." << endl;
	cout << "3. Output." << endl;
	cout << "4. Delete a value." << endl;
	cout << "5. Search a value." << endl;
	cout << "Choose 0 to back the main menu." << endl;
	cin >> choice;
}

SingleList Bucket1[M],Bucket2[M],Bucket3[M],Bucket4[M];

int main()
{
	int m = rand() % 6 + 5;
	int choice,choice1,choice2,choice3,choice4;
	int n,x1,x2,x3,x4;
	int y1,y2,y3,y4;
	int a[100],b[100],c[100],d[100];
	InitBucket(Bucket1);
	InitBucket(Bucket2);
	InitBucket(Bucket3);
	InitBucket(Bucket4);
	while(1)
	{
		system("cls");
		label:
			MainMenu(choice);
		if(choice == 1)
		{
			system("cls");
			while(1)
			{
				system("cls");
				Menu(choice1);
				switch (choice1)
				{
					case 1:
						cout << "\nInput n:";
						cin >> n;
						CreatingTable(Bucket1,a,n,1,1);
						system("pause");
						break;
					case 2:
						CreatingTable(Bucket1,a,m,2,1);
						system("pause");
						break;
					case 3:
						printBucket(Bucket1);
						system("pause");
						break;
						case 4:
						cout << "\nValue needed to delete:\n";
						cin >> x1;
						if(RemoveDirect(Bucket1,x1))
							cout << x1 << " has been removed frome the bucket.\n";
						else
							cout << x1 << " has not been removed from the bucket.\n";
						system("pause");
						break;
					case 5:
						cout << "\nNeeded value to search for:\n";
						cin >> y1;
						if(SearchNodeDirect(Bucket1,y1) != NULL)
							cout << y1 << " has been found in the bucket.\n";
						else
							cout << y1 << " has not been found in the bucket.\n";
						system("pause");
						break;
					}
					if(choice1 > 5 || choice1 < 1)
					{
						if(choice1 == 0)
						{
							system("cls");
							goto label;
						}
						else
						{
							cout << "\nPlease try again." << endl;
							system("pause");							
						}
					}					
				}			
		}
		else if(choice == 2)
		{
			system("cls");
			while(1)
			{
				system("cls");
				Menu(choice2);
				switch (choice2)
				{
					case 1:
						cout << "\nInput n:";
						cin >> n;
						CreatingTable(Bucket2,b,n,1,2);
						system("pause");
						break;
					case 2:
						CreatingTable(Bucket2,b,m,2,2);
						system("pause");
						break;
					case 3:
						printBucket(Bucket2);
						system("pause");
						break;
					case 4:
						cout << "\nValue needed to delete:\n";
						cin >> x2;
						if(RemoveLinear(Bucket2,x2))
							cout << x2 << " has been removed frome the bucket.\n";
						else
							cout << x2 << " has not been removed from the bucket.\n";
						system("pause");
						break;
					case 5:
						cout << "\nNeeded value to search for:\n";
						cin >> y2;
						if(SearchNodeLinear(Bucket2,y2) != NULL)
							cout << y2 << " has been found in the bucket.\n";
						else
							cout << y2 << " has not been found in the bucket.\n";
						system("pause");
						break;
				}
				if(choice2 > 5 || choice2 < 1)
				{
					if(choice2 == 0)
					{
						system("cls");
						goto label;
					}
					else
					{
						cout << "\nPlease try again." << endl;
						system("pause");
					}	
				}					
			}	
		}
		else if (choice == 3)	
		{
			system("cls");
			while(1)
			{
				system("cls");
				Menu(choice3);
				switch (choice3)
				{
					case 1:
						cout << "\nInput n:";
						cin >> n;
						CreatingTable(Bucket3,c,n,1,3);
						system("pause");
						break;
					case 2:
						CreatingTable(Bucket3,c,m,2,3);
						system("pause");
						break;
					case 3:
						printBucket(Bucket3);
						system("pause");
						break;
					case 4:
						cout << "\nValue needed to delete:\n";
						cin >> x3;
						if(RemoveQuadratic(Bucket3,x3))
							cout << x3 << " has been removed frome the bucket.\n";
						else
							cout << x3 << " has not been removed from the bucket.\n";
						system("pause");
						break;
					case 5:
						cout << "\nNeeded value to search for:\n";
						cin >> y3;
						if(SearchNodeQuadratic(Bucket3,y3) != NULL)
							cout << y3 << " has been found in the bucket.\n";
						else
							cout << y3 << " has not been found in the bucket.\n";
						system("pause");
						break;
					}
				if(choice3 > 5 || choice3 < 1)
				{
					if(choice3 == 0)
					{
						system("cls");
						goto label;
					}
					else
					{
						cout << "\nPlease try again." << endl;
						system("pause");
					}	
				}					
			}
		}
		else if(choice == 4)
		{
			system("cls");
			while(1)
			{
				system("cls");
				Menu(choice4);
				switch (choice4)
				{
					case 1:
						cout << "\nInput n:";
						cin >> n;
						CreatingTable(Bucket4,d,n,1,4);
						system("pause");
						break;
					case 2:
						CreatingTable(Bucket4,d,m,2,4);
						system("pause");
						break;
					case 3:
						printBucket(Bucket4);
						system("pause");
						break;
					case 4:
						cout << "\nValue needed to delete:\n";
						cin >> x4;
						if(RemoveDouble(Bucket4,x4))
							cout << x4 << " has been removed frome the bucket.\n";
						else
							cout << x4 << " has not been removed from the bucket.\n";
						system("pause");
						break;
					case 5:
						cout << "\nNeeded value to search for:\n";
						cin >> y4;
						if(SearchNodeQuadratic(Bucket4,y4) != NULL)
							cout << y4 << " has been found in the bucket.\n";
						else
							cout << y4 << " has not been found in the bucket.\n";
						system("pause");
						break;
					}
				if(choice4 > 5 || choice4 < 1)
				{
					if(choice4 == 0)
					{
						system("cls");
						goto label;
					}
					else
					{
						cout << "\nPlease try again." << endl;
						system("pause");
					}	
				}					
			}
		}				
	}
	return 0;
}