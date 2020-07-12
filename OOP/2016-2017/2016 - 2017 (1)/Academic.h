#pragma once
#include "Gate.h"
class Academic:public Gate
{
private:
	int intel;
public:
	Academic();
	~Academic();

	void SetIntel(int i) { intel = i; }
	int GetIntel() { return intel; }

	void Input();
	int GetBack();
};

