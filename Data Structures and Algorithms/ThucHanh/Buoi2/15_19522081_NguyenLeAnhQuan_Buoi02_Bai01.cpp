/// STT:15
/// Họ và tên: Nguyễn Lê Anh QUân
/// Buổi 02 - Bài 01



#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;



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
		cout << "Error allocating node!"  << endl;
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


void AddNPositions(SingleList &list,int pos,int d)
{
	Node *p,*q,*pTemp;
	int n = 0;
	for (pTemp = list.pHead; pTemp != NULL; pTemp = pTemp->pNext)
	{
		n++;
	}
	if(pos < 0 || pos >= n)
		cout << "Invalid position " << endl;
	if(pos == 0)
	{
		p = CreateNode(d);
		AddHead(list,p);
	}
	if(pos == n - 1)
	{
		p = CreateNode(d);
		AddTail(list,p);
	}
	else
	{
		p = CreateNode(d);
		pTemp = list.pHead;
		q = NULL;
		int i = 0;
		while(pTemp != NULL)
		{
			if(i == pos)
				break;
			q = pTemp;
			pTemp = pTemp->pNext;
			i++;
		}
		q->pNext = p;
		p->pNext = pTemp;
	}
}

void FreeMemory(SingleList &list)
{
	while(list.pHead != NULL)
	{
		Node *pTemp = list.pHead;
		list.pHead = pTemp->pNext;
		pTemp->pNext = NULL;
		delete pTemp;
		pTemp = NULL;
	}
}

int findPosNode(SingleList list, int x)
{
    int position = 0;
    for(Node *p = list.pHead; p != NULL; p = p->pNext){
        if(p->data == x)
        {
            return position;
        }
        ++position;
    }
    return -1;
}

Node *SearchNode(SingleList &list,int d)
{
	Node *pTemp = list.pHead;
	while(pTemp != NULL)
	{
		if(pTemp->data == d)
			break;
		pTemp = pTemp->pNext;
	}
	return pTemp;
}


void Input(SingleList &list)
{
	int n;
	cin >> n;
	for(int i = 0; i < n;++i)
	{
		int d;
		cin >> d;
		Node *pNode = CreateNode(d);
		AddTail(list,pNode);
	}
}

void AutoInput(SingleList &list)
{
	srand(time(NULL));
	int n = rand() % 21 + 39;
	for(int i = 0; i < n; i++)
	{
		int d = rand() % 199 - 99;
		Node *pNode = CreateNode(d);
		AddTail(list,pNode);
	}
}

void Output(SingleList &list)
{
	Node *pTemp = list.pHead;
	if(pTemp == NULL)
	{
		cout << "This list is empty!\n";
		return;
	}
	cout << "List is: ";
	while(pTemp != NULL)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->pNext;
	}
	cout << endl;
}

void OutputAddress(SingleList &list)
{
	Node *pTemp = list.pHead;
	if(pTemp == NULL)
	{
		cout << "This list is empty!\n";
		return;
	}
	cout << "\nList is: ";
	while(pTemp != NULL)
	{
		cout << pTemp->data << " " << " <" << pTemp->pNext << ">" << " ";
		pTemp = pTemp->pNext;
	}
	cout << endl;
}

int RemoveHead(SingleList list, int &x)
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

int DeleteAfterQ(SingleList list,Node *q, int &x)
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

bool RemoveX(SingleList list, int &x)
{ 
	Node *p,*q = NULL; 
	p = list.pHead;
	while((p != NULL) && (p->data != x)) //tìm
	{ 
		q = p;
		p = p->pNext;
	}
	if( p == NULL) 
		return 0;
	if(q != NULL)
		DeleteAfterQ(list,q,x);
	else 
		RemoveHead(list,x);
	return 1;
}

int main()
{
	SingleList list;
	int x1,x2,x3,x4,x5,x6,choice,choice1;
	Initialize(list);
	while(1)
	{
		system("cls");
		cout <<"Cau 1\n";
		cout <<"Cau 2\n";
		cout <<"Cau 3\n";
		cout <<"Cau 4\n";
		cout <<"Cau 5\n";
		cout <<"Cau 6\n";
		cout <<"Cau 7\n";
		cout <<"Cau 8\n";
		cout <<"Nhap 0 de thoat khoi chuong trinh\n";
		cout <<"Vui long chon cau can su dung:";
		cin >> choice;
		switch(choice)
		{
			case 1:
				do
				{
					cout <<"\nChon cach tao danh sach lien ket:\nNhan 1 de chon cach thu cong\nNhan 2 de chon cach tu dong\n";
					cin >> choice1;
					if(choice1 < 1 || choice1 > 2)
						cout << "Vui long nhap lai!\n";
				}while(choice1 < 1 || choice1 > 2);
				if(choice1 == 1)
				{
					cout << "Nhap so luong phan tu:\n\n";
					Input(list);
					break;
				}
				else
				{
					AutoInput(list);
					break;
				}
			case 2:
				cout << "\nNhap phan tu vao dau danh sach:\n";
				cin >> x3;
				AddHead(list, CreateNode(x3));
				system("pause");
				break;
			case 3:
				cout << "\nNhap phan tu vao cuoi danh sach:\n";
				cin >> x4;
				AddTail(list, CreateNode(x4));
				system("pause");
				break;
			case 4:
				Output(list);
				system("pause");
				break;
			case 5:
				OutputAddress(list);
				system("pause");
				break;
			case 6:
				cout << "\nNhap so x can tim:\n";
				cin >> x1;
				if(findPosNode(list,x1) == -1)
					cout << "\nGia tri khong co trong list\n";
				else
					cout << "Gia tri "<< x1 << " tai vi tri thu "<< findPosNode(list,x1) + 1 <<" trong list\n" << endl;
				system("pause");
				break;
			case 7:
				cout << "\nNhap so x can xoa:\n";
				cin >> x2;
				if(RemoveX(list, x2) == 0)
					cout << "\nKhong co phan tu can xoa";
				else
				{
					cout << "\nDa xoa phan tu can xoa\n";
				}
				system("pause");
				break;
			case 8:
				cout << "\nNhap so x muon sua:\n";
				cin >> x5;
				if(findPosNode(list,x5) == -1)
					cout << "\nGia tri khong co trong list,khong the sua!\n";
				else
				{
					int pos = findPosNode(list,x5);
					cout <<"\nNhap so x can sua:\n";
					cin >> x6;
					AddNPositions(list,pos ,x6);
					RemoveX(list,x5);
				}
				system("pause");
				break;
		}
		if(choice > 8 || choice < 1)
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
	return 0;
}