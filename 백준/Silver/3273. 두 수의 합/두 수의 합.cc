#include <iostream>
#include <unordered_map>
using namespace std;

int n, num[1000003], sum, cnt;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	cin >> sum;

	//해시 맵
	unordered_map<int, int> mp;

	//배열의 숫자 해시 맵에
	for (int i = 0; i < n; i++) {
		mp[num[i]] = i;           //인덱스에 매핑
	}

	for (int i = 0; i < n; i++) {
		int sub = sum - num[i];      //내가 찾아야 하는거
		
		auto it = mp.find(sub);
		if (it != mp.end() && it->second != i) {
			cnt++;                 //쌍으로 증가됨
		}

	}

	cout << cnt/2;

	return 0;
}