#include "People.h"
void People::ClearPunctuation() {
	wstring str = address, s=L"";
	int len = str.size();
	for (int i = 0; i < len; i++)
		if (str[i] != ',' && str[i] != L'��' && str[i] != '.' && str[i] != L'��')
			s = s + str[i];
	address = s;
}
void People::GetNumber() {
	wstring str = Ori;
	int len = str.size();
	for (int pos = 0; pos < len; pos++) {
		if (str[pos] < '0' && str[pos] > '9') continue;
		int cnt = 0;
		PhoneNumber = L"";
		for (int _pos = pos; _pos < len&&str[_pos] >= '0'&&str[_pos] <= '9'; _pos++) {
			cnt++;
			PhoneNumber = PhoneNumber + str[_pos];
		}
		if (cnt == 11) {
			Ori = Ori.substr(0, pos) + Ori.substr(pos + 11, len - pos - 10);
			break;
		}
	}
}
void People::GetName() {
	wstring str = Ori;
	int pos = 0, len = str.size();
	while (pos < len && str[pos] != L',' && str[pos] != '��')
		pos++;
	name = str.substr(0, pos);
	address = str.substr(pos, len - pos + 1);
}
void People::GetAddress() {
	one = Address(address);
	one.doit();
	//one.Classification();
}

void People::Print() {
	ofstream fout("2.txt");
	fout << Area::UnicodeToUTF8(Area::province[1]) <<"\n";
	//name = Area::province[1];
	fout << Area::UnicodeToUTF8(name)<<"\n";
	fout << Area::UnicodeToUTF8(PhoneNumber) << "\n";
	fout << Area::UnicodeToUTF8(address) <<"\n";
	//system("pause");
}

void People::GetAns(vector <wstring > &ans) {
	ans.push_back(L"    {");
	wstring s = L"        \"����\": \"", t = L"\",";
	ans.push_back(s + name + t);
	s = L"        \"�ֻ�\" : \"";
	ans.push_back(s + PhoneNumber + t);
	one.GetAns(ans);
	ans.push_back(L"    },");
}
void People::doit(vector <wstring > &ans) {
	GetNumber();
	GetName();
	ClearPunctuation();
	GetAddress();
	GetAns(ans);
}
