#include <iostream>
#include <algorithm>
using namespace std;




int main() {


	ios_base::sync_with_stdio(0);     //속도 빨라짐

	//1. 과목 수 입력
	int n;
	cin >> n;

	//2. 점수 입력
	int scores[1001];
	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}

	//3. 최대 점수
	sort(scores, scores + n);      //[start,end)
	int M = scores[n - 1];
	

	double newScore[1001];
	//4. 모든 점수 올려치기 
	for (int i = 0; i < n; i++) {
		newScore[i] = (double)scores[i]/M*100;
	}

	//5. 새롭게 평균 출력
	double average;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += newScore[i];		
	}
	average = sum / (double)n;

	//6. 평균 출력
	cout << average << endl;

	return 0;
}