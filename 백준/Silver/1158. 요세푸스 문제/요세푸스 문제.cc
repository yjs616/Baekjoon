#include <iostream>
#include <queue>
using namespace std;
//백준 1158번 - 요세푸스 문제

int n, k;
queue<int> cq;

int main() {

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cq.push(i);
	}
	cout << "<";
	while (!cq.empty()) {
		for (int i = 1; i <= k; i++) {
			if (i == k) {
				if (cq.size() == 1) {
					cout << cq.front();
				}
				else {
					cout << cq.front() << ", ";
				}
				cq.pop();
				break;
			}
			cq.push(cq.front());    //먼저 뒤에 넣고
			cq.pop();               //앞에 제거
		}
	}
	cout << ">";
	return 0;
}