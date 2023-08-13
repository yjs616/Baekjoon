#include <bits/stdc++.h>
using namespace std;

int a,b,c;
pair<int, int> truck1, truck2, truck3;
int maxTime, totalTime, subTime;
int main(){
	cin >> a >> b >> c;
	
	cin >> truck1.first >> truck1.second;
	cin >> truck2.first >> truck2.second;
	cin >> truck3.first >> truck3.second;
	
	if(truck1.second < truck2.second){
		maxTime = truck2.second;
		if(maxTime < truck3.second){
			maxTime = truck3.second;
		}
	}else{
		maxTime = truck1.second;
		if(maxTime < truck3.second){
			maxTime = truck3.second;
		}
	}
	
	for(int time =1; time<= maxTime; time++){
		int cnt=0; 
		subTime=0;
		
		if(time >= truck1.first && time < truck1.second){
			cnt++;
		}
		if(time >= truck2.first && time < truck2.second){
			cnt++;
		}
		if(time >= truck3.first && time < truck3.second){
			cnt++;
		}
		
		if(cnt ==1){
			subTime = a;
		}else if(cnt==2){
			subTime = b*2;
		}else if(cnt ==3){
			subTime = c*3;
		}
		totalTime += subTime;
	}
	
	cout << totalTime;
	
	return 0;
}