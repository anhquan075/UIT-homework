#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Poem
{
protected:
	int SoTieng;
	string TenBaiTho;
	int SoCau;
	vector<string> vecCauTho;
public:
	Poem();
	virtual ~Poem();

	void SetSoTieng(int st) { SoTieng = st; }
	int GetSoTieng() { return SoTieng; }

	void SetTenBaiTho(string tbt) { TenBaiTho = tbt; }
	string GetTenBaiTho() { return TenBaiTho; }

	void SetSoCau(int sc) { SoCau = sc; }
	int GetSoCau() { return SoCau; }

	void SetVecCauTho(vector<string> vct) { vecCauTho = vct; }
	vector<string> GetVecCauTho() { return vecCauTho; }

	virtual void Input();
	virtual void Output();
};

