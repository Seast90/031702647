#include"Address.h"

void Address::Classification() {
	wstring s = Ori;
	/*ofstream fout("2.txt");
	for (int i = 0; i < (int)s.size();i++) {
		fout << i << ' ';
		wstring str = s.substr(i, 1);
		fout << Area::UnicodeToUTF8(str) << "\n";
	}*/
	for (int i = 1; i <= 34; i++) {
		int pos = 0, f = 1, len = (int)Area::province[i].size();
		for (int j = 0; j < len; j++) {
			if (Area::province[i][j] != s[pos]) {
				f = 0;
				break;
			}
			pos++;
		}
		if (f) {
			prov = Area::province[i];
			int ty = Area::type[i];
			if (ty == 2) prov += L"������";
			else if (ty == 4) prov += L"ʡ";
			provtype = ty;
			int t = len;
			if (s[t] == L'ʡ') t++;
			else if (s[t] == L'��') t++;
			else {
				if (s[t + 1] == L'��') t += 2;
				if (s[t] == L'��' &&s[t+1]==L'��') t+=2;
				if (s[t] == L'��') t++;
			}
 			s = s.substr(t, (int)s.size() - t);
			break;
		}
	}
	if (provtype == 1) {
		downtown = prov + L'��';
	}else 
	for (int i = 0; i < 333; i++) {
		int pos = 0, f = 1, len = (int)Area::city[i].size();
		for (int j = 0,pos=0; j < len; j++) {
			if (Area::city[i][j] != s[pos]) {
				f = 0;
				break;
			}
			pos++;
		}
		if (f) {
			downtown = Area::city[i];
			downtown += L'��';
			int t = len;
			if (s[t] == L'��') t++;
			s = s.substr(t, (int)s.size() - t);
			break;
		}
	}
	for(int i=0;i<(int)s.size();i++)
		if (s[i] == L'��' || s[i] == L'��') {
			region = s.substr(0, i + 1);
			s = s.substr(i + 1, (int)s.size() - i - 1);
			break;
		}
	for (int i = 0; i<(int)s.size(); i++)
		if (s[i] == L'��' ||( s[i] == L'��'&&s[i+1] !=L'��' )|| s[i]==L'��') {
			if (s[i] == L'��' && s[i + 1] == L'��') i++;
			street = s.substr(0, i + 1);
			s = s.substr(i + 1, (int)s.size() - i - 1);
			break;
		}
	for (int i = 0; i<(int)s.size(); i++)
		if (s[i] == L'·') {
			road = s.substr(0, i + 1);
			s = s.substr(i + 1, (int)s.size() - i - 1);
			break;
		}
	for (int i = 0; i<(int)s.size(); i++)
		if (s[i] == L'��') {
			number = s.substr(0, i + 1);
			s = s.substr(i + 1, (int)s.size() - i - 1);
			break;
		}
	build = s;
	Ori = s;
}

void Address::print() {
	ofstream fout("2.txt");
	fout << Area::UnicodeToUTF8(prov) << "\n";
	fout << Area::UnicodeToUTF8(downtown) << "\n";
	fout << Area::UnicodeToUTF8(region) << "\n";
	fout << Area::UnicodeToUTF8(street) << "\n";
	fout << Area::UnicodeToUTF8(road) << "\n";
	fout << Area::UnicodeToUTF8(number) << "\n";
	fout << Area::UnicodeToUTF8(build) << "\n";
}
void Address::doit() {
	Classification();
	print();
}
