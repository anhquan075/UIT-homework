#pragma once
#include <iostream>
#include <string>
using namespace std;

class Personality
{
protected:
	string TenYeuTo;
	string YeuTo;
	int ChiSo;
public:
	Personality();
	Personality(string, int);
	virtual ~Personality();

	void SetYeuTo(string yt) { YeuTo = yt; }
	string GetYeuTo() { return YeuTo; }

	void SetChiSo(int cs) { ChiSo = cs; }
	int GetChiSo() { return ChiSo; }

	void SetTenYeuTo(string tyt) { TenYeuTo = tyt; }
	string GetTenYeuTo() { return TenYeuTo; }

	virtual void CheckChiSo();
	virtual void Output();
	virtual void Input();
};

