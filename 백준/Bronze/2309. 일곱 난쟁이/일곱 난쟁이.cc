#include <bits/stdc++.h>
using namespace std;

int sum;
vector<int> height(9), h;
//한줄에 대한거 
bool print(vector<int>& h){
	sum =0;
	for(int i: h) {
		sum += height[i];
	}
	if(sum == 100){
		vector<int> newheight;
		for(int i: h) newheight.push_back(height[i]);
		sort(newheight.begin(), newheight.end());
		for(int i: newheight) cout << i << "\n";
		return true;
	}
	return false;
}

bool combi(int start, vector<int>& h){
	if(h.size()== 7){
		if(print(h)) return true;
		return false;
	}
	for(int i = start+1; i<9; i++){
		h.push_back(i);
		if(combi(i,h)) return true;
		h.pop_back();
	}
	return false;
}

int main(){
	
	for(int i=0; i<9; i++){
		cin >> height[i];
	}	
	combi(-1, h);
	return 0;
}