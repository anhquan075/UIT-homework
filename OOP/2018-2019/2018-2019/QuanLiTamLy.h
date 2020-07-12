#pragma once
#include "O.h"
#include "C.h"
#include "E.h"
#include "A.h"
#include "N.h"
#include "Personality.h"
#include <vector>


class QuanLiTamLy:public Personality
{
protected:
	vector<Personality*> personal;
	int SoLuongTinhCach;
public:
	QuanLiTamLy();
	~QuanLiTamLy(); 

	void SetQuanLi(vector<Personality*> person){ personal = person;}
	vector<Personality*> GetQuanLi() { return personal; }

	void SetSoLuongTinhCach(int sl) { SoLuongTinhCach = sl; }
	int GetSoLuongTinhCach() { return SoLuongTinhCach; }

	void InputPersonality();
	void OutputPersonality();
};

