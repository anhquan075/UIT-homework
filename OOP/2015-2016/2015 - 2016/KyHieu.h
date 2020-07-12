#pragma once
#include <iostream>
#include <string>

using namespace std;
class KyHieu
{
protected:
	float TruongDo;
public:
	KyHieu();
	virtual ~KyHieu();

	void SetTruongDo(float td) { TruongDo = td; }
	float GetTruongDo() { return TruongDo; }

	virtual float GetCaoDo();
	virtual void Input();
	virtual bool KiemTraDauLang();
};

