#include"Address.h"

void Address::Classification() {

}

string Address::UnicodeToUTF8(const wstring&s) {
	string ret;
	wstring_convert<codecvt_utf8<wchar_t> > wcv;
	ret = wcv.to_bytes(s);
	return ret;
}

wstring Address::UTF8ToUnicode(const string &s) {
	wstring ret;
	wstring_convert<codecvt_utf8<wchar_t> > wcv;
	ret = wcv.from_bytes(s);
	return ret;
}

