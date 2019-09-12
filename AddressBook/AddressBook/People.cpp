#include "People.h"

void People::GetNumber() {
	wstring str = Ori;
	int len = str.size();
	for (int pos = 0; pos < len; pos++) {
		if (str[pos] < '0' && str[pos] > '9') continue;
		int cnt = 0;
		PhoneNumber = 0;
		for (int _pos = pos; _pos < len&&str[_pos] >= '0'&&str[_pos] <= '9'; _pos++) {
			cnt++;
			PhoneNumber = 10 * PhoneNumber + str[_pos] - '0';
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
	while (pos < len && str[pos] != ',' && str[pos] != '£¬')
		pos++;
	name = str.substr(0, pos);
	address = str.substr(pos, len - pos + 1);
}
void People::GetAddress() {

}