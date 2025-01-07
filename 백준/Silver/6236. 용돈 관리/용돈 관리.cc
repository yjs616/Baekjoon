#include <iostream>
using namespace std;

//인출 금액 k원 최소화하기
//n일 중 m번만 k원 인출 

int n, m;
int arr[100003];
int low;
int high;

bool isPos(int inchul){
	int cnt=0;
	int sum=0;
	for(int i=0; i<n; i++){
		if(sum+ arr[i] > inchul){
			sum=0;
			cnt++;
		}
		sum += arr[i];
	}
	if(sum > 0) cnt++;
	
	return cnt <= m; //이하면 됨(만족하는데도 횟수 맞추려면 뺐다 넣기만 하면 되니까)
}

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
		low = max(low, arr[i]); //가장 큰 금액보다 작으면 가장 큰 금액은 절대 인출 불가임
		high += arr[i]; //돈을 한번만 뽑겠다고 하면
	}
	
	int ret=high;
	while(low <= high){
		int mid = (low+high) / 2;
		
		if(isPos(mid)){
			ret = min(ret,mid);
			//인출 금액 최소화해야되니까
			high= mid-1;
		}else{
			//인출 금액을 높여보자
			low = mid + 1;
		}
	}
	
	cout << ret;
	
	return 0;
}