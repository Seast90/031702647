#pragma once
#include "Area.h"
using namespace std;
class Address {
public:
	wstring Ori;
	Address(){}
	Address(wstring __str) {
		Ori = __str;
	}
	void Classification();
};