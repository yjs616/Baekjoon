#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int n, a=1;
int ret[100003];
vector<char> answer;
string s;
stack<int> st;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> ret[i];
	}

	for (int i = 0; i < n; i++) {
		if (!st.empty() && st.top() > ret[i]) {
			s = "NO";
			break;
		}
		 do {
			if (a <= ret[i]) {
				st.push(a);
				//cout << "push : " << a << "\n";
				answer.push_back('+');
				a++;
			}
			if (!st.empty() && st.top() == ret[i]) {
				//cout << "pop : " << st.top() << "\n";
				answer.push_back('-');
				st.pop();
				break;
			}

		 } while (!st.empty());
		 
	}
	if (s != "NO") {
		for (char c : answer) {
			cout << c << "\n";
		}
	}
	else {
		cout << s << "\n";
	}

	return 0;
}