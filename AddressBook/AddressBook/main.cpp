#include "People.h"
int main() {
	ifstream fin("1.txt");
	ofstream fout("2.txt");
	//locale china("chs"); wcin.imbue(china); wcout.imbue(china);
	Area::init();
	string s;
	vector < wstring > ans;
	ans.push_back(L"[");
	while (fin >> s) {
		People t = People(s);
		t.doit(ans);
	}
	ans.push_back(L"]");
	for (int i = 0; i < (int)ans.size(); i++) {
		fout << Area::UnicodeToUTF8(ans[i]) << "\n";
	}
	//t.Print();
	return 0;
}