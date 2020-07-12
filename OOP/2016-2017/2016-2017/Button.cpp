#include "Button.h"

Button::Button()
{
	SetTextColor(0);
	SetBackGroundColor(0);
	SetText("");
	SetPicture(0);
}

Button::~Button()
{

}

void Button::Input()
{
	int temp;
	cout << "\nNhap vao thong tin cua 1 nut:\n";
	Web::Input();
	cout << "\nNut co hinh anh hay text. (1) Hinh anh , (2) Text:\n";
	cin >> temp;
	switch (temp)
	{
	case 1:
		cout << "\nNut co anh khong ? Yes(1), No(0).\n";
		cin >> picture;
		break;
	case 2:
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
		break;
	default:
		break;
	}
}

void Button::Output()
{

	Web::Output();
	if (GetPicture())
		cout << "\nNut co hinh anh.\n";
	else
	{
		cout << "\nNut co noi dung text: " << GetText();
		cout << "\nMau text:\n" << GetTextColor() << endl;
		cout << "\nMau nen:\n" << GetBackGroundColor() << endl;
	}
}