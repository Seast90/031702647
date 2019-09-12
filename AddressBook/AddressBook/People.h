#pragma once
#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
class People {
public :
	wstring Ori, name, address;
	long long PhoneNumber;
	People(){}
	People(wstring __str) {
		Ori = __str; 
	}
	void GetNumber();
	void GetAddress();
	void GetName();
};