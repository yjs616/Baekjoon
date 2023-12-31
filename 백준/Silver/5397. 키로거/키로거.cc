#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {

		string s;
		vector<char> password;
		vector<char> temp;

		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i]>='0'&& s[i]<='9') {
				password.push_back(s[i]);	
			}else if (s[i] == '<') {
				if (!password.empty()) {
					temp.push_back(password.back());
					password.pop_back();
				}
			}else if (s[i] == '>') {
				if (!temp.empty()) {
					password.push_back(temp.back());
					temp.pop_back();
				}
			}else if (s[i] == '-') {
				if (!password.empty()) {
				    password.pop_back();
				}
			}
		}

		while (!temp.empty()) {
			password.push_back(temp.back());
			temp.pop_back();
		}

		for (char c : password) {
			cout << c;
		}
		cout << "\n";

	}

	return 0;
}
