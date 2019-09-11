#pragma once
#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
class People {
public :
	string Ori;
	long long PhoneNumber;
	People(){}
	People(string __str) {
		Ori = __str; 
	}
	void GetNumber();
	void GetAddress();
};