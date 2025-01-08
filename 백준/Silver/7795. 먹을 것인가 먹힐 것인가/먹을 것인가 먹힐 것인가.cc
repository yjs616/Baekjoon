#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

//lower_bound

int main(){
	cin >> t;
	
	while(t--){
		
		int cnt = 0;
		int A, B;
		
		cin >> A >> B;
		
		vector<int> A_set(A);
		vector<int> B_set(B);
		
		for(int i=0; i<A; i++){
			cin >> A_set[i];
		}
		for(int i=0; i<B; i++){
			cin >> B_set[i];
		}
		
		sort(A_set.begin(), A_set.end());
		sort(B_set.begin(), B_set.end());
		
		for(int i=0; i<A; i++){
			auto idx = lower_bound(B_set.begin(), B_set.end(), A_set[i]); //A_set[i]가 시작되는 최소 시작점 -> 이전은 다 A_set보다 작음
			cnt += (int)(idx- B_set.begin());
		}
		
		cout << cnt << "\n";
		
	}
	return 0;
}