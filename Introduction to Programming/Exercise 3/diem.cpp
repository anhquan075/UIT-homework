#include <iostream>
#include <math.h>

using namespace std;

struct toadodiem
{
	int hoanhdo;
	int tungdo;
};


void nhaptoado(toadodiem &td)
{
	cout<<"Nhap tung do:";
	cin>>td.tungdo;
	cout<<"Nhap hoanh do:";
	cin>>td.hoanhdo;
}


void xuattoado(toadodiem &td)
{
	cout<<"Toa do cua diem la: ("<<td.hoanhdo<<","<<td.tungdo<<")"<<endl;
}

void nhapndiem(toadodiem dt[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap toa do thu "<<i+1<<" la:\n";
		nhaptoado(dt[i]);
	}
}

void xuatndiem(toadodiem dt[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nToa do diem thu "<<i+1<<" :\n";
		xuattoado(dt[i]);
	}
}


int demsodiemcohoangdoduong(toadodiem dt[],int n)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(dt[i].hoanhdo>0)
			count++;
	}
	return count;
}


int demsodiemkhongtrung(toadodiem dt[],int n)
{
	int count = 0;
	for(int i = 0; i < n-1; i++)
	{
		for(int j = i + 1;j < n;j++)
		{
			if(dt[i].tungdo != dt[j].tungdo && dt[i].hoanhdo != dt[j].hoanhdo)
				count++;
		}
	}
	return count;
}


void diemcohoangdoMax(toadodiem dt[],int n)
{
	int max = dt[0].hoanhdo;
	for(int i=0;i<n;i++)
	{
		if(dt[i].hoanhdo > max)
			max = dt[i].hoanhdo;
	}
	for(int i=0;i<n;i++)
	{
		if(max == dt[i].hoanhdo)
			cout<<"Diem co hoanh do lon nhat la: ("<<dt[i].hoanhdo<<","<<dt[i].tungdo<<")"<<endl;
	}
}

void diemcohoangdoMin(toadodiem dt[],int n)
{
	int min = dt[0].hoanhdo;
	for(int i=0;i <n;i++)
	{
		if(dt[i].hoanhdo< min)
			min = dt[i].hoanhdo;
	}
	for(int i=0;i<n;i++)
	{
		if(min == dt[i].hoanhdo)
			cout<<"Diem co hoanh do nho nhat la: ("<<dt[i].hoanhdo<<","<<dt[i].tungdo<<")"<<endl;
	}
}


void diemgangoctoado(toadodiem dt[],int n)
{
	float mindistance = sqrt(pow((float)(dt[0].hoanhdo),2)+pow((float)(dt[0].tungdo),2));
	for(int i = 0;i < n;i++)
	{
		if(sqrt(pow((float)(dt[i].hoanhdo),2)+pow((float)(dt[i].tungdo),2)) < mindistance)
			mindistance = sqrt(pow((float)(dt[i].hoanhdo),2)+pow((float)(dt[i].tungdo),2));
	}
	for(int i = 0;i < n;i++)
	{
		if(mindistance == sqrt(pow((float)(dt[i].hoanhdo),2)+pow((float)(dt[i].tungdo),2)))
			cout<<"Diem gan goc toa do nhat la: ("<<dt[i].tungdo<<","<<dt[i].hoanhdo<<")"<<endl;
	}
}


int main()
{
	toadodiem dt[100],td;
	int n;
	cout<<"Nhap so luong toa do can nhap: ";
	cin>>n;
	nhapndiem(dt,n);
	xuatndiem(dt,n);
	cout<<"\nSo diem co hoang do duong la: "<<demsodiemcohoangdoduong(dt,n)<<endl;
	cout<<"So diem khong khong trung voi cac diem khac la: "<<demsodiemkhongtrung(dt,n)<<endl;
	diemcohoangdoMax(dt,n);
	diemcohoangdoMin(dt,n);
	diemgangoctoado(dt,n);
	return 0;
}