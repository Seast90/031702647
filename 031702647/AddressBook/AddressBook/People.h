//#pragmaexecution_character_set("utf-8");
//#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include<iostream>
#include<cstdio>
#include<locale>
#include"Address.h"
#include <codecvt>
#include<fstream>
#include <cstdlib>
using namespace std;
class People {
public :
	wstring Ori, name, address;
	Address one;
	wstring PhoneNumber;
	People(){}
	People(string __str) {
		Ori = Area::UTF8ToUnicode(__str); 
	}
	void ClearPunctuation();
	void GetNumber();
	void GetAddress();
	void GetName();
	void Print();
	void GetAns(vector <wstring > &);
	void doit(vector <wstring > &);
};