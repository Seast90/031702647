#include"Area.h"
namespace Area {
	std::wstring province[50];
//	std::wstring rprovince[50];
	vector <wstring> city;
	int type[50];
	void init() {
		for (int i = 1; i <= 34; i++)type[i] = 4;
		for (int i = 1; i <= 4; i++) type[i] = 1;
		for (int i = 4; i <= 9; i++) type[i] = 2;
		for (int i = 33; i <= 34; i++)type[i] = 3;
		province[1] = L"北京";	province[2] = L"上海";	province[3] = L"天津";	province[4] = L"重庆";
		province[5] = L"内蒙古";	province[6] = L"新疆";	province[7] = L"广西";	province[8] = L"西藏";
		province[9] = L"宁夏";	province[10] = L"辽宁";	province[11] = L"吉林";	province[12] = L"黑龙江";
		province[13] = L"河北";	province[14] = L"山西";	province[15] = L"陕西";	province[16] = L"甘肃";
		province[17] = L"青海";	province[18] = L"山东";	province[19] = L"安徽";	province[20] = L"江苏";
		province[21] = L"浙江";	province[22] = L"河南";	province[23] = L"湖北";	province[24] = L"湖南";
		province[25] = L"江西";	province[26] = L"台湾";	province[27] = L"福建";	province[28] = L"云南";
		province[29] = L"海南";	province[30] = L"四川";	province[31] = L"贵州";	province[32] = L"广东";
		province[33] = L"香港";	province[34] = L"澳门";
	
		city.clear();
		ifstream fin("city.txt");
		string s;
		while (fin >> s) {
			wstring str = UTF8ToUnicode(s);
			city.push_back(str);
		}
		//cout << (city.size());system("pause");
	}

	std::string UnicodeToUTF8(const wstring&s) {
		std::string ret;
		wstring_convert<codecvt_utf8<wchar_t> > wcv;
		ret = wcv.to_bytes(s);
		return ret;
	}
	wstring UTF8ToUnicode(const string &s) {
		wstring ret;
		wstring_convert<codecvt_utf8<wchar_t> > wcv;
		ret = wcv.from_bytes(s);
		return ret;
	}
};