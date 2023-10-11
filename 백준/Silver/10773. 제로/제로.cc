#include <iostream>
#include <stack>
using namespace std;

int k, sum;
stack<int> st;

int main() {

	cin >> k;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			st.pop();
		}
		else {
			st.push(num);
		}
	}

	if (st.size() == 0) {
		cout << "0" << "\n";
	}
	else {
		while (!st.empty()) {
			sum += st.top();
			st.pop();
		}
		cout << sum << "\n";
	}
	
	return 0;
}