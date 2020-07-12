#pragma once
#include "KyHieu.h"
class NotNhac:public KyHieu
{
private:
	float CaoDo;
public:
	NotNhac();
	~NotNhac();

	void SetCaoDo(float cd) { CaoDo = cd; }
	float GetCaoDo() { return CaoDo; }

	void Input();
};

