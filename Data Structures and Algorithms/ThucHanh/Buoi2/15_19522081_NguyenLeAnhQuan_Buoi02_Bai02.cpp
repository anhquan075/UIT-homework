/// STT:15
/// Họ và tên: Nguyễn Lê Anh QUân
/// Buổi 02 - Bài 02





#include <iostream>
#include <time.h>
#include <string.h>
#include <string>
#include <algorithm>

const int MAX_SIZE = 26;

using namespace std;

struct SinhVien
{
	string name;
	float GPA;
};


struct Node
{
	SinhVien data;
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

Node *CreateNode(SinhVien d)
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

int findPosNode(SingleList list,SinhVien x)
{
    int position = 0;
    for(Node *p = list.pHead; p != NULL; p = p->pNext){
        if(p->data.name == x.name && p->data.GPA == x.GPA)
        {
            return position;
        }
        ++position;
    }
    return -1;
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

void AddNPositions(SingleList &list,int pos,SinhVien d)
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

void Input(SingleList &list)
{
	int n;
	cin >> n;
	for(int i = 0; i < n;++i)
	{
		SinhVien d;
		cin.ignore();
		getline(cin,d.name);
		cin >> d.GPA;
		Node *pNode = CreateNode(d);
		AddTail(list,pNode);
	}
}


string printstring(int n)
{
	char letters[MAX_SIZE] = {'a','b','c','d','e','f','g',
								'h','i','j','k','l','m','n','o','p','q',
								'r','s','t','u','v','w','x','y','z'};
	string ran = "";
	for (int i = 0;i < n;++i) 
		ran = ran + letters[rand() % MAX_SIZE];
	return ran;
}

float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}


void AutoInput(SingleList &list)
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		SinhVien d;
        d.name = printstring(rand() % 50);
        d.GPA = float_rand(0,10);
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
	cout << "List is:\n";
	while(pTemp != NULL)
	{
		SinhVien sv = pTemp->data;
		cout << "Ten sv: " <<sv.name << " | Diem GPA: " << sv.GPA<< " " << endl;
		pTemp = pTemp->pNext;
	}
	cout << endl;
}


void Sorting(SingleList &list)
{
	for(Node *pNode = list.pHead;pNode->pNext != NULL;pNode = pNode->pNext)
	{
		for(Node *qNode = pNode->pNext;qNode != NULL;qNode = qNode->pNext)
		{
			if(pNode->data.GPA > qNode->data.GPA)
			{
				swap(pNode->data,qNode->data);
			}
		}
	}
}


void DeleteHeadNode(SingleList& l)
{
	if (l.pHead == NULL)
		return;
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void DeleteTailNode(SingleList& l)
{
	if (l.pHead == NULL)
		return;
	if (l.pHead->pNext== NULL)
	{
		DeleteHeadNode(l);
	}
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (l.pTail == k->pNext)
		{
			delete l.pTail;
			k->pNext= NULL;
			l.pTail = k;
		}
	}
}
void DeleteNode(SingleList& l)
{
	string x;
	cout << "\nNhap ten muon xoa: ";
	cin.ignore();
    getline(cin,x);
	if (l.pHead->data.name == x)
		DeleteHeadNode(l);
	else if (l.pTail->data.name == x)
		DeleteTailNode(l);
	else
	{
		Node* g = new Node;
		for (Node* k = l.pHead; k != NULL; k = k->pNext)
		{
			if (k->data.name == x)				
			{
				g->pNext= k->pNext;
				delete k;
				return;

			}
			g = k;
		}
	}
}

int RemoveHead(SingleList list, SinhVien &x)
{
	Node *p;
	if(list.pHead != NULL)
	{ 
		p = list.pHead;
		x.name = p->data.name;
		x.GPA = p->data.GPA; 
		list.pHead = list.pHead->pNext;
		delete p;
		if(list.pHead==NULL)
			list.pTail=NULL;
		return 1;
	}
	return 0;
}

int DeleteAfterQ(SingleList list,Node *q, SinhVien &x)
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

bool RemoveX(SingleList list, SinhVien &x)
{ 
	Node *p,*q = NULL; 
	p = list.pHead;
	while((p != NULL) && (p->data.name != x.name && p->data.GPA != x.GPA)) 
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

void findWName(SingleList &List)
{
    Node *p;
    int dem = 0;
    string k;
    cout << "\nNhap ten sinh vien can tim:\n";
    cin.ignore();
    getline(cin,k);
    p = List.pHead;
    while (p != NULL)
    {
        if(k == p->data.name)      
        	dem++;
        p = p->pNext;
    }
    if(dem!=0)
    {
            cout <<"\nTim thay sinh vien\n";
    }
    else 
    	cout << "\nKhong tim thay!";
}


void findWGPA(SingleList &List)
{
	Node *p;
    int dem = 0;
    int k;
    cout << "\nNhap diem sinh vien can tim:\n";
    cin >> k;
    p = List.pHead;
    while (p != NULL)
    {
        if(k == p->data.GPA)      
        	dem++;
        p = p->pNext;
    }
    if(dem != 0)
    {
            cout <<"\nTim thay sinh vien\n";
    }
    else 
    	cout << "\nKhong tim thay!";
}


int main()
{
	SingleList list;
	SinhVien x5,x6;
	int choice,choice1,choice2;
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
				if(list .pHead == NULL)
				{
					cout <<"\nList rong, vui long them thanh phan vao danh sach\n";
					system("pause");
					break;
				}	
				else
				{	Sorting(list);
					cout << "\nDa sap xep danh sach\n";
					system("pause");
					break;
				}
			case 3:
				do
				{
					cout <<"\n\nNhan 1 de chon tim theo ten\nNhan 2 de chon tim theo diem\n";
					cin >> choice2;
					if(choice2 < 1 || choice2 > 2)
						cout << "Vui long nhap lai!\n";
				}while(choice2 < 1 || choice2 > 2);
				if(choice2 == 1)
				{
					findWName(list);
					system("pause");
					break;
				}
				else
				{
					findWGPA(list);
					system("pause");
					break;
				}			
				system("pause");
			case 4:
				DeleteNode(list);
				system("pause"); 
				break;
			case 5:
				cout << "\nNhap ten can sua:\n";
				cin.ignore();
    			getline(cin,x5.name);
    			cout << "\nNhap diem GPA can sua:\n";
    			cin >> x5.GPA;
    			if(findPosNode(list,x5) == -1)
    			{
    				cout << "\nSinh vien khong co trong danh sach\n";
    			}
    			else
    			{
    				int pos = findPosNode(list,x5);
    				cout <<"\nNhap ten muon sua:\n";
    				cin.ignore();
    				getline(cin,x6.name);
    				cout << "\nNhap diem GPA can sua:\n";
    				cin >> x6.GPA;
    				AddNPositions(list,pos ,x6);
					RemoveX(list,x5);
    			}
				system("pause");
				break;
			case 6:
				Output(list);
				system("pause");
				break;
		}
		if(choice > 6 || choice < 1)
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