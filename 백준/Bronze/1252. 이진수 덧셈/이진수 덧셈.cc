#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int binary1[81]={0}, binary2[81]={0}, sum[81]={0};

int main(){
	cin >> str1 >> str2;
	for(int i=0; i<str1.size(); i++){
		binary1[80-i] = str1[str1.size()-1-i] -'0';	
	}
		
	for(int i=0; i<str2.size(); i++){
		binary2[80-i] = str2[str2.size()-1-i]-'0';
	}
	
	for(int i=80; i>=0; i--){
		sum[i] = binary1[i] + binary2[i];
		if(sum[i] >=2){
			sum[i]= sum[i]-2;
			binary1[i-1]++;
		}
	}
	
	int startIdx=0;
	while(sum[startIdx]==0 && startIdx<80) startIdx++;
	for(int i=startIdx; i<=80; i++){
		cout << sum[i];
	}

	return 0;
}