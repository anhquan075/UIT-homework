#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

const int minYear = 1, maxYear = 10000;
struct Ngay
{
       int Day, Month, Year;
};
typedef struct Ngay NGAY;

bool KiemTraNamNhuan(NGAY a)
{
	return (a.Year % 4 == 0 && a.Year % 100 != 0) || (a.Year % 400 == 0);
}

bool KiemTraNamNhuan(int i)
{
    if (i % 4 == 0 && i % 100!=0)
        return true;
    if (i % 400 == 0)
        return true;
    return false;
}
int TimSoNgayTrongThang(NGAY a)
{
	int NgayTrongThang;
	switch(a.Month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		NgayTrongThang = 31;
		break;
	case 4: case 6: case 9 : case 11:
		NgayTrongThang = 30;
		break;
	case 2:
		int Check = KiemTraNamNhuan(a);
		if(Check == 1)
		{
			NgayTrongThang = 29;
		}
		else
		{
			NgayTrongThang = 28;
		}
	}
	return NgayTrongThang;
}


void NhapNgay(NGAY &a)
{
	do
	{
		cout<<"\nNhap vao nam: ";
		cin>>a.Year;
		if(a.Year < minYear || a.Year > maxYear)
		{
			cout<<"\nDu lieu nam khong hop le. Xin kiem tra lai!";
		}
	}while(a.Year < minYear || a.Year > maxYear);

	do
	{
		cout<<"\nNhap vao thang: ";
		cin>>a.Month;
		if (a.Month < 1 || a.Month > 12)
			cout<<"\nDu lieu thang khong hop le. Xin kiem tra lai!";
	}while(a.Month < 1 || a.Month > 12);

	int NgayTrongThang = TimSoNgayTrongThang(a);
	do
	{
		cout<<"\nNhap vao ngay: ";
		cin>>a.Day;
		if(a.Day < 1 || a.Day > NgayTrongThang)
		{
			cout<<"\nDu lieu ngay khong hop le. Xin kiem tra lai!";
		}
	}while(a.Day < 1 || a.Day > NgayTrongThang);
}


void XuatNgay(NGAY ng)
{
	cout<<ng.Day<<"/"<<ng.Month<<"/"<<ng.Year<<endl;
}


int TinhSoThuTuNgayTrongNam(NGAY a)
{

	int S = a.Day;
	for(int i = 1; i < a.Month; i++) 
	{ 
		switch (i)
		{
			case 4: case 6: case 9 : case 11: S += 30; break;
			case 2: S += (a.Year % 4 == 0 && a.Year % 100 != 0 || a.Year % 400 == 0) ? 29 : 28;
				break;
		default: S += 31;
		}
	}
	return S;
}


int TinhSoThuTuNgayTuNgayChoTruoc(NGAY a)
{
	int stt = 0;
	for(int i = 1; i < a.Year; i++)
	{
		if(KiemTraNamNhuan(i))
		{
			stt += 366;
		}
		else
		{
			stt += 365;
		}
	}
	return stt + TinhSoThuTuNgayTrongNam(a);
}

