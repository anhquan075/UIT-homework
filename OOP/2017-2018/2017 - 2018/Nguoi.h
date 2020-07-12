#pragma once
#include "LoaiMau.h"
#include "A.h"
#include "B.h"
#include "O.h"
#include "AB.h"
#include <vector>

#define MAX 100

class Nguoi 
{
private:
	vector<LoaiMau*> nguoi;
	int SoLuong;
public:
	Nguoi();
	~Nguoi();
	
	void SetNguoi(vector<LoaiMau*> ng) { nguoi = ng; }
	vector<LoaiMau*> GetNguoi() { return nguoi; }

	void SetSoLuong(int sl) { SoLuong = sl; }
	int GetSoLuong() { return SoLuong; }

	void Input(int n);
	void Output();

	void CheckDiTruyen();
	void CheckNhanMau();
};

