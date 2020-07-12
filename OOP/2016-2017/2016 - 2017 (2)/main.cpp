#include "TapTho.h"

int main()
{
	// Cau 1
	TapTho t;
	t.InputTapTho();
	t.OutputTapTho();


	// Cau 2
	cout << "\nBai tho dai nhat trong tap tho:\n";
	t.BaiThoDaiNhat();

	// Cau 3

	/* Vì trong đề có sẵn hàm kiểm tra gieo vần cho từng bài thơ nên mình không làm câu 3 ở đây
	. Ý tưởng là xây dựng một virtual method int ktgieovan(string a,string b) và sử dụng đa hình 
	cho các lớp con là được.*/
	
	return 0;
}