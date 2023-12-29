#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);                         //1부터 n명 push
	}

	cout << "<";
	while (q.size() > 1) {
		for (int i = 1; i <= k - 1; i++) {     //k-1만큼 뒤로 넘기기
			q.push(q.front());
			q.pop();
		}
		cout << q.front() <<", ";
		q.pop();
	}

	//1개 남았을 때
	cout << q.front() << ">";

	return 0;
}