#include "People.h"
int main(int argv, char **argc) {
	if (argv < 3) return 0;
	ifstream fin;
	fin.open(argc[1]);
	ofstream fout;
	fout.open(argc[2]);
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
	fin.close();
	fout.close();
	//t.Print();
	return 0;
}