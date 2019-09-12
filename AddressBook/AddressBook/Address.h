#pragma once
#include<string>
#include<iostream>
#include<cstdio>
#include<locale>
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