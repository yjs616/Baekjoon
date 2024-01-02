#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string s, ret;
int n;
vector<char> tmp;

int main() {
	cin >> s >> n;

	stack<char> st;

	for (size_t i = 0; i < s.size(); i++) {
		st.push(s[i]);
	}

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;

		if (c == 'L') {
			if(!st.empty()){
				tmp.push_back(st.top());
				st.pop();
			}
		}
		else if (c == 'D') {
			if (!tmp.empty()) {
				st.push(tmp.back());
				tmp.pop_back();
			}
		}
		else if (c == 'B') {
			if (!st.empty()) {
				st.pop();
			}
		}
		else if (c == 'P') {
			char inser;
			cin >> inser;
			st.push(inser);
		}
	}

	//문자열 출력하기
	while (!st.empty()) {
		ret += st.top();
		st.pop();
	}
	reverse(ret.begin(), ret.end());

	while (!tmp.empty()){
		ret += tmp.back();
		tmp.pop_back();
	}

	cout << ret;
	
	return 0;
}