#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int n, money, sum;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> money;
		if (money == 0) {
			st.pop();
		}
		else {
			st.push(money);
		}
	}

	//남아있는 수들의 합 계산
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum;

	return 0;
}