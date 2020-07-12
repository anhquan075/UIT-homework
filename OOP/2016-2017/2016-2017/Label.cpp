#include "Label.h"

Label::Label()
{
	SetTextColor(0);
	SetBackGroundColor(0);
	SetText("");
}

Label::~Label()
{

}

void Label::Input()
{

	cout << "\nNhap vao thong tin cua 1 nhan:\n";
	Web::Input();
	cout << "\nNhap vao noi dung text.\n";
	cin >> text;
	cout << "Chon mau bang so duoi day : \n";
	cout << "1. Red, 2. Orange, 3.Yellow, 4. Spring Green\n";
	cout << "5. Red, 6. Orange, 7.Yellow, 8. Spring Green\n";
	cout << "9. Red, 10. Orange, 11.Yellow, 12. Spring Green\n";
	cout << "\nNhap vao mau text:\n";
	cin >> TextColor;
	cout << "\nNhap vao mau nen:\n";
	cin >> BackgroundColor;
}

void Label::Output()
{
	Web::Output();
	cout << "\nNut co noi dung text: " << GetText() << endl;
	cout << "\nMau text: " << GetTextColor() << endl;
	cout << "\nMau nen: " << GetBackGroundColor() << endl;
}