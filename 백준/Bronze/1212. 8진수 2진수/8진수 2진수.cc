#include <bits/stdc++.h>
using namespace std;

string converToBinary(int num){
	string binaryStr="";
	 
	while(num >0){      //몫이 0이 될 때까지 
		int remainder = num % 2;
		binaryStr = to_string(remainder) + binaryStr;
		num = num/2;
	}
	
	return binaryStr; 
}

int main(){
	// 1. 8진수 입력 받기 
	string octalStr;
	cin >> octalStr;
	
	// 2. string -> int로 
	if(octalStr == "0") cout << 0;
	else{
		string binaryStr="";
		for(char digit : octalStr){
			int num = digit-'0';
			string binaryDigit = converToBinary(num);
			
			while(binaryDigit.size()<3){
				binaryDigit = "0" + binaryDigit;
			}
			binaryStr +=binaryDigit;
		}
			
		int startIdx=0;
		while(binaryStr[startIdx]== '0'){
			startIdx++;
		}
		cout << binaryStr.substr(startIdx);
	} 
	
	return 0;
}