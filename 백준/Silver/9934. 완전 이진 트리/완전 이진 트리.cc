#include <iostream>
#include <vector>
using namespace std;

int k, num;
vector<int> nodes;
vector<int> depth[10];

void PrintNode(int s, int e, int d) {
	if (s >= e) {
		return;
	}
	int mid = (s + e) / 2;
	depth[d].push_back(nodes[mid]);

	//recursion
	PrintNode(s, mid, d + 1);
	PrintNode(mid + 1, e, d + 1);
}

int main() {
	cin >> k;


	while(cin >> num) {
		nodes.push_back(num);
	}

	PrintNode(0, nodes.size(), 0);

	//트리 모양으로 출력  
	for (int i = 0; i < k; i++) {     //depth
		for (int value : depth[i]) {
			cout << value << " ";
		}
		cout << "\n";
	}

	return 0;
}
