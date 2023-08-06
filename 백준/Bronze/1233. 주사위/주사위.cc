#include <bits/stdc++.h>
using namespace std;

int s1, s2, s3, maxValue=0, maxKey;
map <int, int> mp;

int main(){
	cin >> s1 >> s2 >> s3;
	
	for(int i=1; i<=s1; i++){
		for(int j=1; j<= s2; j++){
			for(int k=1; k<=s3; k++){
				int subsum = i+j+k;
				mp[subsum]++;
			}
		}
	}
	for(auto it : mp){
		int value = it.second;
		int key = it.first;
		if(value > maxValue){
			maxValue = value;
			maxKey = key;
		}
	}
	cout << maxKey;
	
	return 0;	
}