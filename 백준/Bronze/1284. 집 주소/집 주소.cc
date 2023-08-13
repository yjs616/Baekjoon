#include <bits/stdc++.h>
using namespace std;

string num;
int width;
int numToNum;
int sumWidth;

int main(){
	
	while(true){
		sumWidth=2;
		cin >> num;
		if(num == "0"){
			break;
		}
		
		numToNum = num.size()-1;
		
		for(int i=0; i<num.size(); i++){
			if(num[i]=='1'){
				width=2;
			}else if(num[i]=='0'){
				width=4;
			}else{
				width=3;
			}
			sumWidth+=width;
		}
		sumWidth+=numToNum;
		
		cout << sumWidth << "\n";
	}
	return 0;	
}