#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int n;
int a[1000003], ans[1000003];
stack<int> st;

int main() {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.top()] < a[i]) {
			ans[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		ans[st.top()] = -1;
		st.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	

	return 0;
}