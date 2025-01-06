#include <iostream>
#include <algorithm>
using namespace std;

//절반 쪼개고 학생 수 카운트

int n, m, b[300003];
int high,low=1;
int ret = 987654321;

bool isPos(int jiltu){
	int cnt=0;
	for(int i=0; i<m; i++){
		cnt += b[i] / jiltu; //몫만큼 카운트
		if(b[i] % jiltu) cnt++;
	}
	
	return n >= cnt;
}

int main(){
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		cin >> b[i];
		high= max(high, b[i]); 
	}
	
	while(low <= high){
		int mid = (low + high) / 2;
		if(isPos(mid)){ //mid가 질투심 후보임
			//가능한 질투심
			//기존꺼랑 비교해서 작은걸로
			ret = min(ret, mid);
			
			high = mid-1; //질투심 낮춰봐야지
		}else{
			low = mid+1;
		}
	}
	
	cout << ret;
	
	return 0;
}