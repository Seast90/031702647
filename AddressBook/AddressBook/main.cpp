#include "People.h"
int main() {
	locale china("chs");
	People t;
	wstring s;
	wcin.imbue(china);
	wcout.imbue(china);
	wcin >> s;
	//s = "д╕Ти╟╒фе";
	//wcout << s;
	t = People(s);
	t.doit();
	t.Print();
	return 0;
}