int TimNgayKhiBietNamVaSoThuTuNgayTrongNam(int Year, int STT)
{
	int n[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (KiemTraNamNhuan(Year))
        n[1] = 29;
    for (int i = 0; i < 12; i++)
    {
        if (n[i] < STT)
            STT -= n[i];
        else
            break;
    }
    return STT;
}

int TimNgayKhiBietSoThuTuNgayChoTruoc(int STT)
{
	int Year = 1;
	while(1)
	{
		if(KiemTraNamNhuan(Year))
		{
			if(STT > 366)
			{
				STT -= 366;
			}
			else
			{
				return TimNgayKhiBietNamVaSoThuTuNgayTrongNam(Year, STT);
			}
		}
		else
		{
			if(STT > 365)
			{
				STT -= 365;
			}
			else
			{
				return TimNgayKhiBietNamVaSoThuTuNgayTrongNam(Year, STT);
			}
		}
		Year++;
	}
	return -1;
}


NGAY TimNgayKeTiep(NGAY a)
{
	int NgayTrongThang = TimSoNgayTrongThang(a);
	if (a.Day < NgayTrongThang)  // Tăng ngày lên
	{
		a.Day++;
	}
	else if (a.Month < 12)     // Ngày kế tiếp là đầu tháng
	{
		a.Day = 1; a.Month++;
	}
	else                      // Ngày kế là đầu năm mới tức là hiện tai đang là tháng 12
	{
		a.Day = a.Month = 1;
		a.Year++;
	}
	return a;
}


NGAY TimNgayHomQua(NGAY a)
{
	int NgayTrongThang = TimSoNgayTrongThang(a);
	if(a.Day == 1)            // Nếu ngày nhập vào là 1
	{
		a.Day = NgayTrongThang;        // ngày trước đó là số ngày trong tháng trước 
		if(a.Month == 1)            // Nếu tháng là 1
		{
			a.Month = 12;
			a.Year--;
		}
		else                     // Tháng khác 1
			a.Month--;
	}
	else                // Ngày khác 1
		a.Day--;
	return a;
}
// Tìm ngày kế đó k ngày
NGAY TimNgayKeDoKNgay(NGAY a, int k)
{
	while(k > 0)
	{
		a = TimNgayKeTiep(a);
		k--;
	}
	return a;
}
// Tìm ngày hôm trước k ngày
NGAY TimNgayTruocDoKNgay(NGAY a, int k)
{
	while(k>0)
    {
        a = TimNgayHomQua(a);
        k--;
    }
    return a;
}
// Khoảng cách giữa 2 ngày
int TimKhoangCach2Ngay(NGAY a, NGAY b)
{
	int STTa = TinhSoThuTuNgayTrongNam(a);
	int STTb = TinhSoThuTuNgayTrongNam(b);

	if(STTa > STTb)
	{
		return STTa - STTb;
	}
	return STTb - STTa;
}


//  So sánh 2 ngày
int SoSanh2Ngay(NGAY a, NGAY b)
{
	int STTa = TinhSoThuTuNgayTrongNam(a);
	int STTb = TinhSoThuTuNgayTrongNam(b);

	if(STTa > STTb)
	{
		return 1;
	}
	if(STTb > STTa)
	{
		return 0;
	}
	return -1;
}

int main()
{
	NGAY a,a1,a2;
	NhapNgay(a);
	XuatNgay(a);
	int k;
	if(KiemTraNamNhuan(a))
	{
		cout<<a.Year<<" la nam nhuan ";
	}
	else
	{
		cout<<a.Year<<" la nam thuong ";
	}

	int STTNgay = TinhSoThuTuNgayTrongNam(a);
	cout<<"\nNgay thu "<<STTNgay<<" trong nam";
	int STT = TinhSoThuTuNgayTuNgayChoTruoc(a);
	cout<<"\nNgay thu "<<STT<<" trong nam tu ngay 1/1/1";
	cout<<"\nNgay ke tiep 100 ngay: ";
	XuatNgay(TimNgayKeDoKNgay(a, 100));
    cout<<"\nNgay hom truoc 100 ngay: ";
	XuatNgay(TimNgayTruocDoKNgay(a, 100));


	cout<<"\nNhap du lieu hai ngay de so sanh"<<endl;
	cout<<"\nNhap du lieu ngay thang nam thu nhat: "<<endl;
	NhapNgay(a1);
	XuatNgay(a1);
	cout<<"Nhap du lieu ngay thang nam thu hai:"<<endl;
	NhapNgay(a2);
	XuatNgay(a2);
	// Khoảng cách giũa hai ngày
	cout<<"\nKhoang cach giua hai ngay vua nhap la: "<<TimKhoangCach2Ngay(a1,a2)<<endl;
	// So sánh giữa hai ngày
	if(SoSanh2Ngay(a1,a2) == 1)
		cout<<"Ngay thang nam thu nhat lon hon";
	else if(SoSanh2Ngay(a1,a2) == 0)
		cout<<"Ngay thang nam thu hai lon hon";
	return 0;
}