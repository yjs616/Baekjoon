#include <iostream>
using namespace std;

//다솜이의 방 번호가 주어졌을 때 필요한 숫자 세트의 최소 개수 
//6과 9 뒤집어서 이용 가능
int num[10];    //0-9
string s;

int main() {

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '6' || s[i] == '9') {
			num[6]++;
		}else num[s[i]-'0']++;
	}
	
	if (num[6] % 2 == 0) {
		num[6] = num[6] / 2;
	}else {
		num[6] = num[6] / 2 + 1;
	}

	int ret= 0;
	for (int i = 0; i < 10; i++) {
		ret = max(ret, num[i]);
	}

	cout << ret;
	
	return 0;
}