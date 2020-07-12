#pragma once
#include <iostream>
#include <string>

using namespace std;
class Hero
{
private:
	int power;
	int intel;
	int money;
public:
	Hero();
	~Hero();

	void SetIntel(int i) { intel = i; }
	int GetIntel() { return intel; }
	void SetPower(int p) { power = p; }
	int GetPower() { return power; }
	void SetMoney(int m) { money = m; }
	int GetMoney() { return money; }

	void Input();
};

