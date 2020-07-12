#pragma once
#include "DuongLuat.h"
#include "LucBat.h"
#include "BaiTho.h"
#include "SongThat.h"
class TapTho
{
private:
	vector<Poem*> taptho;
public:
	TapTho();
	~TapTho();

	void SetTapTho(vector<Poem*> vtt) { taptho = vtt; }
	vector<Poem*> GetTapTho() { return taptho; }

	void InputTapTho();
	void OutputTapTho();

	void BaiThoDaiNhat();
};

