#include"Area.h"
namespace Area {
	std::wstring province[50];
	int type[50];
	void init() {
		for (int i = 1; i <= 4; i++) type[i] = 1;
		for (int i = 4; i <= 9; i++) type[i] = 2;
		province[1] = L"北京";	province[2] = L"上海";	province[3] = L"天津";	province[4] = L"重庆";
	}
};