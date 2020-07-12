#include "QuanLiTamLy.h"



QuanLiTamLy::QuanLiTamLy()
{
	SetSoLuongTinhCach(5);
	vector<Personality*> personal;
	personal.resize(5);
	SetQuanLi(personal);
}

QuanLiTamLy::~QuanLiTamLy()
{
	
}

void QuanLiTamLy::InputPersonality()
{
	vector<Personality*> per;
	per.resize(5);
	per.push_back(new O());
	per[per.size() - 1]->Input();
	per[per.size() - 1]->CheckChiSo();
	
	per.push_back(new C());
	per.back()->Input();
	per.back()->CheckChiSo();

	per.push_back(new E());
	per.back()->Input();
	per.back()->CheckChiSo();

	per.push_back(new A());
	per.back()->Input();
	per.back()->CheckChiSo();

	per.push_back(new N());
	per.back()->Input();
	per.back()->CheckChiSo();

	SetQuanLi(per);
}

void QuanLiTamLy::OutputPersonality()
{
	vector<Personality*> person(GetSoLuongTinhCach());
	person = GetQuanLi();
	for (int i = 5; i < 10; ++i)
	{
		person[i]->Output();
	}
}