#pragma once
#include "Web.h"

class Button:public Web
{
private:
	bool picture;
public:
	Button();
	~Button();


	void SetPicture(bool p) { picture = p; }
	bool GetPicture() { return picture; }

	void Input();
	void Output();
};

