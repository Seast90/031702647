//#pragmaexecution_character_set("utf-8");
#pragma once
#include<string>
#include<iostream>
#include<cstdio>
#include<locale>
#include"Address.h"
using namespace std;
class People {
public :
	wstring Ori, name, address;
	Address one;
	long long PhoneNumber;
	People(){}
	People(wstring __str) {
		Ori = __str; 
	}
	void ClearPunctuation();
	void GetNumber();
	void GetAddress();
	void GetName();
	void Print();
	void doit();
	
};