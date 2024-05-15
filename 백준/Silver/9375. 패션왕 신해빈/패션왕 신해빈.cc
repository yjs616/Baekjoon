#include <bits/stdc++.h>
using namespace std;
int n, clothNum;
string clothName, clothType;
int main(){
	cin >> n;
	
	for(int i=0; i<n; i++){
		map<string, int> closet;
		
		cin >> clothNum;
		
		for(int j=0; j<clothNum; j++){
			cin >> clothName >> clothType;
			closet[clothType]++;
		}
		
		long long sum =1;
		for(auto it : closet){
			sum *= (it.second+1);
	    }
		
		cout << sum-1 << "\n";	
	}
		
	return 0;
}