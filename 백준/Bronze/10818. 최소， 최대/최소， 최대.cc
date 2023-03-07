#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    ios_base::sync_with_stdio(0);     //속도 빨라짐
    
    int n;
	cin >> n;

	int minNum = 1000001;       //입력할 수 있는 최대 숫자가 1000,000이니까, 초기값이 무조건 바뀔 수 있도록
	int maxNum = -1000001;

	int inputNum;
	for (int i = 0; i < n; i++) {
		cin >> inputNum;
		if (minNum > inputNum) {
			minNum = inputNum;
		}
		if (maxNum < inputNum) {
			maxNum = inputNum;
		}
	}
	cout << minNum << " " << maxNum << endl;

	return 0;
}