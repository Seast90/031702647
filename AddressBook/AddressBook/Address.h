#pragma once
#include "Area.h"
using namespace std;
class Address {
public:
	wstring Ori, prov, downtown, region, street, road, number, build;
	int provtype;
	Address(){}
	Address(wstring __str) {
		prov = downtown = region = street = road= number= build =L"";
		Ori = __str;
	}
	void Classification();
	void doit();
	void print();
	void GetAns(vector<wstring> &);
};