#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;
vector<char> ret;
int n, num;
bool isBool = true;

int main() {
	cin >> n;

	int j = 1;
	for (int i = 0; i < n; i++) {      //횟수
		cin >> num;

		while (isBool) { // 5
			if (st.empty()) {
				st.push(j);
				ret.push_back('+');
				j++;
			}
			else {
				if (st.top() == num) {
					st.pop();
					ret.push_back('-');
					break;
				}
				else {
					if (st.top() > num) {
						isBool = false;
					}
					else {
						st.push(j);
						j++;
						ret.push_back('+');
					}
				}
			}
		}
		
	}

	if (isBool) {
		for (char c : ret) {
			cout << c << "\n";
		}
	}
	else {
		cout << "NO";
	}

	return 0;
}