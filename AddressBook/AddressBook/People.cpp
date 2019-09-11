#include "People.h"

void People::GetNumber() {
	string str = Ori;
	int len = str.size();
	for (int pos = 0; pos < len; pos++) {
		if (str[pos] < '0' && str[pos] > '9') continue;
		int cnt = 0;
		PhoneNumber = 0;
		for (int _pos = pos; _pos < len&&str[_pos] >= '0'&&str[_pos] <= '9'; _pos++) {
			cnt++;
			PhoneNumber = 10 * PhoneNumber + str[_pos] - '0';
		}
		if (cnt == 11) break;
	}
}