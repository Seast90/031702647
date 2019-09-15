#include "People.h"
int main() {
	ifstream fin("1.txt");
	ifstream fn("1.out");
	ofstream fout("2.txt");
	//locale china("chs"); wcin.imbue(china); wcout.imbue(china);
	People t;
	string s;
	fin >> s;
	t = People(s);
	t.doit();
	t.Print();
	return 0;
}