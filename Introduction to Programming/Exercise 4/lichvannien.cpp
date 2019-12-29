#include <iostream>
using namespace std;


bool checkYear(int nam) 
{ 
	return (((nam % 4 == 0) && (nam % 100 != 0)) || (nam % 400 == 0)); 
} 


int tinhsongaycua1thang(int thang,int nam){
	 return (thang == 2) ? (28 + checkYear(nam)) : 31 - (thang - 1) % 7 % 2;
}

int zeller(int ngay,int thang,int nam)
{
	int q = ngay; 
	int m = thang; 
	int k = nam % 100; 
	int j = nam / 100; 
	int h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j; // Công thức Zeller
	h = (h+6)% 7;
	return h; 
}

void thucuangaybatky(int ngay,int thang, int nam)
{
	do
	{
		cout<<"\nNhap ngay:";
		cin>>ngay;
		if(ngay < 0 || ngay > 31)
			cout<<"\nSo lieu khong hop le vui long nhap lai !\n";
	}while(ngay < 0 || ngay > 31);

	do{
		cout<<"\nNhap thang:";
		cin>>thang;
		if(thang < 0 || thang > 12 || ngay == 30 && thang == 2)
			cout<<"\nSo lieu khong hop le vui long nhap lai !\n";
	}while(thang < 0 || thang > 12 || ngay == 30 && thang == 2);

	do{
		cout<<"\nNhap nam:";
		cin>>nam;
		if(nam < 1900 || nam > 9999 || ngay == 29 && checkYear(nam) == 0)
			cout<<"\nSo lieu khong hop le vui long nhap lai !\n";
	}while(nam < 1900 || nam > 9999 || ngay == 29 && checkYear(nam) == 0);

	if (thang < 3) 
	{ 
    	thang += 12;
    	nam--;
    } 

    cout<<"Ngay hom do la ";
	switch (zeller(ngay,thang,nam)) 
	{ 
	    case 0 : cout<<"Chu Nhat \n"; 
	    break; 
	    case 1 : cout<<"Thu Hai \n"; 
	    break; 
	    case 2 : cout<<"Thu Ba \n"; 
	    break; 
	    case 3 : cout<<"Thu Tu \n"; 
	    break; 
	    case 4 : cout<<"Thu Nam \n"; 
	    break; 
	    case 5 : cout<<"Thu Sau \n"; 
	    break; 
	    case 6 : cout<<"Thu Bay \n"; 
	    break; 
	} 
}


void lichcuathang(int thang,int nam)
{
	cout<<"\n\nNhap thang va nam can in lich ra man hinh :\n";
	cin>>thang>>nam;
	cout<<"Lich cua thang "<<thang<<" nam "<<nam<<" la:\n\n";
	cout<<"Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
	int ngaytrongthang = tinhsongaycua1thang(thang,nam); 
	int current = zeller(1, thang, nam);
	int k;
	for(k = 0 ; k < current; k++)
	{
		cout<<"     ";
	}
	for (int j = 1; j <= ngaytrongthang; j++) 
    { 
        if(j >=10)
        	cout<<j<<"   ";
        else
        	cout<<j<<"    ";  
        if(++k >6)
        {
        	k = 0;
        	cout<<"\n";
        }
    }
}


void lichcanchi(int nam)
{
	cout<<"\n\n\n----CAN CHI CUA MOT NAM----";
	cout<<"\n\nNhap nam can tinh: ";
	cin>>nam;
	int x;
	x = nam % 10 ;
	
	switch(x) { 
		case 4 : cout<<"Giap ";
		break ;
		case 5 : cout<<"At ";
		break ;
		case 6 : cout<<"Binh ";
		break ;
		case 7 : cout<<"Dinh ";
		break ;
		case 8 : cout<<"Mau ";
		break ;
		case 9 : cout<<"Ky ";
		break ;
		case 0 : cout<<"Canh ";
		break ;
		case 1 : cout<<"Tan ";
		break ;
		case 2 : cout<<"Nham ";
		break ;
		case 3 : cout<<"Quy ";
		break ;
	}
	
	x = nam % 12;
	
	switch(x) { 
		case 0 : cout<<"Than";
		break ;
		case 1 : cout<<"Dau";
		break ;
		case 2 : cout<<"Tuat";
		break ;
		case 3 : cout<<"Hoi";
		break ;
		case 4 : cout<<"Ti";
		break ;
		case 5 : cout<<"Suu";
		break ;
		case 6 : cout<<"Dan";
		break ;
		case 7 : cout<<"Meo";
		break ;
		case 8 : cout<<"Thin";
		break ;
		case 9 : cout<<"Ty";
		break ;
		case 10 : cout<<"Ngo";
		break ;
		case 11 : cout<<"Mui";
		break ;
	}
}


int main(){
	int ngay,thang,nam;
	thucuangaybatky(ngay,thang,nam);
	lichcuathang(thang,nam);
	lichcanchi(nam);
	return 0;
}