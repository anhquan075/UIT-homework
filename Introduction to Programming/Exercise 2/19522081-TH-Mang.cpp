#include <iostream>
#include <math.h>

using namespace std;

int nhapmang(int a[],int &n)
{
	cout<<"Nhap kich thuoc mang: ";
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"]= ";
		cin>>a[i];
	}
	return 0;
}


int xuatmang(int a[],int &n)
{
	cout<<"Cac phan tu la:\n";
	for (int i=0;i<n;i++)
		{
			cout<<" "<<a[i]<<endl;
		}
	return 0;
}

void xoaphantu(int a[], int &n, int pos)
{
	cout<<"Nhap vi tri can xoa phan tu: ";
	cin>>pos;
    if(n <= 0)
    {
        return;
    }
    if(pos < 0)
    {
        pos = 0;
    }
    else if(pos >= n)
    {
        pos = n-1;
    }
    for(int i = pos-1; i < n - 1; i++)
    {
        a[i] = a[i+1];
    }
    --n;
}

int demsoam(int a[],int &n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			dem++;
		}
	}
	if(dem>0)
	{
		cout<<"Cac so am co trong mang la: "<<dem<<endl;
	}else
	{
		cout<<"Mang vua nhap khong co so am !!"<<endl;
	}
	return 0;
}

int maxandmin(int a[],int &n)
{
	int max=a[0],min=a[0];
	for (int i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	cout<<"Phan tu lon nhat co trong mang la: "<<max<<endl;
	for (int i=0;i<n;i++)
	{
		if(min>a[i])
		{
			min=a[i];
		}
	}
	cout<<"Phan tu nho nhat co trong mang la: "<<min<<endl;
	return 0;
}


int maxam(int a[],int &n)
{
	int maxam=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			if(maxam<a[i])
			{
				maxam=a[i];
			}
		}
	}
	if(maxam<0)
		{
			cout<<"So nguyen am lon nhat cua mang: "<<maxam<<endl;
		}
		else
		{
			cout<<"Mang khong co so nguyen am de thuc hien !!."<<endl;
		}
	return 0;
}


int minduong(int a[],int &n)
{
	int minduong=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		{
			if(minduong>a[i])
			{
				minduong=a[i];
			}
		}
	}
	if(minduong>0)
	{
		cout<<"So nguyen duong nho nhat cua mang: "<<minduong<<endl;
	}
	else
	{
		cout<<"Mang khong co so nguyen duong de thuc hien !!.";
	}
	return 0;
}

int demsophantutrongmang(int a[],int &n,int &pos)
{
	int dem = 0;
	cout<<"\nPhan tu can tim trong mang: ";
	cin>>pos;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == pos)
		{
			dem++;
		}
	}
	cout<<"So luong phan tu can tim trong mang la: "<<dem<<endl;
	return dem;
}

int demcacsochiahetcho3(int a[],int &n)
{
	int dem = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] % 3 == 0)
			dem++;
	}
	cout<<"So luong cac so chia het cho 3 la: "<<dem<<endl;
	return dem;
}


bool snt(int a)
{
    if(a < 2) 
    	return false;
    for(int i = 2; i <= sqrt(a); ++i)
    {
        if(a % i == 0) 
        	return false;
    }
    return true;
}

int demsnt(int a[],int &n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(snt(a[i]) == 1)
			dem++;
	}
	cout<<dem;
	return dem;
}


int tangdan(int a[],int &n)
{
	int tg;
	for(int i = 0; i < n - 1; i++)
	{
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
    return 0;
}


int giamdan(int a[],int &n)
{
	int tg;
	for(int i = 0; i < n - 1; i++)
	{
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
    return 0;
}

int main()
{
	char tieptuc,n,y,N,Y;
	do
	{
	int luachon;
	int a[50],n,pos;
	cout<<"****************************************************\n";
	cout<<"      Chao mung ban den voi chuong trinh!!\n";
	cout<<"   		Minh la Anh Quan ";
	cout<<"		 \nVui long chon chuc nang ban muon:";
	cout<<"\n1. Nhap va xuat mang. ";
	cout<<"\n2. Xoa phan tu tai vi tri tuy chon.";
	cout<<"\n3. Tim phan tu lon nhat hoac nho nhat trong mang.";
	cout<<"\n4. Dem luong so am co trong mang. ";
	cout<<"\n5. Tim so am lon nhat trong mang.";
	cout<<"\n6. Tim so duong nho nhat trong mang.";
	cout<<"\n7. Tim phan tu tuy chon trong mang.";
	cout<<"\n8. Tim so luong so chia het cho 3 trong mang.";
	cout<<"\n9. Tim so luong so nguyen to trong mang";
	cout<<"\n10. Sap xep cac phan tu trong mang giam dan.";
	cout<<"\n11. sap xep cac phan tu trong mang tang dan.";
	cout<<"\n12. Quay lai menu chuong trinh.";
	cout<<"\n13. Thoat chuong trinh.";
	cout<<"\nNhap cac so 1-13 de thuc hien chuc nang: ";
	cin>>luachon;
	switch(luachon)
	{
		case 1:
			nhapmang(a,n);
			xuatmang(a,n);
			break;
		case 2:
			nhapmang(a,n);
			xoaphantu(a,n,pos);
			xuatmang(a,n);
			break;
		case 3:
			nhapmang(a,n);
			maxandmin(a,n);
			break;
		case 4:
			nhapmang(a,n);
			demsoam(a,n);
			break;
		case 5:
			nhapmang(a,n);
			maxam(a,n);
			break;
		case 6:
			nhapmang(a,n);
			minduong(a,n);
			break;
		case 7:
			nhapmang(a,n);
			demsophantutrongmang(a,n,pos);
			break;
		case 8:
			nhapmang(a,n);
			demcacsochiahetcho3(a,n);
			break;
		case 9:
			nhapmang(a,n);
			cout<<"So luong cac so nguyen to la: ";
			demsnt(a,n);
			break;
		case 10:
			nhapmang(a,n);
			tangdan(a,n);
			cout<<"Cac phan tu sau khi sap xep la:\n\n";
			xuatmang(a,n);
			break;
		case 11:
			nhapmang(a,n);
			giamdan(a,n);
			cout<<"Cac phan tu sau khi sap xep la:\n\n ";
			xuatmang(a,n);
			break;
		case 12:
			main();
			break;
		case 13:
			exit(0);
			break;
		default:
			cout<<"Khong co lenh tuong ung de thuc hien.\n";
			break;
		}
	}while(0);
	cout<<"\nBan co muon thuc hien tiep chuong trinh khong ? Y/N ? ";
	cin>>tieptuc;
	if(tieptuc=='y' || tieptuc=='Y')
	{
		main();
	}else if(tieptuc=='n' || tieptuc=='N')
	{
		exit(0);
	}
	return 0;
}