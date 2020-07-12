#include "Web.h"

Web::Web()
{
	SetXAxis(0);
	SetYAxis(0);
	SetWidth(0);
	SetHeight(0);
}

Web::~Web()
{

}


void Web::Input()
{
	cout << "\nNhap hoanh do (x):\n";
	cin >> x;
	cout << "\nNhap tung do (y):\n";
	cin >> y;
	cout << "\nNhap chieu dai (h):\n";
	cin >> height;
	cout << "\nNhap chieu rong (w):\n";
	cin >> width;
}

void Web::Output()
{
	cout << "- Hoanh do: " << GetXAxis() << endl;
	cout << "- Tung do: " << GetYAxis() << endl;
	cout << "- Chieu dai: " << GetHeight() << endl;
	cout << "- Chieu rong: " << GetWidth() << endl;
}