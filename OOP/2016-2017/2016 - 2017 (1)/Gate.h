#pragma once
#include <iostream>
#include <string>

using namespace std;
class Gate
{
protected:
	int type;
public:
	Gate();
	virtual ~Gate();

	virtual void Input() = 0;
	virtual int GetBack() = 0;

	void SetType(int t) { type = t; }
	int GetType() { return type; }

};

