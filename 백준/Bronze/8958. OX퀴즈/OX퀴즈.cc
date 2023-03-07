#include <iostream>
#include <string>

using namespace std;

//3. 갯수 세는 함수 생성
int Count(string& inputString) {

	int countNum = 0;
	int sumNum = 0;

	for (char& c : inputString) {
		if (c == 'O') {
			countNum++;
			sumNum += countNum;
		}
		else {
			countNum = 0;
		}
	}

	return sumNum;      //리턴값 주면 함수 종료
}

int main() {

	//1. 갯수 입력
	int n;
	cin >> n;


	//2. 갯수만큼 케이스 입력
	for (int i = 0; i < n; i++) {
		string inputString;
		cin >> inputString;


		cout << Count(inputString) << endl;
	}

	return 0;
}


