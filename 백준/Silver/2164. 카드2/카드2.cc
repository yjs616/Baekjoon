#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
queue<int> que;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
	while (que.size() > 1) {
		que.pop();
		que.push(que.front());
		que.pop();
	}
	cout << que.front();


	return 0;
}