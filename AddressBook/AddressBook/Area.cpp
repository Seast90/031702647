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
		province[1] = L"����";	province[2] = L"�Ϻ�";	province[3] = L"���";	province[4] = L"����";
		province[5] = L"���ɹ�";	province[6] = L"�½�";	province[7] = L"����";	province[8] = L"����";
		province[9] = L"����";	province[10] = L"����";	province[11] = L"����";	province[12] = L"������";
		province[13] = L"�ӱ�";	province[14] = L"ɽ��";	province[15] = L"����";	province[16] = L"����";
		province[17] = L"�ຣ";	province[18] = L"ɽ��";	province[19] = L"����";	province[20] = L"����";
		province[21] = L"�㽭";	province[22] = L"����";	province[23] = L"����";	province[24] = L"����";
		province[25] = L"����";	province[26] = L"̨��";	province[27] = L"����";	province[28] = L"����";
		province[29] = L"����";	province[30] = L"�Ĵ�";	province[31] = L"����";	province[32] = L"�㶫";
		province[33] = L"���";	province[34] = L"����";
	
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