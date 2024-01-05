#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, num;
vector<int> v, ans;
stack<int> st;

int main() {

	cin >> n;
	
	v.resize(n + 1);
	ans.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	int j = n;
	//스택 삽입
	for (int i = n; i > 0; i--) {
		if (st.empty()) st.push(i);        //인덱스 삽입(인덱스로 접근)
		else {			
			while (!st.empty() && v[st.top()] <= v[i]) {
				ans[st.top()] = i;
				st.pop();
			}
			st.push(i);		
		}
	}

	//스택에 남아있는 나머지 다 0으로
	while (!st.empty()) {
		ans[st.top()] = 0;
		st.pop();
	}

	//정답 배열 출력
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}