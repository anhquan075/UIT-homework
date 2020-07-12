#include "LoaiMau.h"
#include "A.h"
#include "B.h"
#include "AB.h"
#include "O.h"
#include "Nguoi.h"

#define MAX 100

int main()
{
	// Cau 1
	int n;
	cout << "\nNhap so luong nguoi:\n";
	cin >> n;
	Nguoi ds;
	ds.Input(n);
	ds.Output();

	// Cau 2
	Nguoi gd;
	gd.Input(3);
	gd.Output();
	gd.CheckDiTruyen();
	// Cau 3
	ds.CheckNhanMau();
	
	return 0;
}