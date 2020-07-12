#pragma once
#include <iostream>
#include <string>

using namespace std;
class Web
{
protected:
	int x;
	int y;
	int width;
	int height;
	int TextColor;
	int BackgroundColor;
	string text;
public:
	Web();
	virtual ~Web();

	void SetXAxis(int x_axis) { x = x_axis; }
	int GetXAxis() { return x; }
	void SetYAxis(int y_axis) { y = y_axis; }
	int GetYAxis() { return y; }

	void SetWidth(int w) { width = w; }
	int GetWidth() { return width; }
	void SetHeight(int h) { height = h; }
	int GetHeight() { return height; }

	void SetTextColor(int tclr) { TextColor = tclr; }
	int GetTextColor() { return TextColor; }
	void SetBackGroundColor(int bgclr) { BackgroundColor = bgclr; }
	int GetBackGroundColor() { return BackgroundColor; }
	void SetText(string t) { text = t; }
	string GetText() { return text; }

	virtual void Input();
	virtual void Output();
};

