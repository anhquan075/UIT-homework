#pragma once
#include "Gate.h"
class Power :public Gate
{
private:
	int power;
public:
	Power();
	~Power();

	void SetPower(int p) { power = p; }
	int GetPower() { return power; }

	void Input();
	int GetBack();
};

